//
// Created by Romain on 25/08/2024.
//

#include "BgpPeerWindow.h"

BgpPeerWindow::BgpPeerWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::BgpPeerWindow) {
	ui->setupUi(this);
	
	connect(ui->saveBtn, &QPushButton::clicked, this, &BgpPeerWindow::mSaveConfig);
}

BgpPeerWindow::~BgpPeerWindow() {
	delete ui;
}

QString *BgpPeerWindow::getPeer() {
	QTextStream ts;
	
	ts << "protocol bgp " << ui->peerName->text() << " {" << nl()
		<< "interface \"" << "{}" << "\";" << nl() //Interface name
		<< "local port " << ";" << nl() //Local port
		<< "neighbor port " << ";" << nl();
	
	auto peer = ui->peerAddress->text();
	ts << "neighbor " << peer << nl();
	
	if (ui->cbMultihop->isChecked()) {
		ts << "multihop " << ui->multihop->text() << ";" << nl();
	}
	
	if (ui->cbPassword->isChecked()) {
		ts << "password \"" << ui->password->text() << "\";" << nl();
	}
	
	//Terminate config file
	ts << "}";
	
	return ts.string();
}

void BgpPeerWindow::mSaveConfig() {
	//
}
