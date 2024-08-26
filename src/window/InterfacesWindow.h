//
// Created by Romain on 25/08/2024.
//

#ifndef BIRD_UI_INTERFACESWINDOW_H
#define BIRD_UI_INTERFACESWINDOW_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMainWindow>
#include <QString>
#include <QTableView>
#include <QVector>
#include <QWidget>

#include "../models/InterfaceTableModel.h"
#include "../thread/LoadInterfacesThread.h"

class InterfacesWindow : public QMainWindow {

	public:
		
		explicit InterfacesWindow(QWidget *parent = nullptr);
		~InterfacesWindow() override;
		
	public slots:
		
		void mLoadData();
		
	private:
		
		LoadInterfacesThread *loadInterfacesThread;
		
		InterfaceTableModel *model;
		
		QTableView *table;
		
		QWidget *widget;
		
};


#endif //BIRD_UI_INTERFACESWINDOW_H
