//
// Created by Romain Neil on 17/08/2024.
//

#include "BirdConfigService.h"

BirdConfigService::BirdConfigService() {
	m_path = QString();
	//m_objects =
}

void BirdConfigService::SetConfigPath(const QString &path) {
	this->m_path = path;
}

void BirdConfigService::Parse() const {
	if (this->m_path.isEmpty()) {
		return;
	}

	//
}

void BirdConfigService::Apply() {
	if (this->m_path.isEmpty()) {
		return;
	}

	//Write config file to bird location
}

void BirdConfigService::LoadConfig() {

}

void BirdConfigService::SaveConfig() {

}


