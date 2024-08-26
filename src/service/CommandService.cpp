//
// Created by Romain on 25/08/2024.
//

#include "CommandService.h"

CommandService::CommandService() {
	mp_ssh = new SshService();
	mp_ssh->Init();
}

CommandService::~CommandService() {
	delete mp_ssh;
}

QString CommandService::Run(const QString &command) const {
	return mp_ssh->RunCMD(command, false);
}
