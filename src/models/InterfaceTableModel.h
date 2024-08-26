//
// Created by Romain on 24/08/2024.
//

#ifndef BIRD_UI_INTERFACETABLEMODEL_H
#define BIRD_UI_INTERFACETABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>

#include "Interface.h"

class InterfaceTableModel : public QAbstractTableModel {
	
	Q_OBJECT
	
	public:
		
		explicit InterfaceTableModel(QObject *parent = nullptr);
	
		[[nodiscard]] int rowCount(const QModelIndex &) const override {
			return static_cast<int>(m_rows.size());
		}
		
		[[nodiscard]] int columnCount(const QModelIndex &) const override {
			return 3;
		}
		
		[[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
		
		[[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
		
		[[nodiscard]] Qt::ItemFlags flags(const QModelIndex &index) const override;
		
		void addRows(const QVector<Interface> &rows);
		
	private:
		
		QVector<Interface> m_rows;
		
};


#endif //BIRD_UI_INTERFACETABLEMODEL_H
