#include "ListView.h"
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include "MainGUI.h"

ListView::ListView(){}

ListView::ListView(MainGUI* parent){
	this->parent = parent;
	
	this->initializeComponents();
	this->connectSignalsSlot();
	this->renderGUI();
}

void ListView::initializeComponents(){
	this->btnLayoutWidget = new QWidget{};
	
	this->mainLayout = new QHBoxLayout{this};
	this->buttonLayout = new QVBoxLayout{this->btnLayoutWidget};


	this->addPersonBtn = new QPushButton{"Add Person"};
	this->updatePersonBtn = new QPushButton{"Update Person"};
	this->deletePersonBtn = new QPushButton{"Delete Person"};

	this->personsList = new QListWidget{};
	this->addPersonMenu = new AddPersonMenu{this};
}

void ListView::renderGUI(){
	buttonLayout->addWidget(this->addPersonBtn);
	buttonLayout->addWidget(this->updatePersonBtn);
	buttonLayout->addWidget(this->deletePersonBtn);

	mainLayout->addWidget(this->personsList);
	mainLayout->addWidget(this->btnLayoutWidget);

}

void ListView::reloadList(std::vector<Person> persons){
	personsList->clear();
	
	for(auto person : persons){
		QString personFirstName = QString::fromStdString(person.getFirstName());
		QString personLastName = QString::fromStdString(person.getLastName());
		int age = person.getAge();
		int id = person.getId();
		QString personData;
		personData += personFirstName;
		personData += " ";
		personData += personLastName;
		personData += " ";
		personData += QString::number(age);
		personData += " ";
		personData += QString::number(id);		
		QListWidgetItem *item = new QListWidgetItem(personData);
		personsList->addItem(item);
	}
}


void ListView::connectSignalsSlot(){
	QObject::connect(addPersonBtn, &QPushButton::clicked, this, [&](){
		this->addPersonMenu->show();
		emit addPerson();
	});
	QObject::connect(parent,&MainGUI::updatedRepo,this, [&](std::vector<Person> persons){
		this->reloadList(persons);
	});
	QObject::connect(updatePersonBtn,&QPushButton::clicked,this,[&](){
		if(this->personsList->selectedItems().size() > 0){
			QString personData = this->personsList->selectedItems().at(0)->text();
			QStringList dataStr = personData.split(" ");
			int id = dataStr[3].toInt();
			int age = dataStr[2].toInt();
			std::string firstName = dataStr[0].toStdString();
			std::string lastName = dataStr[1].toStdString();
			Person person(firstName,lastName,age,id);
			this->addPersonMenu->show();
			emit updatePerson(person);

		}else{
			QMessageBox box;
			box.setText("No person selected\n Please select a person.");
			box.exec();
		}
	});
	QObject::connect(deletePersonBtn,&QPushButton::clicked,this,[&](){
		if(this->personsList->selectedItems().size() > 0){
			QString personData = this->personsList->selectedItems().at(0)->text();
			QStringList dataStr = personData.split(" ");
			int id = dataStr[3].toInt();
			
			
			emit deletePerson(id);
		}else{
			QMessageBox box;
			box.setText("No person selected\n Please select a person.");
			box.exec();
		}
	});
	// QObject::connect(addPersonMenu, &AddPersonMenu::close, this, [&](){
	// 	this->reloadList();
	// });
	
	// QObject::connect(updatePersonBtn, &QPushButton::clicked, this, [&](){
	// 	if(this->personsList->selectedItems().size() > 0){

	// 		this->addPersonMenu = new AddPersonMenu(this->personsList->selectedItems().at(0),this->service,true);
	// 		this->addPersonMenu->show();
	// 	}
	// 	else{
	// 		QErrorMessage *error = new QErrorMessage();
	// 		error->showMessage("No person selected !");
	// 	}

	// });
	// QObject::connect(deletePersonBtn,&QPushButton::clicked, this, [&](){
	// 	if(this->personsList->selectedItems().size() > 0){
	// 		QString personData = this->personsList->selectedItems().at(0)->text();
	// 		QStringList dataStr = personData.split(" ");
	// 		int id = dataStr[3].toInt();
	// 		this->service.deletePerson(id);
	// 		this->reloadList();
	// 	}
	// });
}

AddPersonMenu* ListView::getAddPersonMenuInstance(){ return this->addPersonMenu; }

ListView::~ListView(){}

