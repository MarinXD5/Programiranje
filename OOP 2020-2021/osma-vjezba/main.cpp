#include <iostream>

using namespace std;

class money
{
private:
    int kuna;
    int lipa;
public:
    money()
    {
        kuna = 0;
        lipa = 0;
    }
    money (int kn, int lp)
    {
        kuna = kn;
        lipa = lp;
    }
    friend money operator+(money juha, money becki);
    friend money operator-=(money racun, money pivo);
    friend money operator+=(money racun, money babic);
    friend ostream& operator<<(ostream& os, const money& racun);
};

money operator+(money juha, money becki)
{
    money temp;
    temp.kuna = juha.kuna + becki.kuna;
    temp.lipa = juha.lipa + juha.lipa;

    return temp;
}

money operator-=(money racun, money pivo)
{
    racun.kuna -= pivo.kuna;
    racun.lipa -= pivo.lipa;

    return racun;
}

money operator+=(money racun, money babic)
{
    racun.kuna += babic.kuna;
    racun.lipa += babic.lipa;

    return racun;
}

ostream& operator<<(ostream& os, const money& racun)
{
    os << racun.kuna;

    return os;
}

/* Nalazimo se u hipotetskoj ulozi konobara u restoranu. Hipotetskom gostu treba izdati hipotetski racun*/
int main()
{
    //zadan je jednostavan cjenik
    money juha(11,30), becki(15,50), salata(10,0), pivo(15,0), babic(16,40);
    // gost je konzumirao:
    money racun = juha + becki + salata + pivo;
    // na zalost nas konobar je nepazljiv pa pivo treba stornirati
     racun -= pivo;
     //i dodati babic
     racun += babic;


    cout << racun << endl;
}
