//
// Created by Romain Neil on 27/08/2024.
//

#ifndef ROUTE_H
#define ROUTE_H

#include <QString>

struct RouteGateway {
	bool isInterfaces;
};

struct Route {
	QString destination;
	int metric;

	RouteGateway gateway;
};

#endif //ROUTE_H
