#include "Model.h"

Student::Student() {
	
}

Student::Student(int id, std::string name, Date birthday, std::string address) {
	Student::id = id;
	Student::name = name;
	Student::birthDay = birthday;
	Student::address = address;

}

void Student::setId(int id)
{
	Student::id = id;
}

void Student::setName(std::string name)
{
	Student::name = name;
}

void Student::setBirthday(Date birthday)
{
	Student::birthDay = birthday;
}

void Student::setAddress(std::string address)
{
	Student::address = address;
}

int Student::getId()
{
	return id;
}

std::string Student::getName()
{
	return name;
}

Date Student::getBirthday()
{
	return birthDay;
}

std::string Student::getAddress()
{
	return address;
}

