//
// Created by Romain on 25/08/2024.
//

#ifndef BIRD_UI_BGPPEERWINDOW_H
#define BIRD_UI_BGPPEERWINDOW_H

#include <QMainWindow>
#include <QTextStream>

#include "../ui/ui_bgpPeerUI.h"

/**
 * Show a bgp peer window
 */
class BgpPeerWindow : public QMainWindow {
	
	public:
		
		explicit BgpPeerWindow(QWidget *parent = nullptr);
		~BgpPeerWindow() override;
		
	public slots:
		
		void mSaveConfig();
		
	private:
		
		QString *getPeer();
		
		static QString nl() {
			return "\n";
		}
		
		Ui::BgpPeerWindow *ui;

};


#endif //BIRD_UI_BGPPEERWINDOW_H
