//
// Created by Romain on 23/08/2024.
//

#ifndef BIRD_UI_ROUTETABLEMODEL_H
#define BIRD_UI_ROUTETABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>

class QAction;

/**
 * Represent a route line view, in a table.
 * A route can be coming from different sources:
 * - static (S)
 * - dynamic : BGP, ...
 */
class RouteTableModel : public QAbstractTableModel {
	
	enum RouteType {
		STATIC = 1,
		BGP
	};
	
	struct Route {
		RouteType type;
		QString destIP;
		QString gateway;
		int metric;
	};
	
	Q_OBJECT
	
	public:
		
		explicit RouteTableModel(QObject *parent = nullptr);
		
		[[nodiscard]] int rowCount(const QModelIndex &) const override {
			return static_cast<int>(m_rows.size());
		}
		
		[[nodiscard]] int columnCount(const QModelIndex &) const override {
			return 4;
		}
		
		[[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
		
		[[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
		
		[[nodiscard]] Qt::ItemFlags flags(const QModelIndex &index) const override;
		
	private:
		
		QVector<Route> m_rows;

};


#endif //BIRD_UI_ROUTETABLEMODEL_H
