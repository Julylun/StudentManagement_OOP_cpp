#include "Model.h"
#include "Header.h"
#include <Vector>

using namespace std;

vector<Student> vStudent;
void addStudent();
void deleteStudent();
void findStudent();

void findStudent() {
	system("cls");
	int id, index(-1);
	bool isFindOut(0);
	cout << "-*-*- Delete Student -*-*-\n";
	cout << "--------------------------\n";
	cout << "Code find all: -150905\n";
	cout << "Choose student to find (id): "; cin >> id;
	if (id == -150905) {
		system("cls");
		cout << "Id\t|\tName\t|\tBirthday\t|\tAddress\t\n";
		cout << "--------------------------------------------------------------------\n";
		for (Student std : vStudent) {
			cout << std.getId() << "\t|\t" << std.getName() << "\t|\t" << std.getBirthday().debug() << "\t|\t" << std.getAddress() << "\n";
		}
		cout << "--------------------------------------------------------------------\n";
		system("pause");
		return;
	}
	for (Student student : vStudent) {
		index++;
		if (student.getId() == id) {
			isFindOut = true;
			break;
		}
	}
	system("cls");
	if (isFindOut == false) {
		cout << "Can't find out";
		system("pause");
		return;
	}
	Student std = vStudent[index];
	cout << "Id\t|\tName\t|\tBirthday\t|\tAddress\n";
	cout << std.getId() << "\t|\t" << std.getName() << "\t|\t" << std.getBirthday().debug() << "\t|\t" << std.getAddress() << "\n";
	cout << "---------------------------\n";
	system("pause");
}
void deleteStudent() {
	int id, index(-1);
	cout << "-*-*- Delete Student -*-*-\n";
	cout << "--------------------------\n";
	cout << "Choose student to delete (id): "; cin >> id;
	for (Student student : vStudent) {
		index++;
		if (student.getId() == id) break;
	}
	Student std = vStudent[index];
	vStudent.erase(vStudent.begin() + index);
}
void addStudent() {
	bool isContinued(true);
	int id;
	string name, address, strBirthday;
	Date birthday;
	while (true) {
		system("cls");
		cout << "-*-*- Add Student -*-*-\n";
		cout << "-----------------------\n";
		cout << "Id: "; cin >> id;
		cout << "Name: "; cin >> name;
		cout << "Address: "; cin >> address;
		cout << "Birthday (dd-MM-yyyy): "; cin >> strBirthday;
		if (birthday.setDate(strBirthday) == true) {
			break;
		}
		cout << "Birthday is unvalid\n";
		system("pause");
	}
	Student std(id, name, birthday, address);
	vStudent.push_back(std);
}

int main() {
	int choice;
	while (true) {
		
		
		system("cls");
		//for (Student std : vStudent) cout << std.getName() << "\n";
		cout << "-*-*- Student Management -*-*-\n";
		cout << "------------------------------\n";
		cout << "1) Add Student\n";
		cout << "2) Delete Student\n";
		cout << "3) Find Student by id\n";
		cout << "------------------------------\n";
		cout << "------------------------------\n";
		cout << "Your choice: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			addStudent();
			break;
		}
		case 2: {
			deleteStudent();
			break;
		}
		case 3: {
			findStudent();
			break;
		}
		default: {
			cout << "Your choice is wrong. Please type again.\n";
			system("pause");
			system("cls");
		}
		}
	}

}