//
// Created by Romain on 25/08/2024.
//

#include "InterfacesWindow.h"
#include "MainWindow.h"

InterfacesWindow::InterfacesWindow(QWidget *parent) : QMainWindow(parent) {
	widget = new QWidget(this);
	
	model = new InterfaceTableModel(this);
	table = new QTableView(widget);
	
	table->setModel(model);
	
	setCentralWidget(widget);
	setWindowTitle("Interfaces list");
	
	loadInterfacesThread = new LoadInterfacesThread();
	connect(
			loadInterfacesThread,
			&LoadInterfacesThread::finished,
			this,
			&InterfacesWindow::mLoadData
			);
	loadInterfacesThread->start();
}

InterfacesWindow::~InterfacesWindow() {
	delete model;
	delete table;
}

void InterfacesWindow::mLoadData() {

}
