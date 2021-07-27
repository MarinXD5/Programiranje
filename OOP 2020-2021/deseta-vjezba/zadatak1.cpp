#include "zadatak1.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

char unosOperacije()
{
	char operacija;

	cout << "Unesite operaciju: " << endl;
	cin >> operacija;
	if (operacija != '+' && operacija != '-' && operacija != '/' && operacija != '*'){
		throw ErrorOperacija();
	}
	else {
		return operacija;
	}
}

int unosBrojeva()
{
	int broj;

	cout << "Unesite broj: " << endl;
	cin >> broj;

	if (cin.fail()) {
		throw ErrorBroj();
	}
	else {
		return broj;
	}
}

int racunanje(int a, int b, int operacija)
{
	if (operacija == '+')
	{
		return a + b;
	}
	else if (operacija == '-')
	{
		return a - b;
	}
	else if (operacija == '*')
	{
		return a * b;
	}
	else if (operacija == '/')
	{
		if (b == 0)
		{
			throw ErrorNula();
		}
		else{
		return a / b;
		}
	}
}

int main()
{
	int a, b;
	char o;

	fstream fp("error.log", ios::app);

	while (1) {
		try {
			a = unosBrojeva();
			b = unosBrojeva();
			o = unosOperacije();

			cout << a << o << b << "=" << racunanje(a, b, o) << endl;
		}
		catch (Error& x) {
			time_t now = time(0);
			fp << ctime(&now);
			fp << x.ErrorGeneral();
			fp << endl;
		}
	}
}
