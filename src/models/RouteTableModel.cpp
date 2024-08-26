//
// Created by Romain on 23/08/2024.
//

#include "RouteTableModel.h"

RouteTableModel::RouteTableModel(QObject *parent) : QAbstractTableModel(parent) {}

QVariant RouteTableModel::data(const QModelIndex &index, int role) const {
	if (!index.isValid() || role != Qt::DisplayRole) {
		return {};
	}
	
	const Route &route = m_rows.at(index.row());
	
	switch (index.column()) {
		case 0:
			switch (route.type) {
				case STATIC:
					return "S";
				case BGP:
					return "BGP";
				default:
					return {};
			}
		case 1:
			return route.destIP;
		case 2:
			return route.gateway;
		case 3:
			return route.metric;
		default:
			return {};
	}
}

QVariant RouteTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role != Qt::DisplayRole) {
		return {};
	}
	
	if (orientation == Qt::Horizontal) {
		switch (section) {
			case 0:
				return ""; //Type de route
			case 1:
				return tr("Destination address");
			case 2:
				return tr("Gateway");
			case 3:
				return tr("Metric");
			default:
				return {};
		}
	}
	
	return {};
}

Qt::ItemFlags RouteTableModel::flags(const QModelIndex &index) const {
	if (!index.isValid()) {
		return Qt::NoItemFlags;
	}
	
	return Qt::ItemIsEnabled;
}
