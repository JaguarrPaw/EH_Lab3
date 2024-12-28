#ifndef PASSWORDLAB_H
#define PASSWORDLAB_H

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class PasswordLab
{
public:
	string passwordAnalyzer(string);
	string passwordSecureGenerator();
	int listAnalyzer();
	int generateWeakPasswords(int);
};



#endif
