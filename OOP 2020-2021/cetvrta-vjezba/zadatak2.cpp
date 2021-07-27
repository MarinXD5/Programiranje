#include "zadatak2.hpp"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

Board::Board()
{
    cout << "Pokrece se default konstruktor" << endl;

    char character = 'o';

    rows = 10;
    collumns = 10;

    this->matrix = new char*[rows];

    for (int i = 0; i<rows; i++)
    {
        matrix[i] = new char[collumns];
    }

    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<collumns; j++)
        {
            if (i == 0 || j == 0 || i==rows-1 || j == collumns-1)
            {
                matrix[i][j] = character;
            }
            else
            {
                matrix[i][j] = ' ';
            }
        }
    }

    cout << "Konstruktor je zavrsio sa inicijalizacijom varijabli" << endl;
}
Board::Board(int a, int b)
{
    cout << "Pokrece se konstruktor sa varijablama" << endl;

    rows = a;
    collumns = b;
    char character = 'o';

    this->matrix = new char*[rows];


    for (int i = 0; i<rows; i++)
    {
        matrix[i] = new char[collumns];
    }

    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<collumns; j++)
        {
            if (i == 0 || j == 0 || i==rows-1 || j == collumns-1)
            {
                matrix[i][j] = character;
            }
            else
            {
                matrix[i][j] = ' ';
            }
        }
    }
}

Board::Board(Board &mojBoard)
{
    cout << "Pokrece se copy konstruktor" << endl;

    rows = mojBoard.rows;
    collumns = mojBoard.collumns;

    this->matrix = new char*[rows];

    for (int i = 0; i<rows; i++)
    {
        matrix[i] = new char[collumns];
    }

    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<collumns; j++)
        {
            matrix[i][j] = mojBoard.matrix[i][j];
        }
    }
    cout << "Copy konstruktor je gotov sa kopiranjem prvog boarda u drugi" << endl;
}

Board::~Board()
{
    cout << "Pokrece se destruktor" << endl;
    for (int i = 0; i<rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cout << "Destruktor je zavrsio sa unistenjem Boarda" << endl;
}

void Board::display()
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<collumns; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void Board::zaokruzi(Point& a)
{
    if (a.x - (int)a.x >= 0.5)
    {
        a.x++;
    }

    a.x = (int) a.x;

    if (a.y - (int)a.y >= 0.5)
    {
        a.y++;
    }

    a.y = (int) a.y;
}

void Board::draw_char(Point p, char ch)
{
    this->zaokruzi(p);

    if (p.x >= rows-1 || p.y >= collumns-1)
    {
        return;
    }

    matrix[(int)p.x][(int)p.y] = ch;
}

void Board::draw_up_line(Point p, char ch)
{
    this->zaokruzi(p);

    if (p.x >= rows-1 || p.y >= collumns-1)
    {
        return;
    }

    while(p.x != 0)
    {
        matrix[(int)p.x][(int)p.y] = ch;
        p.x--;
    }
}

void Board::draw_line(Point p1, Point p2, char ch)
{
    this->zaokruzi(p1);
    this->zaokruzi(p2);

    if (p1.x >= rows-1 || p1.y >= collumns-1)
    {
        return;
    }

    if (p2.x >= rows-1 || p2.y >= collumns-1)
    {
        return;
    }

    int dx,dy,p,x,y;

    dx = p2.x - p1.x;
    dy = p2.y - p1.y;

    cout << dx << endl << dy << endl;

    x = p2.x;
    y = p2.y;

    p=2*dy-dx;

    while (x<p1.x)
    {
        if (p >= 0)
        {
            matrix[(int)x][(int)y] = ch;
            y += 1;
            p=p+2*dy-2*dx;
        }
        else
        {
            matrix[(int)x][(int)y] = ch;
            p=p+2*dy;
        }
        x=x+1;
    }
}
