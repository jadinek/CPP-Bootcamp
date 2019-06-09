#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <ncurses.h>

class Enemy{
    public:
    Enemy(WINDOW * win, int y, int x, char c);

    // void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();
    void shoot();
    void displayBullet();
    int getXLoc();
    int getYLoc();
    // WINDOW* getWin();
    // void hasDied();
    void setYLoc();
    void setXLoc();

    private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    static const char bullet = '.';
    int yBullet;
    WINDOW *curwin;
};

Enemy::Enemy(WINDOW * win, int y, int x, char c){
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
};
void Enemy::shoot(){
    yBullet = yLoc - 1;
    while (yBullet != 0){
        displayBullet();
        yBullet--;
    }
};
void Enemy::mvdown(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc > yMax-2)
        yLoc = yMax-2;
};
void Enemy::mvleft(){
    mvdown();
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
        xLoc = 1;
};
void Enemy::mvright(){
    mvdown();
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
        xLoc = xMax-2;
};
int Enemy::getmv(){
    srand(time(0));
    int choice =  rand() %3 + 1;
    switch(choice)
    {
        case 1:
            mvdown();
            break;
        case 2:
            mvright();
            break;
        case 3:
            mvleft();
            break;
        default:
            break;
    }
    return choice;
};
void Enemy::display(){
    mvwaddch(curwin, yLoc, xLoc, character);
};
void Enemy::displayBullet(){
    mvwaddch(curwin, yBullet, xLoc, bullet);
};

int Enemy::getXLoc(){
    return xLoc;
};
int Enemy::getYLoc(){
    return yLoc;
};

void Enemy::setYLoc(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc = rand() % 21 + 7;
    // std::cout << "new yLoc = " << yLoc << std::endl;
};
void Enemy::setXLoc(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc = rand() % 47 + 6;

    // std::cout << "new xLoc = " << xLoc << std::endl;
};

#endif