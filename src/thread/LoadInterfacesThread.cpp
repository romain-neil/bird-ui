//
// Created by Romain on 26/08/2024.
//

#include "LoadInterfacesThread.h"

LoadInterfacesThread::LoadInterfacesThread() {
	m_interfaces = QVector<Interface>();
}

void LoadInterfacesThread::run() {
	m_interfaces.empty();
	
	auto cmd = MainWindow::s_self->getCommandService();
	QString interfacesList = cmd->Run("ip -json link show");
	
	QJsonDocument doc = QJsonDocument::fromJson(interfacesList.toUtf8());
	if (doc.isNull() || !doc.isArray()) {
		return;
	}
	
	//Parse interfaces list
	QJsonArray arr = doc.array();
	for (auto && i : arr) {
		QJsonObject obj = i.toObject();
		
		Interface itf = {
				obj["ifname"].toString(),
				obj["link_type"].toString(),
				obj["mtu"].toInt()
		};
		m_interfaces.append(itf);
	}
}

QVector<Interface> LoadInterfacesThread::GetInterfaces() {
	return m_interfaces;
}
