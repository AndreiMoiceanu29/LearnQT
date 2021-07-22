#ifndef H_REPO
#define H_REPO
#include "Person.h"
#include <vector>
class Repository
{
	std::vector<Person> database;
public:
	Repository();
	void addPerson(Person&);
	Person getPerson(int);
	Person updatePerson(Person&,Person&);
	Person deletePerson(int);
	std::vector<Person> getAllPersons();
	~Repository();
	
};
#endif