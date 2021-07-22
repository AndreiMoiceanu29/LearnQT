#ifndef H_ADD_PERSON_MENU
#define H_ADD_PERSON_MENU
#include "Person.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "Service.h"
#include <QVBoxLayout>
#include <QListWidgetItem>
class AddPersonMenu: public QWidget
{
	Service service;
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

	QListWidgetItem* oldItem;
	bool isUpdating;
public:
	void initializeComponents();
	void renderComponents();
	void initializeSignals();
	AddPersonMenu();
	AddPersonMenu(Service&);
	AddPersonMenu(QListWidgetItem*, Service&,bool);
	~AddPersonMenu();
	
};
#endif