#ifndef RUSH00_HPP
#define RUSH00_HPP

#include <iostream>
#include <ncurses.h>

class Player{
    public:
    Player(WINDOW * win, int y, int x, char c);

    // void mvup();
    // void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();
    void shoot();
    void displayBullet();

    private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    static const char bullet = '.';
    int yBullet;
    WINDOW *curwin;
};

Player::Player(WINDOW * win, int y, int x, char c){
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    // std::cout << yMax << std::endl;
    keypad(curwin, true);
    character = c;
};
void Player::shoot(){
    yBullet = yLoc - 1;
    while (yBullet != 0){
        displayBullet();
        yBullet--;
    }
    // mvwaddch(curwin, yLoc, xLoc, ' ');
    // yLoc--;

    // if(yLoc < 1)
    //     yLoc = 1;
};
// void Player::mvdown(){
//     mvwaddch(curwin, yLoc, xLoc, ' ');
//     yLoc++;
//     // if(yLoc > yMax-2)
//     //     yLoc = yMax-2;
// };
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
        // case KEY_DOWN:
        //     mvdown();
        //     break;
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

#endif