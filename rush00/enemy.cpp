#include "enemy.hpp"

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
};
void Enemy::setXLoc(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc = rand() % 47 + 6;
};