#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <math.h>

using namespace std;

class pozicija_tocke_u_prostoru
{
    private:
        double x;
        double y;
        double z;
    public:
        void postavljanjeTocaka(double a, double b, double c);
        void randomVrijednost(double kraj, double pocetak);
        double dohvatiVrijednostix();
        double dohvatiVrijednostiy();
        double dohvatiVrijednostiz();
        double pozicija2D(pozicija_tocke_u_prostoru t2);
        double pozicija3D(pozicija_tocke_u_prostoru t2);
};

class target
{
    private:
        bool pogoden=false;
    public:
        pozicija_tocke_u_prostoru a;
        pozicija_tocke_u_prostoru b;
        void pogodenaMeta();
        bool JelipogodenaMeta();
};

class weapon
{
    public:
        pozicija_tocke_u_prostoru x;
        int fullAmmo = 30, currentAmmo = 30;
        void reload();
        void shoot(target *meta, int n);
        void generirajPoziciju();
};

void target::pogodenaMeta()
{
    pogoden=true;
}

bool target::JelipogodenaMeta()
{
    return pogoden;
}

target* generirajMete(int n)
{
    target* meta = new target[n];

    for (int i = 0; i<n; i++)
    {
        meta[i].a.randomVrijednost(10,1);
        meta[i].b.randomVrijednost(20,11);
    }
    return meta;
}

void weapon::reload()
{
    currentAmmo = fullAmmo;
}

void weapon::shoot(target *meta, int n)
{
    for (int i = 0; i<n; i++)
    {
        if (meta[i].a.dohvatiVrijednostiy() <= x.dohvatiVrijednostiy() && meta[i].b.dohvatiVrijednostiy() >= x.dohvatiVrijednostiy())
        {
            meta[i].pogodenaMeta();
        }
    }
}

void weapon::generirajPoziciju()
{
    x.randomVrijednost(20,1);
}

int brojMeta(target* meta, int n)
{
    int cnt=0;

    for (int i = 0; i<n; i++)
    {
        if (meta[i].JelipogodenaMeta())
        {
            cnt++;
        }
    }

    return cnt;
}

void pozicija_tocke_u_prostoru::postavljanjeTocaka(double a=0, double b=0, double c=0)
{
    x=a;
    y=b;
    z=c;
}

double pozicija_tocke_u_prostoru::dohvatiVrijednostix()
{
    return x;
}

double pozicija_tocke_u_prostoru::dohvatiVrijednostiy()
{
    return y;
}

double pozicija_tocke_u_prostoru::dohvatiVrijednostiz()
{
    return z;
}

void pozicija_tocke_u_prostoru::randomVrijednost(double kraj, double pocetak)
{
    x=(rand() / (RAND_MAX / (kraj - pocetak))) + pocetak;
    y=(rand() / (RAND_MAX / (kraj - pocetak))) + pocetak;
    z=(rand() / (RAND_MAX / (kraj - pocetak))) + pocetak;
}

double pozicija_tocke_u_prostoru::pozicija2D(pozicija_tocke_u_prostoru t2)
{
    double rezultat;

    rezultat = sqrt((t2.dohvatiVrijednostix()-x)*(t2.dohvatiVrijednostix()-x) + (t2.dohvatiVrijednostiy()-y)*(t2.dohvatiVrijednostiy()-y));

    return rezultat;
}

double pozicija_tocke_u_prostoru::pozicija3D(pozicija_tocke_u_prostoru t2)
{
    double rezultat;

    rezultat = sqrt((t2.dohvatiVrijednostix()-x)*(t2.dohvatiVrijednostix()-x) +(t2.dohvatiVrijednostiy()-y)*(t2.dohvatiVrijednostiy()-y)+(t2.dohvatiVrijednostiz()-z)*(t2.dohvatiVrijednostiz()-z));

    return rezultat;
}

int main()
{
    pozicija_tocke_u_prostoru mojaPozicija;
    pozicija_tocke_u_prostoru mojaPozicija2;
    weapon oruzje;
    target *meta;

    srand((unsigned)time(NULL));
    int kraj = 6;
    mojaPozicija.randomVrijednost(6,1);
    mojaPozicija2.randomVrijednost(8,5);

    cout << "--------------------------------" << endl;
    cout << mojaPozicija.dohvatiVrijednostix() << endl;
    cout << mojaPozicija.dohvatiVrijednostiy() << endl;
    cout << mojaPozicija.dohvatiVrijednostiz() << endl;
    cout << "--------------------------------" << endl;

    cout << "---------------------------------" << endl;
    cout << mojaPozicija2.dohvatiVrijednostix() << endl;
    cout << mojaPozicija2.dohvatiVrijednostiy() << endl;
    cout << mojaPozicija2.dohvatiVrijednostiz() << endl;
    cout << "---------------------------------" << endl;

    cout << "---------------------------------" << endl;
    double mizracun2D = 0, mizracun3D = 0;
    mizracun2D = mojaPozicija.pozicija2D(mojaPozicija2);
    cout << mizracun2D << endl;
    mizracun3D = mojaPozicija.pozicija3D(mojaPozicija2);
    cout << mizracun3D << endl;
    cout << "---------------------------------" << endl;

    meta = generirajMete(7);
    oruzje.generirajPoziciju();
    oruzje.shoot(meta,7);

    cout << "---------------------------------" << endl;
    cout << oruzje.x.dohvatiVrijednostiy() << endl;
    cout << "---------------------------------" << endl;

    cout << "---------------------------------" << endl;
    for (int i = 0; i<7; i++)
    {
        cout << meta[i].a.dohvatiVrijednostiy() << endl;
        cout << meta[i].b.dohvatiVrijednostiy() << endl;
        cout << endl;
    }
    cout << "---------------------------------" << endl;

    cout << "---------------------------------" << endl;
    cout << "Pogodeno je: "<< brojMeta(meta, 7) << " meta" << endl;
    cout << "-------------------------------- " << endl;
}
