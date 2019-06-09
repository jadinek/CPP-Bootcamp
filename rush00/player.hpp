#ifndef PLAYER_HPP
#define PLAYER_HPP

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
    int getLives();
    // int getTime();
    // int getScore();
    void deleteBullet();
    int getXLoc();
    int getYLoc();
    void setLives();

    private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    static const char bullet = '|';
    int yBullet;
    // int health;
    int lives;
    // int score;
    WINDOW *curwin;
};

Player::Player(WINDOW * win, int y, int x, char c){
    // health = 5;
    lives = 3;
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
        // wrefresh(curwin);
        yBullet--;
    }
    // display();
    // wrefresh(curwin);
    // deleteBullet();
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
// int Player::getTime(){

// };
// int Player::getScore(){
//     return score;
// };

int Player::getXLoc(){
    return xLoc;
};
int Player::getYLoc(){
    return yLoc;
};
void Player::setLives(){
    lives--;
};

#endif