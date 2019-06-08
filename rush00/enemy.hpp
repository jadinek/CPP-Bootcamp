#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <ncurses.h>

class Enemy{
    public:
    Enemy(WINDOW * win, int y, int x, char c);

    // void mvup();
    // void mvdown();
    void mvleft();
    void mvright();
    // int getmv();
    void display();
    // void shoot();
    void displayBullet();

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
    // std::cout << yMax << std::endl;
    keypad(curwin, true);
    character = c;
};
// void Enemy::shoot(){
//     yBullet = yLoc - 1;
//     while (yBullet != 0){
//         displayBullet();
//         yBullet--;
//     }
// };
// void Player::mvdown(){
//     mvwaddch(curwin, yLoc, xLoc, ' ');
//     yLoc++;
//     // if(yLoc > yMax-2)
//     //     yLoc = yMax-2;
// };
void Enemy::mvleft(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
        xLoc = 1;
};
void Enemy::mvright(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
        xLoc = xMax-2;
};
// int Enemy::getmv(){
//     int choice =  wgetch(curwin);
//     switch(choice)
//     {
//         case KEY_UP:
//             shoot();
//             break;
//         // case KEY_DOWN:
//         //     mvdown();
//         //     break;
//         case KEY_RIGHT:
//             mvright();
//             break;
//         case KEY_LEFT:
//             mvleft();
//             break;
//         default:
//             break;
//     }
//     return choice;
// };
void Enemy::display(){
    mvwaddch(curwin, yLoc, xLoc, character);
};
void Enemy::displayBullet(){
    mvwaddch(curwin, yBullet, xLoc, bullet);
};

#endif