#include "enemy.hpp"

Enemy::Enemy(void){};
Enemy::Enemy(Enemy const &e){
    *this = e;
};
Enemy::Enemy(WINDOW * win, int y, int x, char c){
    curwin = win;
    yLoc = y;
    xLoc = x;
    // shotsFired = false;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
};
Enemy::~Enemy(){};

Enemy &Enemy::operator =(Enemy const &e){
    this->xLoc = e.xLoc;
	this->yLoc = e.yLoc;
	return (*this);
};
// void Enemy::shoot(){
//     yBullet = yLoc + 1;
//     while (yBullet <= 4){
//         displayBullet();
//         yBullet++;
//     }
//     shotsFired = true;
// };
// void Enemy::deleteBullet(){
//     yBullet = yLoc + 1;
//     while (yBullet <= 4){
//         mvwaddch(curwin, yBullet, xLoc, ' ');
//         yBullet++;
//     }
// };
void Enemy::mvdown(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc > yMax-2)
        yLoc = yMax-2;
};
void Enemy::display(){
    mvwaddch(curwin, yLoc, xLoc, character);
};
// void Enemy::displayBullet(){
//     mvwaddch(curwin, yBullet, xLoc, bullet);
// };
int Enemy::getXLoc(){
    return xLoc;
};
int Enemy::getYLoc(){
    return yLoc;
};
void Enemy::setYLoc(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc = rand() % 20 + 7;
};
void Enemy::setXLoc(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc = rand() % 47 + 6;
};
void Enemy::setYLoc(int y){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc = y;
};
void Enemy::setXLoc(int x){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc = x;
};
// void Enemy::setShotsFired(){
//     shotsFired = false;
// };
// bool Enemy::getShotsFired(){
//     return shotsFired;
// };