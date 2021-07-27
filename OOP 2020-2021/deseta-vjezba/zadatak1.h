#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class Error {
private:

public:
	virtual string ErrorGeneral() = 0;
};

class ErrorOperacija : public Error{
private:
	string s = "Nepoznata operacija";
public:
	string ErrorGeneral() { return s; };
};

class ErrorNula : public Error {
private:
	string s = "Dijeljenje sa 0";
public:
	string ErrorGeneral() { return s; };
};

class ErrorBroj : public Error {
private:
	string s = "Nepoznat broj";
public:
	string ErrorGeneral() { return s; };
};
