#include "zadatak2.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Igra::Igra()
{
    cout << "Postavlja se vrijednost kovanica!" << endl;
    pet_kuna = 5;
    dvije_kune = 2;
    jedna_kuna = 1;
    prazna_ruka = 0;
    cout << "Zavrseno je postavljanje vrijednosti kovanica!" << endl;
}

int Igrac::setbrojIgraca()
{
    cout << "Unesite broj igraca:" << endl;
    cin >> brojIgraca;

    return brojIgraca;
}

void Igra::gameLogic(Igrac Player)
{
    int br = Player.setbrojIgraca();

    int igraci[br];
    int broj5, broj2, broj1, broj0, rezultat[br];
    int ukupniBodovi = 3;
    int bodovi[br] = {0};
    char answ;

    int i = 0;

    while(bodovi[i] < ukupniBodovi)
    {
        for (int i = 0; i<br; i++)
        {
            rezultat[i] = 0;
            cout << "Zelite li praznu ruku" << endl;
            cout << "Unesite Y(Yes) ili N(No) za odabir!" << endl;
            cin >> answ;

            if (answ == 'Y' || answ == 'y')
            {
                rezultat[i] = 0;
            }
            else
            {
                for (int j = 0; j<br; j++)
                {
                    cout << "Unesite koliko kovanica od 5 kuna zelite: " << endl;
                    cin >> broj5;

                    if (broj5 > 3)
                    {
                        cout << "Ne mozete imati vise od 3 iste kovanice u jednoj ruci!" << endl;
                        break;
                    }
                    else
                    {
                        pet_kuna = pet_kuna * broj5;
                        rezultat[i] += pet_kuna;
                    }
                    cout << "Unesite koliko kovanica od 2 kune zelite: " << endl;
                    cin >> broj2;
                    if (broj2 > 3)
                    {
                        cout << "Ne mozete imati vise od 3 iste kovanice u jednoj ruci!" << endl;
                        break;
                    }
                    else
                    {
                        dvije_kune = dvije_kune * broj2;
                        rezultat[i] += dvije_kune;
                    }
                    cout << "Unesite koliko kovanica od 1 kune zelite: " << endl;
                    cin >> broj1;
                    if (broj1 > 3)
                    {
                        cout << "Ne mozete imati vise od 3 iste kovanice u jednoj ruci!" << endl;
                        break;
                    }
                    else
                    {
                        jedna_kuna = jedna_kuna * broj1;
                        rezultat[i] += jedna_kuna;
                    }
                }
            }
        }

        for (int i = 0; i<br; i++)
        {
            int pogadanje = 0;
            cout << rezultat[i] << endl;
            cout << "Unesite neki broj i pokusajte pogoditi ukupan zbroj kovanica :) " << endl;
            cin >> pogadanje;


            while (rezultat[i] != pogadanje)
            {
                cout << "Nije tocno...pokusajte ponovo!" << endl;
                cin >> pogadanje;
            }

            if (rezultat[i] == pogadanje)
            {
                cout << "Bravo... to je zbroj kovanica u rukama!!";
                bodovi[i]++;
                i++;
                break;
            }
        }

    }
}
