//
// Created by Romain on 23/08/2024.
//

#include "RouteWindow.h"

RouteWindow::RouteWindow(QWidget *parent) : QMainWindow(parent) {
	mp_model = new RouteTableModel(this);
	mp_table = new QTableView(this);
	mp_table->setModel(mp_model);
}