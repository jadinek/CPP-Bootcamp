#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <ncurses.h>

class Player{
    public:
        Player(void);
        Player(Player const &p);
        ~Player();
        Player &operator =(Player const &p);
        Player(WINDOW * win, int y, int x, char c);
        void mvleft();
        void mvright();
        int getmv();
        void display();
        void shoot();
        void displayBullet();
        int getLives();
        int getScore();
        void deleteBullet();
        int getXLoc();
        int getYLoc();
        void setLives();
        void setScore();
        void setShotsFired();
        bool getShotsFired();

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        static const char bullet = '|';
        int yBullet;
        int lives;
        int score;
        bool shotsFired;
        WINDOW *curwin;
};

#endif