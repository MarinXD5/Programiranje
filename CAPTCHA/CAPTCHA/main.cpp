#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const char alpha[] = "abcdefghijklmnoprstuvzxyqABCDEFGHIJKLMNOPRSTUVZXYQ";
int sLength = sizeof(alpha) - 1;


int main() {
	char captcha[10], userInput[10];
	int string_length = 5, cnt = 0;
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

	for (int i = 0; i < string_length; i++) {
		if (captcha[i] == userInput[i]){
			cnt++;
		}
		else {
			break;
		}
	}
	

	if (cnt==5) {
		cout << "CAPTCHA MATCHED!!";
	}
	else {
		cout << "CAPTCHA NOT MATCHED!!";
	}
}