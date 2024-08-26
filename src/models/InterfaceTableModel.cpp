//
// Created by Romain on 24/08/2024.
//

#include "InterfaceTableModel.h"

InterfaceTableModel::InterfaceTableModel(QObject *parent) : QAbstractTableModel(parent) {}

QVariant InterfaceTableModel::data(const QModelIndex &index, int role) const {
	if (!index.isValid() || role != Qt::DisplayRole) {
		return {};
	}
	
	const auto i = m_rows.at(index.row());
	
	switch (index.column()) {
		case 0:
			return i.name;
		case 1:
			return i.type;
		case 2:
			return i.mtu;
//		case 3:
//			return i.tx;
//		case 4:
//			return i.rx;
		default:
			return {};
	}
}

QVariant InterfaceTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role != Qt::DisplayRole) {
		return {};
	}
	
	if (orientation != Qt::Horizontal) {
		return {};
	}
	
	switch (section) {
		case 0:
			return "Name";
		case 1:
			return "Type";
		case 2:
			return "MTU";
//		case 3:
//			return "Tx";
//		case 4:
//			return "Rx";
		default:
			return {};
	}
}

Qt::ItemFlags InterfaceTableModel::flags(const QModelIndex &index) const {
	if (!index.isValid()) {
		return Qt::NoItemFlags;
	}
	
	return Qt::ItemIsEnabled;
}

void InterfaceTableModel::addRows(const QVector<Interface> &rows) {
	if (rows.isEmpty()) {
		return;
	}
	
	const auto rowCount = static_cast<int>(m_rows.size());
	beginInsertRows(QModelIndex(), rowCount, rowCount + static_cast<int>(rows.size()));
	
	m_rows.append(rows);
	
	endInsertRows();
}
