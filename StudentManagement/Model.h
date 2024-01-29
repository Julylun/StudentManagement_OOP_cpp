#pragma once
#include "Header.h"

class Date {
public:
	
	//Attributes
	int day;
	int month;
	int year;
	//Methods
	Date();
	Date(int day, int month, int year);
	bool setDate(std::string ddMMyyyy);
	std::string debug();
	bool static isValidDate(int day, int month, int year);
	
public:
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getDay();
	int getMonth();
	int getYear();

	
};

class Student {
public:
	//Constructor
	Student();
	Student(int id, std::string name, Date birthDay, std::string address);

	//Getter&Setter
	void setId(int id);
	void setName(std::string name);
	void setBirthday(Date birthday);
	void setAddress(std::string address);
	int getId();
	std::string getName();
	Date getBirthday();
	std::string getAddress();
	

private:
	int id;
	std::string name;
	Date birthDay;
	std::string address;
};