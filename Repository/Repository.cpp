#include "Repository.h"

Repository::Repository(){}

void Repository::addPerson(Person& person){
	this->database.push_back(person);
}

Person Repository::getPerson(int id){
	Person nullPerson;
	for(auto person : this->database){
		if(person.getId() == id){
			return person;
		}
	}
	return nullPerson;
}

Person Repository::updatePerson(Person& oldPerson, Person& newPerson){
	for(int i=0; i<this->database.size();i++){
		if(database[i].getId() == oldPerson.getId()){
			database[i] = newPerson;
		}
	}
	return oldPerson;
}

Person Repository::deletePerson(int id){
	Person deletedPerson;
	for(int i=0; i < this->database.size();i++){
		if(this->database[i].getId() == id){
			deletedPerson = this->database[i];
			this->database.erase(this->database.begin() + i);
		}
	}
	return deletedPerson;
}

std::vector<Person> Repository::getAllPersons(){
	return this->database;
}

Repository::~Repository(){}