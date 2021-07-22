#include "AppHeader.h"

AppHeader::AppHeader(){
	this->headerTxt = new QLabel{"Welcome"};
	this->mainLayout = new QHBoxLayout{this};
	this->mainLayout->addWidget(headerTxt);
}

AppHeader::~AppHeader(){}