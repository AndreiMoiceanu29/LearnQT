#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "AddPersonMenu.h"
#include <QVBoxLayout>
#include <QObject>
#include <QStringList>
#include <QStringList>

AddPersonMenu::AddPersonMenu(){
	this->initializeComponents();
	this->renderComponents();
	this->initializeSignals();
	
}

AddPersonMenu::AddPersonMenu(Service& service){
	this->service = service;
	this->isUpdating = false;
	this->initializeComponents();
	this->renderComponents();
	this->initializeSignals();
}

AddPersonMenu::AddPersonMenu(QListWidgetItem* item, Service& service,bool isUpdating){
	this->service = service;
	this->oldItem = item;
	this->isUpdating = isUpdating;
	this->initializeComponents();
	this->renderComponents();
	this->initializeSignals();

}

void AddPersonMenu::initializeComponents(){
	this->win = new QWidget();
	this->headerLbl = new QLabel("Add Person");
	this->firstNameLbl = new QLabel("First Name:");
	this->lastNameLbl = new QLabel("Last Name:");
	this->ageLbl = new QLabel("Age:");
	this->idLbl = new QLabel("Id:");
	this->firstNameTxt = new QLineEdit();
	this->lastNameTxt = new QLineEdit();
	this->ageTxt = new QLineEdit();
	this->idTxt = new QLineEdit();
	this->addBtn = new QPushButton("Add");
}

void AddPersonMenu::renderComponents(){
	QVBoxLayout *vL = new QVBoxLayout();
	vL->addWidget(win);
	QHBoxLayout *hLNames = new QHBoxLayout();
	QHBoxLayout *hLNumbers = new QHBoxLayout();
	QWidget *firstList = new QWidget();
	QWidget *secondList = new QWidget();
	hLNames->addWidget(firstNameLbl);
	hLNames->addWidget(firstNameTxt);
	hLNames->addWidget(lastNameLbl);
	hLNames->addWidget(lastNameTxt);
	hLNumbers->addWidget(ageLbl);
	hLNames->addWidget(ageTxt);
	hLNames->addWidget(idLbl);
	hLNames->addWidget(idTxt);
	firstList->setLayout(hLNames);
	secondList->setLayout(hLNumbers);
	vL->addWidget(firstList);
	vL->addWidget(secondList);
	vL->addWidget(addBtn);
}

void AddPersonMenu::initializeSignals(){
	QObject::connect(addBtn,&QPushButton::clicked, this, [&](){
		std::string firstName = this->firstNameTxt->text().toStdString();
		std::string lastName = this->lastNameTxt->text().toStdString();
		int age = stoi(this->ageTxt->text().toStdString());
		int id = stoi(this->idTxt->text().toStdString());
		Person person(firstName,lastName,age,id);
		if(isUpdating){
			QString personData = this->oldItem->text();
			QStringList strList= personData.split(" ");
			Person oldPerson(strList[0].toStdString(),strList[1].toStdString(),strList[2].toInt(),strList[3].toInt());
			this->service.updatePerson(oldPerson,person);
		}else
			this->service.addPerson(person);
		this->close();
	});
}

AddPersonMenu::~AddPersonMenu(){}