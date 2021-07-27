#include "zadatak1.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    EBook knjiga;
    knjiga.sAuthor("Marin");
    knjiga.sTitle("Programiranje u c++ :)");
    knjiga.setIme("AAAA");


    puts(knjiga.gAuthor());
    puts(knjiga.gTitle());
    puts(knjiga.getime_datoteke());

}
