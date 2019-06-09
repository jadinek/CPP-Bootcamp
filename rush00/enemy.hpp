#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <ncurses.h>

class Enemy{
    public:
        Enemy(WINDOW * win, int y, int x, char c);
        void mvdown();
        int getmv();
        void display();
        void shoot();
        void displayBullet();
        int getXLoc();
        int getYLoc();
        void setYLoc();
        void setXLoc();

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        static const char bullet = '.';
        int yBullet;
        WINDOW *curwin;
};

#endif