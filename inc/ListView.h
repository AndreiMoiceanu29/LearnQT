#ifndef H_LIST_VIEW
#define H_LIST_VIEW

#include <QListWidget>

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QHBoxLayout>
#include "Service.h"
#include "AddPersonMenu.h"

class ListView: public QWidget
{
private:
	QHBoxLayout *mainLayout;
	QVBoxLayout *buttonLayout;

	Service service;

	QWidget* btnLayoutWidget;
	QListWidget *personsList;

	QPushButton *addPersonBtn;
	QPushButton *updatePersonBtn;
	QPushButton *deletePersonBtn;
	
	AddPersonMenu* addPersonMenu;
public:
	ListView();
	ListView(Service);
	~ListView();
	void initializeComponents();
	void renderGUI();
	void reloadList();
	void connectSignalsSlot();
};
#endif