#ifndef H_APP_WINDOW
#define H_APP_WINDOW
#include <QMainWindow>
#include <QWidget>

#include "AppHeader.h"
#include "ListView.h"
#include "Service.h"

class MainGUI : public QWidget
{
	Service service;
	QVBoxLayout *mainLayout;
	AppHeader* header;
	ListView* listView;

public:
	MainGUI();
	MainGUI(Service);
	void initializeComponents();
	void renderGUI();
	~MainGUI();
	
};
#endif