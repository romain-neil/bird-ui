//
// Created by Romain on 23/08/2024.
//

#ifndef BIRD_UI_ROUTEWINDOW_H
#define BIRD_UI_ROUTEWINDOW_H


#include <QMainWindow>
#include <QTableView>

#include "../models/RouteTableModel.h"

class RouteWindow final : public QMainWindow {

	Q_OBJECT
	
	public:
		
		explicit RouteWindow(QWidget *parent = nullptr);
	
	private:
		
		RouteTableModel *mp_model;
		
		QTableView *mp_table;
		
};


#endif //BIRD_UI_ROUTEWINDOW_H
