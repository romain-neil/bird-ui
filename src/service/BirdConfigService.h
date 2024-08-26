//
// Created by Romain Neil on 17/08/2024.
//

#ifndef BIRDCONFIGSERVICE_H
#define BIRDCONFIGSERVICE_H

#include <QFile>
#include <QString>
#include <QVector>

#include "../Object/AbstractBirdObject.h"

class AbstractBirdObject;

class BirdConfigService final {

	public:
		BirdConfigService();

		void SetConfigPath(const QString &path);

		void Parse() const;

		void Apply();

		void LoadConfig();
		
		void SaveConfig();

	private:

		QString m_path;

		QVector<AbstractBirdObject*> m_objects;

};


#endif //BIRDCONFIGSERVICE_H
