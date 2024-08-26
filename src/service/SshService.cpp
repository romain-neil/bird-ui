//
// Created by Romain Neil on 18/08/2024.
//

#include "SshService.h"

SshService::SshService(
		const QString &username,
		const QString &password,
		const QString &host,
		const int port,
		bool trustUnknownHost
) : m_trust(trustUnknownHost) {
	m_ssh = ssh_new();
	
	if (m_ssh == NULL) {
		exit(-1);
	}
	
	if (!username.isEmpty()) {
		ssh_options_set(m_ssh, SSH_OPTIONS_USER, username.toStdString().c_str());
	}
	
	ssh_options_set(m_ssh, SSH_OPTIONS_HOST, host.toStdString().c_str());
	ssh_options_set(m_ssh, SSH_OPTIONS_PORT, &port);
	
	int rc = ssh_connect(m_ssh);
	if (rc != SSH_OK) {
		fprintf(stderr, "ssh_connect() failed: %s\n", ssh_get_error(m_ssh));
	}
	
	m_isAuth = false;
	m_isInit = false;
	m_channel = nullptr;
}

SshService::~SshService() {
	ssh_disconnect(m_ssh);
	ssh_free(m_ssh);
}

void SshService::Authenticate() {
	unsigned char *hash;
	ssh_key key;
	std::size_t hlen;
	
	int rc = ssh_get_server_publickey(m_ssh, &key);
	if (rc < 0) {
		return;
	}
	
	rc = ssh_get_publickey_hash(key, SSH_PUBLICKEY_HASH_SHA1, &hash, &hlen);
	ssh_key_free(key);
	if (rc < 0) {
		return;
	}
	
	switch (ssh_session_is_known_server(m_ssh)) {
		case SSH_KNOWN_HOSTS_OK:
			break;
		case SSH_KNOWN_HOSTS_CHANGED:
			//
			return;
		case SSH_KNOWN_HOSTS_OTHER:
			ssh_clean_pubkey_hash(&hash);
			return;
		case SSH_KNOWN_HOSTS_NOT_FOUND:
		case SSH_KNOWN_HOSTS_UNKNOWN:
			if (this->m_trust) {
				HandleUnknownHost(hash, hlen);
			}
			break;
		case SSH_KNOWN_HOSTS_ERROR:
			return;
	}
	
	ssh_clean_pubkey_hash(&hash);
	m_isAuth = true;
}

void SshService::HandleUnknownHost(unsigned char* hash, size_t hlen) const {
	char *hexa = ssh_get_hexa(hash, hlen);
	
	ssh_string_free_char(hexa);
	ssh_clean_pubkey_hash(&hash);
	
	if (ssh_session_update_known_hosts(m_ssh) < 0) {
		qInfo("Unable to update known hosts : %s\n", ssh_get_error(m_ssh));
	}
}

void SshService::Init() {
	if (!m_isAuth) {
		Authenticate();
		
		//Authentication goes wrong
		if (!m_isAuth) {
			return;
		}
	}
	
	m_channel = ssh_channel_new(m_ssh);
	if (m_channel == NULL) {
		return;
	}
	
	if (ssh_channel_open_session(m_channel) != SSH_OK) {
		ssh_channel_free(m_channel);
		return;
	}
	
	m_isInit = true;
}


QString SshService::RunCMD(const QString &cmd, const bool read) {
	if (!m_isInit) {
		Init();
	}
	
	if (const int rc = ssh_channel_request_exec(m_channel, cmd.toStdString().c_str()); rc != SSH_OK) {
		ssh_channel_close(m_channel);
		ssh_channel_free(m_channel);
		
		return {};
	}
	
	if (!read) {
		return {};
	}
	
	QByteArray response;
	char buffer[256];
	int len;
	while ((len = ssh_channel_read(m_channel, buffer, sizeof(buffer), NULL)) > 0) {
		response.append(buffer, len);
	}
	
	ssh_channel_send_eof(m_channel);
	ssh_channel_close(m_channel);
	ssh_channel_free(m_channel);
	
	return QString::fromUtf8(response);
}
