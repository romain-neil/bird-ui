//
// Created by Romain Neil on 18/08/2024.
//

#ifndef ABSTRACTBIRDOBJECT_H
#define ABSTRACTBIRDOBJECT_H

#include <QString>

class AbstractBirdObject {

	public:

		virtual ~AbstractBirdObject() = default;

		virtual QString GetConfig() = 0;

};

#endif //ABSTRACTBIRDOBJECT_H
