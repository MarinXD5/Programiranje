#include <iostream>

using namespace std;

int& referenca_na_element_niza(int (&niz)[5])
{
    int i;

    cout << "Unesite i-ti broj koji zelite izolirati: \n";
    cin >> i;

    return niz[i];
}

int main()
{
    int niz[5]={1,2,3,4,5};

    int &lvalue = referenca_na_element_niza(niz);

    cout << "Stara vrijednost je: " << lvalue;

    lvalue += 1;

    cout << "Nova vrijednost je: " << lvalue;
}
