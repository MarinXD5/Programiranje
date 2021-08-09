#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const char alpha[] = "abcdefghijklmnoprstuvzxyqABCDEFGHIJKLMNOPRSTUVZXYQ";
int sLength = sizeof(alpha) - 1;


int main() {
	cout << "Welcome to CAPTCHA v1.0. This CAPTCHA is only text based. You need to alphabetically sort five, five letter strings!" << endl << endl;
	char captcha[10], userInput[10];
	int string_length = 5;
	srand(time(0));

	for (int i = 0; i < string_length; i++) {
		captcha[i] = alpha[rand() % sLength];
	} 

	for (int i = 0; i < string_length; i++) {
		cout << captcha[i];
	}
	cout << endl << endl;
	cout << "Enter the CAPTCHA:";
	cin >> userInput;

	int r = strcmp(captcha, userInput);

	if (r) {
		cout << "CAPTCHA MATCHED!!";
	}
	else {
		cout << "CAPTCHA NOT MATCHED!!";
	}
}