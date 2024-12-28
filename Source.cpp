#include <iostream>
#include <cstdio>
#include <windows.h>
#include "PasswordLab.h"

using namespace std;

void displayInterface();
void optionSelection();
string getPassword();

void option1();
void option2();
void option3();
void option4();
void option5();


PasswordLab lab;
int main() {
	bool running = true; //Main program loop 
	while (running) {
		displayInterface();

		optionSelection();


	}
}


void displayInterface() {
	cout << " ************************\n";
	cout << " *                      *\n";
	cout << " *     Password Lab     *\n";
	cout << " *                      *\n";
	cout << " ************************\n\n\n\n";

	cout << " Select an option:\n";
	cout << " 1) Evaluate a password's security\n";
	cout << " 2) Generate a safe password\n";
	cout << " 3) Analyze password list \"MyList.txt\"\n";
	cout << " 4) Generate a number of weak passwords, for some weird reason\n";
	cout << " 5) Exit\n\n";
}


void optionSelection() {
	int option = 0;
	bool validOption = false;

	while (!validOption) {
		cout << "Select a valid option.\n";
		cout << " --> ";
		cin >> option;

		switch (option) {
		case 1: 
			option1();
			validOption = true;
			break;
		case 2:
			option2();
			validOption = true;
			break;
		case 3:
			option3();
			validOption = true;
			break;
		case 4:
			option4();
			validOption = true;
			break;
		case 5:
			option5();
			break;
		default:
			break;
		}
	}
}

string getPassword() {
	cout << "\nPlease enter your password bro:\n -->";
	string str;
	cin >> str;
	return str;
}

int getNumOfPasswords() {
	int num = 0;
	cout << "\nHow many weak passwords to generate?\n";

	bool validOption = false;
	while (!validOption) {
		cout << "(Number can't be negative)\n";
		cout << " ---> ";
		cin >> num;
		cout << "\n\n";
		if (num >= 0) validOption = true;
	}
	return num;
}

void option1() {
	cout << lab.passwordAnalyzer(getPassword());
	Sleep(3000);
}

void option2() {
	cout << "Password succesfully generated below:\n |\n |\n-----> " << lab.passwordSecureGenerator() << "\n\n\n\n";
	Sleep(3000);
}

void option3() {
	lab.listAnalyzer();
	Sleep(3000);
}

void option4() {
	lab.generateWeakPasswords(getNumOfPasswords());
	Sleep(3000);
}

void option5() {
	exit(0);
}