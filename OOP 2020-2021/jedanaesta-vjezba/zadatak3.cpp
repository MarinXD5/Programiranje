#include <iostream>
#include<string.h>
using namespace std;

void razmak(string& s) {
 
    char tocka = '.';
    char zarez = ',';

    for (int i = 0; i<s.length(); i++){
        if (s[i] == ',' || s[i] == '.' && s[i-1] == ' '){
            s.erase(s.begin() +(i - 1));
            s.insert(s.begin() + i, ' ');
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && s[i+1] == ' ') {
            s.erase(s.begin() + i);
        }
    }

    cout << s;
}

int main()
{ 
    string s = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .";

    razmak(s);
    
    return 0;
}