#include "Model.h"

//Getter&Setter
void Date::setDay(int day) {
	Date::day = day;
}

void Date::setMonth(int month) {
	Date::month = month;
}

void Date::setYear(int year) {
	Date::year = year;
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}


//Methods
Date::Date() {
	//std::cout << "[Date.cpp]<Constructor> Date is created\n";
}

Date::Date(int day, int month, int year) {
	Date();
	try {
		if (isValidDate(day, month, year) == false) throw WrongDateException();
	} catch (WrongDateException wde) {
		std::cout << "[Date.cpp]<Constructor>WrongDateException is cautch!\n";
		return;
	}
	Date::day = day;
	Date::month = month;
	Date::year = year;

	//std::cout << debug() + "\n";
}

std::string Date::debug() {
	return numberToString(day) + "/" + numberToString(month) + "/" + numberToString(year);
}

int dayInMonth(int month, int year) {
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: {
		return 30;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11: {
		return 31;
		break;
	}
	case 2: {
		if (year % 4 == 0 && year % 100 != 0) return 29;
		else return 28;
	}
	}
}

bool Date::isValidDate(int day, int month, int year)
{
	std::cout << "[Date]<isValidDate>: isValidDate function is called\n";
	if (year < 1) return false;
	if (month > 12 || month < 1) return false;
	if (day > dayInMonth(month, year)) return false;
	return true;
}

bool Date::setDate(std::string ddMMyyyy) {
	try {
		int dashIndexArray[2], dashIndex(0);
		if (ddMMyyyy.length() > 10) throw WrongDateException();
		for (int i(0); i < ddMMyyyy.length(); i++) {
			if (ddMMyyyy[i] == '-') {
				dashIndexArray[dashIndex] = i;
				dashIndex++;
				if (dashIndex > 2) {
					std::cout << "dashIndex > 2 error\n";
					throw WrongDateException();

				}
			}
		}
		if (dashIndex == 0) {
			std::cout << "dashIndex == 0 error\n";
			throw WrongDateException();
		}
		std::string tempString = "";
		for (int i(0); i < dashIndexArray[0]; i++) {
			tempString += ddMMyyyy[i];
		}
		Date::setDay(stringToNumber(tempString));
		tempString = "";
		
		for (int i(dashIndexArray[0]+1); i < dashIndexArray[1]; i++) {
			tempString += ddMMyyyy[i];
		}
		//std::cout << "[Date.cpp]<setDate>: tempString - - -> " << tempString << "\n";
		//std::cout << "[Date.cpp]<setDate>: dashIndex - - -> " << dashIndexArray[0] << " " << dashIndexArray[1] << "\n";
		Date::setMonth(stringToNumber(tempString));
		tempString = "";
		for (int i(dashIndexArray[1] + 1); i < ddMMyyyy.length(); i++) {
			tempString += ddMMyyyy[i];
		}
		Date::setYear(stringToNumber(tempString));
		if (isValidDate(day, month, year) == false) throw WrongDateException();
		//std::cout << "[Date.cpp]<setDate>: tempString - - -> " << tempString << "\n";
		return true;
	}
	catch (WrongDateException wde) {
		std::cout << "[Date]<setDate>: WrongDateException is cautch!\n";
		return false;
	}
	
}


