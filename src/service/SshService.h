//
// Created by Romain Neil on 18/08/2024.
//

#ifndef SSHSERVICE_H
#define SSHSERVICE_H

#include <iostream>
#include <QString>

#include <libssh/libssh.h>

/**
 * SSH helper
 * @since 0.1.0
 * @author Romain Neil
 */
class SshService {
	
	public:
		
		explicit SshService(
				const QString & username = QString(""),
				const QString & password = QString(""),
				const QString & host = QString("127.0.0.1"),
				int port = 22,
				bool trustUnknownHost = false
		);
		
		~SshService();
		
		/**
		 * Explicitly initialize SSH channel.
		 * If the function are not directly called, she will be called the first time we try to run a command
		 */
		void Init();
		
		/**
		 * Run the specified command via ssh
		 *
		 * @param cmd The command to run
		 * @param read Specify if we have to read command output
		 * @param output The command output, if any
		 */
		QString RunCMD(const QString & cmd, bool read);
	
	private:
		
		void Authenticate();
		
		void HandleUnknownHost(unsigned char* hash, size_t hlen) const;
		
		bool m_isAuth;
		bool m_isInit;
		bool m_trust;
		
		ssh_channel m_channel;
		
		ssh_session m_ssh;
	
};



#endif //SSHSERVICE_H
