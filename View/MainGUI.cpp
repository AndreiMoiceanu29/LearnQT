#include "MainGUI.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
MainGUI::MainGUI() {
	this->initializeComponents();
	this->renderGUI();
}

MainGUI::MainGUI(Service service) {
	this->service = service;

	this->initializeComponents();
	this->connectSignals();
	this->renderGUI();
}

void MainGUI::initializeComponents(){
	this->header = new AppHeader{};
	this->listView = new ListView{this};
	this->mainLayout = new QVBoxLayout{this};
}

void MainGUI::renderGUI(){
	mainLayout->addWidget(this->header);
	mainLayout->addWidget(this->listView);
	
}

void MainGUI::connectSignals(){
	QObject::connect(this->listView->getAddPersonMenuInstance(), &AddPersonMenu::addPerson, this, [&](Person& person){
		this->service.addPerson(person);
		std::vector<Person> persons = this->service.getAllPersons();
		emit updatedRepo(persons);
	});
	QObject::connect(this->listView->getAddPersonMenuInstance(), &AddPersonMenu::updatePerson,this,[&](Person& oldPerson, Person& newPerson){
		this->service.updatePerson(oldPerson,newPerson);
		std::vector<Person> persons = this->service.getAllPersons();
		emit updatedRepo(persons);
	});
	QObject::connect(this->listView,&ListView::deletePerson,this,[&](int id){
		this->service.deletePerson(id);
		std::vector<Person> persons = this->service.getAllPersons();
		emit updatedRepo(persons);
	});
}

MainGUI::~MainGUI(){}