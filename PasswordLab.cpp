#include <fstream>
#include <string>
#include <random>
#include "PasswordLab.h"

//First requirement - Evaluating a password
string PasswordLab::passwordAnalyzer(string password) {
	string result = "";
	int passwordSecurity = 0;
	bool a, b = false, c = false, d = false, e = false, f = true;

	//Checking size
	password.length() >= 12 ? a = true : a = false;

	//Checking if it cotains an integer
	for (int i = 0; i < password.length(); i++) {
		if (isdigit(password[i])) {
			b = true;
			break;
		}
	}

	//Checkimg for special character
	for (int i = 0; i < password.length(); i++) {
		if (ispunct(password[i])) {
			c = true;
			break;
		}
	}

	//Checking for capital letter
	for (int i = 0; i < password.length(); i++) {
		if (isupper(password[i])) {
			d = true;
			break;
		}
	}

	//Checking for lower letter
	for (int i = 0; i < password.length(); i++) {
		if (islower(password[i])) {
			e = true;
			break;
		}
	}

	//Checking if password exists in the list
	ifstream file("CommonPasswords.txt");
	string word;
	
	if (!file)
	{
		std::cout << "Error finding password file.\n" << std::endl;
	}
	
	while (file >> word) {
		if (password == word) f = false;
	}

	//Conclusion and feedback
	cout << "\n";
	if (a) passwordSecurity++;
	else result += "(!) Password should have at least a length of 12 characters.\n";

	if (b) passwordSecurity++;
	else result += "(!) Password should contain at least 1 number.\n";

	if (c) passwordSecurity++;
	else result += "(!) Password should contain at least 1 special characters.\n";

	if (d) passwordSecurity++;
	else result += "(!) Password should contain at least 1 upper case letter.\n";

	if (e) passwordSecurity++;
	else result += "(!) Password should contain at least 1 lower case letter.\n";

	if (f) passwordSecurity++;
	else result += "(!) This password exists in the top 100 most common list.\n";

	result += "Password security requirements met: " + to_string(passwordSecurity) + "/6\n\n\n\n";

	return result;
}

//Second option - generate a secure password
string PasswordLab::passwordSecureGenerator() {

	string res = "";
	for (int i = 0; i < 12; i++) res += 33 + rand() % 89;


	int number = 48 + rand() % 10;
	res[0 + rand() % 3] = number;

	int specSymbol = 33 + (rand() % 14);
	res[3 + rand() % 3] = specSymbol;

	int capitalLetter = 65 + rand() % 26;
	res[6 + rand() % 3] = capitalLetter;

	int lowerLetter = 97 + rand() % 26;
	res[9 + rand() % 3] = lowerLetter;

	return res;
}

//Third option - analyze a list of passwords and store in Results.txt
int PasswordLab::listAnalyzer() {
	PasswordLab lab;

	//Opening input file, always named MyList.txt
	ifstream passFile("MyList.txt");
	if (!passFile)
	{
		cout << "Error finding password file.\n";
		return 1;
	}


	ofstream resultFile;
	resultFile.open("Results.txt");
	// Check if the file was successfully created.
	if (!resultFile.is_open()) {
		cout << "Error in creating file!\n";
		return 1;
	}
	cout << "Results.txt created successfully.\n";

	//Writing in Results.txt
	string word;
	while (passFile >> word) {
		resultFile << "Analyzing password: \"" + word + "\"\n";
		resultFile << lab.passwordAnalyzer(word);
	}

	return 0;
}

//Fourth option - generate weak passwords
int PasswordLab::generateWeakPasswords(int n) {
	ofstream resultFile;
	resultFile.open("WeakPasswords.txt");
	if (!resultFile) {
		cout << "Error creating WeakPasswords.txt\n";
		return 1;
	}

	string str = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 8; j++) {
			str += (65 + rand() % 26);
		}
		resultFile << str << endl;
		str = "";
	}

	cout << "WeakPasswords.txt generated succesfully! Enjoy I guess\n\n";
	return 0;
}
