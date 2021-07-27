#include <iostream>

using namespace std;

struct broj
{
    int br, br2, div;

    broj(int br_, int br2_ ,int div_) : br(br_), br2(br2_), div(div_) {};
    operator double() const {return double(br*br2) / double(div); }
};


int main()
{
    broj number(5,1,9);
    double f = static_cast<double>(number);

    cout << f;

}
