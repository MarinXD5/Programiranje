#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void getNum(vector<int>& vb) {
    ifstream fp("brojevi.txt");
    string s;
    float num;

    if (!fp) {
        cout << "Ne mogu otvoriti file!";
    }

    while(fp >> num){
        vb.push_back(num);
    }
}

void izbaciEx(vector<int>& vb) {
    vector<int>::iterator it;

    for (it = vb.begin(); it != vb.end(); it++) {
        try {
            if (*it < 0) {
                throw 99;
            }
        }
        catch (int x) {
            cout << "Broj nije prirodan" << endl;
        }
    }
}

int prebroji(vector<int> vb) {
    vector<int>::iterator pi;
    int cnt = 0;

    for (pi = vb.begin(); pi < vb.end(); pi++) {
        if (*pi > 100) {
            cnt++;
        }
    }
    return cnt;
}

void izbaciveciod100(vector<int>& vb) {
    vector<int>::iterator i;
    int pozicija = 0;

    for (i = vb.begin(); i != vb.end(); i++) {
        if (*i < 100) {
            pozicija++;
            *i = pozicija;
            vb.erase(i);
        }
        else {
            pozicija++;
        }
    }
}

void sortirajSilazno(vector<int>& vb) {
    sort(vb.begin(), vb.end(), greater<>());
}

void ispis(vector<int> vb) {
    for (vector<int>::iterator it = vb.begin(); it != vb.end(); ++it)
        cout << *it << ' ';
}

int main() {
    vector<int> vb;
    vector<int>::iterator i;
    getNum(vb);

    ispis(vb);
    cout << endl;

    int rezultat = prebroji(vb);
    cout << "Brojeva vecih od 100 je: " << rezultat << endl;

    izbaciEx(vb);
    
    izbaciveciod100(vb);
    ispis(vb);
    

    sortirajSilazno(vb);
    ispis(vb); 
}