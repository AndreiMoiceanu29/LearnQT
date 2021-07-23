#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "AddPersonMenu.h"
#include <QVBoxLayout>
#include <QObject>
#include <QStringList>
#include <QStringList>
#include "ListView.h"

AddPersonMenu::AddPersonMenu(){
	this->initializeComponents();
	this->renderComponents();
	this->initializeSignals();
	
}

AddPersonMenu::AddPersonMenu(ListView* parent){
	this->parent = parent;

	this->initializeComponents();
	this->renderComponents();
	this->initializeSignals();
}



void AddPersonMenu::initializeComponents(){
	this->win = new QWidget{};
	this->headerLbl = new QLabel{"Add Person"};
	this->firstNameLbl = new QLabel{"First Name:"};
	this->lastNameLbl = new QLabel{"Last Name:"};
	this->ageLbl = new QLabel{"Age:"};
	this->idLbl = new QLabel{"Id:"};
	this->firstNameTxt = new QLineEdit();
	this->lastNameTxt = new QLineEdit();
	this->ageTxt = new QLineEdit();
	this->idTxt = new QLineEdit();
	this->addBtn = new QPushButton{"Add"};
	this->vL = new QVBoxLayout{this};
	this->hLNames = new QHBoxLayout();
	this->hLNumbers = new QHBoxLayout();
	this->firstList = new QWidget();
	this->secondList = new QWidget();
}

void AddPersonMenu::renderComponents(){
 
	vL->addWidget(win);
	
	hLNames->addWidget(firstNameLbl);
	hLNames->addWidget(firstNameTxt);
	hLNames->addWidget(lastNameLbl);
	hLNames->addWidget(lastNameTxt);
	hLNumbers->addWidget(ageLbl);
	hLNumbers->addWidget(ageTxt);
	hLNumbers->addWidget(idLbl);
	hLNumbers->addWidget(idTxt);
	firstList->setLayout(hLNames);
	secondList->setLayout(hLNumbers);
	vL->addWidget(firstList);
	vL->addWidget(secondList);
	vL->addWidget(addBtn);
}

void AddPersonMenu::initializeSignals(){
	// QObject::connect(addBtn,&QPushButton::clicked, this, [&](){
		// std::string firstName = this->firstNameTxt->text().toStdString();
		// std::string lastName = this->lastNameTxt->text().toStdString();
		// int age = stoi(this->ageTxt->text().toStdString());
		// int id = stoi(this->idTxt->text().toStdString());
		// Person person(firstName,lastName,age,id);
	// 	if(isUpdating){
			// QString personData = this->oldItem->text();
			// QStringList strList= personData.split(" ");
			// Person oldPerson(strList[0].toStdString(),strList[1].toStdString(),strList[2].toInt(),strList[3].toInt());
			// this->service.updatePerson(oldPerson,person);
	// 	}else
	// 		this->service.addPerson(person);
	// 	this->close();
	// });
	QObject::connect(parent, &ListView::addPerson,this,[&](){
		this->isUpdating = false;
	});
	QObject::connect(parent, &ListView::updatePerson,this,[&](Person oldPerson){
		this->isUpdating = true;
		this->oldPerson = oldPerson;	
	});
	QObject::connect(addBtn, &QPushButton::clicked, this, [&](){
		std::string firstName = this->firstNameTxt->text().toStdString();
		std::string lastName = this->lastNameTxt->text().toStdString();
		int age = stoi(this->ageTxt->text().toStdString());
		int id = stoi(this->idTxt->text().toStdString());
		Person person(firstName,lastName,age,id);
		if(this->isUpdating){
			emit updatePerson(oldPerson,person);
		}else{
			
			emit addPerson(person);
		}
		this->close();
	});
}

AddPersonMenu::~AddPersonMenu(){}