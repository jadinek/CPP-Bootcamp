#include "player.hpp"

Player::Player(WINDOW * win, int y, int x, char c){
    score = 0;
    lives = 3;
    shotsFired = false;
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
};
void Player::shoot(){
    yBullet = yLoc - 1;
    while (yBullet >= 4){
        displayBullet();
        yBullet--;
    }
    shotsFired = true;
};
void Player::mvleft(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
        xLoc = 1;
};
void Player::mvright(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
        xLoc = xMax-2;
};
int Player::getmv(){
    int choice =  wgetch(curwin);
    switch(choice)
    {
        case KEY_UP:
            shoot();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        default:
            break;
    }
    return choice;
};
void Player::display(){
    mvwaddch(curwin, yLoc, xLoc, character);
};
void Player::displayBullet(){
    mvwaddch(curwin, yBullet, xLoc, bullet);
};
void Player::deleteBullet(){
    yBullet = yLoc - 1;
    while (yBullet >= 4){
        mvwaddch(curwin, yBullet, xLoc, ' ');
        yBullet--;
    }
};
int Player::getLives(){
    return lives;
};
void Player::setScore(){
    score++;
};
int Player::getScore(){
    return score;
};
int Player::getXLoc(){
    return xLoc;
};
int Player::getYLoc(){
    return yLoc;
};
void Player::setLives(){
    lives--;
};
void Player::setShotsFired(){
    shotsFired = false;
};
bool Player::getShotsFired(){
    return shotsFired;
};