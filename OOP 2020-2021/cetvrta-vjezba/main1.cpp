#include <iostream>
#include <cstdlib>
#include "zadatak1.hpp"

int main()
{
    vektor mojVektor;


    int n = 5;
    int k = 1;

    vektor mojVektor2(n,k);
    vektor mojVektor3(mojVektor2);

    return 0;
}
