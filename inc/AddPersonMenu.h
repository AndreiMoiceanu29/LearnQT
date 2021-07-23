#ifndef H_ADD_PERSON_MENU
#define H_ADD_PERSON_MENU
#include "Person.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QLineEdit>
//#include "ListView.h"
#include <QVBoxLayout>
#include <QListWidgetItem>
class ListView;
class AddPersonMenu: public QWidget
{
	Q_OBJECT
	ListView* parent;
	QWidget *win;
	QLabel *headerLbl;
	QLabel *firstNameLbl;
	QLineEdit *firstNameTxt;
	QLabel *lastNameLbl;
	QLineEdit *lastNameTxt;
	QLabel *ageLbl;
	QLineEdit *ageTxt;
	QLabel *idLbl;
	QLineEdit *idTxt;
	QPushButton *addBtn;
	QVBoxLayout *vL;
	QHBoxLayout *hLNames;
	QHBoxLayout *hLNumbers;
	QWidget * firstList;
	QWidget * secondList;
	Person oldPerson;
	QListWidgetItem* oldItem;
	bool isUpdating;
public:
	void initializeComponents();
	void renderComponents();
	void initializeSignals();
	AddPersonMenu();
	AddPersonMenu(ListView*);
	
	~AddPersonMenu();
signals:
	void addPerson(Person& person);
	void updatePerson(Person& oldPerson, Person& newPerson);
	
};
#endif