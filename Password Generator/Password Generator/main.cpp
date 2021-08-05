#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(char* pass, int arrayLength)
{
	for (int i = 0; i < arrayLength; i++) {
		cout << pass[i];
	}
}

int main() {
	int arrayLength, random_number;
	char* password;
	char c;
	srand(time(NULL));

	cout << "Welcome to Password generator v1.0" << endl;
	cout << "Please enter the amount of characters you want your password to have: ";
	cin >> arrayLength;

	password = new char[arrayLength];

	for (int i = 0; i < arrayLength; i++) {
		random_number = rand() % 26;
		c = 'a' + random_number;
		password[i] = c;
 	}

	print(password, arrayLength);

	delete password;

}