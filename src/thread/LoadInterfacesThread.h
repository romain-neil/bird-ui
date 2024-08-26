//
// Created by Romain on 26/08/2024.
//

#ifndef BIRD_UI_LOADINTERFACESTHREAD_H
#define BIRD_UI_LOADINTERFACESTHREAD_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>

#include "../models/Interface.h"
#include "../window/MainWindow.h"

class LoadInterfacesThread : public QThread {
	
	public:
		
		LoadInterfacesThread();
	
	protected:
		
		void run() override;
		
		QVector<Interface> GetInterfaces();
	
	private:
		
		QVector<Interface> m_interfaces;

};


#endif //BIRD_UI_LOADINTERFACESTHREAD_H
