#include <iostream>
#include <cstdlib>
#include <string.h>
#include <vector>

using namespace std;

int racunanje(vector<string> vs) {
	int cnt = 0;

	for (vector<string>::iterator it = vs.begin(); it != vs.end(); it++) {
		cnt += (*it).length();
	}

	return cnt;
}

void racunanjeProsjeka(vector<string> vs) {
	float cnt;

	int rez = racunanje(vs);

	cnt = rez / vs.size();

	cout << "Prosjecan broj slova je:" << cnt << endl;
}

vector<string> izbacivanje(vector<string>& vs) {
	int max = vs[0].length();
	string tmp = "";
	int poz = 0;

	for (vector<string>::iterator it = vs.begin(); it != vs.end(); it++) {
		if ((*it).length() > max)
		{
			max = (*it).length();
			tmp = *it;
			poz++;
		}
	}
	vs.erase(vs.begin() + poz);

	return vs;
}

int main() {
	vector<string> vs;

	string s;
	char answ;

	cout << "zelite li unijeti string: " << endl;
	cin >> answ;
	while (answ == 'y' || answ == 'Y') {
		cout << "Unesite string" << endl;
		cin >> s;
		vs.push_back(s);
		cout << "zelite li unijeti string: " << endl;
		cin >> answ;
	}
	racunanjeProsjeka(vs);
	vs = izbacivanje(vs);

	for (int i = 0; i < vs.size(); i++) {
		cout << vs[i] << endl;
	}
}