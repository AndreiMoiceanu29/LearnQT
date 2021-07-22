#include "Person.h"

Person::Person(){

}

Person::Person(std::string firstName, std::string lastName, int age, int id){
	this->id = id;
	this->age = age;
	this->firstName = firstName;
	this->lastName = lastName;
}

int Person::getId(){ return this->id; }
void Person::setId(int id){ this->id = id; }

int Person::getAge(){ return this->age; }
void Person::setAge(int age){ this->age = age; }

std::string Person::getFirstName(){ return this->firstName; }
void Person::setFirstName(std::string firstName){ this->firstName = firstName; }

std::string Person::getLastName(){ return this->lastName; }
void Person::setLastName(std::string lastName){ this->lastName = lastName; }

Person::~Person(){}