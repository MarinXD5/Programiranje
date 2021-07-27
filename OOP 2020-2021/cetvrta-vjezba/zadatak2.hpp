#pragma once

struct Point
{
    double x,y;
};

class Board
{
    private:
        int rows;
        int collumns;
        char** matrix;
    public:
        Board();
        Board(int a, int b);
        Board(Board &mojBoard);
        ~Board();
        void zaokruzi(Point &a);
        void draw_char(Point p, char ch);
        void display();
        void draw_up_line(Point p, char ch);
        void draw_line(Point p1, Point p2, char ch);

};


