#include "Service.h"

Service::Service(){}

Service::Service(Repository repo){ this->repo = repo; }
void Service::addPerson(Person& person){ this->repo.addPerson(person); }
Person Service::getPerson(int id){ this->repo.getPerson(id); }
void Service::deletePerson(int id){ this->repo.deletePerson(id); }
void Service::updatePerson(Person& oldPerson, Person& newPerson){ this->repo.updatePerson(oldPerson,newPerson);}
std::vector<Person> Service::getAllPersons(){return this->repo.getAllPersons(); }
Service::~Service(){}