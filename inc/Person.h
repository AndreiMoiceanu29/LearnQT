#ifndef H_PERSON
#define H_PERSON
#include <string>
class Person
{
private:
	int id;
	int age;
	std::string firstName;
	std::string lastName;
public:
	Person();
	Person(std::string,std::string,int,int);
	int getId();
	void setId(int);
	int getAge();
	void setAge(int);
	std::string getFirstName();
	void setFirstName(std::string);
	std::string getLastName();
	void setLastName(std::string);
	~Person();
	
};
#endif