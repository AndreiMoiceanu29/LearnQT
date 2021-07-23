#ifndef H_LIST_VIEW
#define H_LIST_VIEW

#include <QListWidget>

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QHBoxLayout>
//#include "MainGUI.h"
#include <QObject>
#include "AddPersonMenu.h"
class MainGUI;
class ListView: public QWidget
{
private:
	Q_OBJECT
	QHBoxLayout *mainLayout;
	QVBoxLayout *buttonLayout;

	MainGUI* parent;

	QWidget* btnLayoutWidget;
	QListWidget *personsList;

	QPushButton *addPersonBtn;
	QPushButton *updatePersonBtn;
	QPushButton *deletePersonBtn;
	
	AddPersonMenu* addPersonMenu;
public:
	ListView();
	ListView(MainGUI*);
	~ListView();
	void initializeComponents();
	void renderGUI();
	void reloadList(std::vector<Person>);
	void connectSignalsSlot();
	AddPersonMenu* getAddPersonMenuInstance();

signals:
	void addPerson();
	void updatePerson(Person person);
	void deletePerson(int id);
};
#endif