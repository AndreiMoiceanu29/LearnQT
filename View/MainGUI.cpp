#include "MainGUI.h"
#include <QVBoxLayout>
#include <QPushButton>

MainGUI::MainGUI() {
	this->initializeComponents();
	this->renderGUI();
}

MainGUI::MainGUI(Service service) {
	this->service = service;

	this->initializeComponents();
	this->renderGUI();
}

void MainGUI::initializeComponents(){
	this->header = new AppHeader{};
	this->listView = new ListView{service};
	this->mainLayout = new QVBoxLayout{this};
}

void MainGUI::renderGUI(){
	mainLayout->addWidget(this->header);
	mainLayout->addWidget(this->listView);
	
}

MainGUI::~MainGUI(){}