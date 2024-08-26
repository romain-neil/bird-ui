//
// Created by Romain Neil on 17/08/2024.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QWidget>
#include <QMainWindow>
#include <QScopedPointer>

#include "../service/BirdConfigService.h"
#include "../service/CommandService.h"

#include "BgpPeersWindow.h"
#include "RouteWindow.h"

class QMenu;

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:

        MainWindow();
		~MainWindow() override;
		
		static MainWindow * s_self;
		
		CommandService *getCommandService() {
			return mp_commandService;
		}
	
	public slots:
		
		void mShowInterfacesList();
		
		void mShowStaticRoutingWindow();
	
		void mShowBgpPeersWindow();

    private:
		
		void createActions();
		void deleteActions();
		
		void createMenus();
		
        BirdConfigService m_birdConfigService;
		
		CommandService *mp_commandService;
		
		QAction *actInterfacesList;
		
		QAction *actStaticRoutes;
		QAction *actBgpPeers;
		
		QAction *actAboutQt;
		
		QMenu *menuInterfaces{};
		QMenu *menuRouting{};
		QMenu *menuAbout{};
		
		//Windows
		
		BgpPeersWindow *mp_bgpPeersWindow;
		RouteWindow *mp_routeWindow;

};



#endif //MAINWINDOW_H
