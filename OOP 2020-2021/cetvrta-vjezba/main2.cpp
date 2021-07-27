#include "zadatak2.hpp"
#include <iostream>
#include <cstdlib>
#include <conio.h>

int main()
{
    Board mojaPloca;

    int j = 6;
    int k = 10;
    Point p;
    Point p1;
    Point p2;

    p.x = 5.1;
    p.y = 2.9;

    p1.x = 5.5;
    p2.x = 1.4;

    p1.y = 2.5;
    p2.y = 3.3;

    char ch = 'x';

    Board mojaPloca2(j,k);
    Board mojaPloca3(mojaPloca2);

    mojaPloca.display();
    mojaPloca.draw_char(p,ch);
    mojaPloca.display();
    mojaPloca.draw_up_line(p,ch);
    mojaPloca.display();
    mojaPloca.draw_line(p1,p2,ch);
    mojaPloca.display();

}
