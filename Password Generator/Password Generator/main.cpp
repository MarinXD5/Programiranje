#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int stringLength = sizeof(alphanum) - 1;

int main() {
	int arrayLength;
	srand(time(0));

	cout << "Welcome to Password generator v2.0" << endl;
	cout << "Please enter the amount of characters you want your password to have: ";
	cin >> arrayLength;

	for (int i = 0; i < arrayLength; i++) {
		cout << alphanum[rand() % stringLength];
 	}
}