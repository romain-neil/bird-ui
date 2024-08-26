//
// Created by Romain on 25/08/2024.
//

#ifndef BIRD_UI_COMMANDSERVICE_H
#define BIRD_UI_COMMANDSERVICE_H

#include <QString>

#include "SshService.h"

class CommandService {
	
	public:
		
		CommandService();
		~CommandService();
		
		QString Run(const QString& command) const;
	
	private:
		
		SshService* mp_ssh;

};


#endif //BIRD_UI_COMMANDSERVICE_H
