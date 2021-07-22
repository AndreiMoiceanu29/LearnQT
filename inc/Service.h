#ifndef H_SERVICE
#define H_SERVICE
#include "Repository.h"

class Service
{
private:
	Repository repo;
public:
	Service();
	Service(Repository);
	void addPerson(Person&);
	Person getPerson(int);
	void deletePerson(int);
	void updatePerson(Person&,Person&);
	std::vector<Person> getAllPersons();
	~Service();
	
};
#endif