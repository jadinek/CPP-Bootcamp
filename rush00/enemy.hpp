#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <ncurses.h>

class Enemy{
    public:
        Enemy(void);
        Enemy(Enemy const &e);
        Enemy(WINDOW * win, int y, int x, char c);
        ~Enemy();
        Enemy &operator =(Enemy const &e);
        void mvdown();
        int getmv();
        void display();
        // void shoot();
        // void displayBullet();
        int getXLoc();
        int getYLoc();
        void setYLoc();
        void setXLoc();
        void setYLoc(int y);
        void setXLoc(int x);
        // void deleteBullet();
        // void setShotsFired();
        // bool getShotsFired();

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        static const char bullet = '.';
        int yBullet;
        WINDOW *curwin;
        // bool shotsFired;
};

#endif