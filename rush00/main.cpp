#include "player.hpp"
#include "enemy.hpp"

#define playerPiece '^'
#define enemy1      '$'
#define enemy2      '&'
#define enemy3      '#'
#define astroid     '*'


void collide(Player *p, Enemy *e){
    if (p->getXLoc() == e->getXLoc() && p->getYLoc() == e->getYLoc())
    {
        e->display();
        e->setYLoc();
        e->setXLoc();
        p->setLives();
    }
};
void collide(Player *p, Enemy *e1, Enemy *e2){
    if ((p->getXLoc() == e1->getXLoc() && p->getYLoc() == e1->getYLoc()) ||
    (p->getXLoc() == e2->getXLoc() && p->getYLoc() == e2->getYLoc()))
    {
        int x, y;
        e1->display();
        e2->display();
        e1->setYLoc();
        y = e1->getYLoc();
        e1->setXLoc();
        x = e1->getXLoc();
        e2->setYLoc(y);
        e2->setXLoc(x+1);
        p->setLives();
    }
};

void outOfRange(Enemy *e){
    if(e->getYLoc() == 21)
    {
        e->setYLoc();
        e->setXLoc();
    }
}
void outOfRange(Enemy *e1, Enemy *e2){
    if(e1->getYLoc() == 21)
    {
        int x, y;
        e1->setYLoc();
        y = e1->getYLoc();
        e1->setXLoc();
        x = e1->getXLoc();
        e2->setYLoc(y);
        e2->setXLoc(x+1);
    }
}

void destroyEnemy(Player *p, Enemy *e){
    if (p->getXLoc() == e->getXLoc())
    {
        e->setYLoc();
        e->setXLoc();
        p->setScore();
    }
}
void destroyEnemy(Player *p, Enemy *e1, Enemy *e2){
    if ((p->getXLoc() == e1->getXLoc()) || (p->getXLoc() == e2->getXLoc()))
    {
        int x, y;
        e1->setYLoc();
        y = e1->getYLoc();
        e1->setXLoc();
        x = e1->getXLoc();
        e2->setYLoc(y);
        e2->setXLoc(x+1);
        p->setScore();
    }
}

int main(){
    // ncurses start
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);

    // create a window for input
    WINDOW *playwin = newwin(23, 55, 0, 0);
    box(playwin, 0, 0);
    nodelay(playwin, TRUE);
    halfdelay(1);

    char input;
    srand(time(0));

    Player *p = new Player(playwin, 21, 26, playerPiece);
    Enemy *e1 = new Enemy(playwin, 5, 26, enemy1);
    Enemy *e2 = new Enemy(playwin, 8, 20, enemy2);
    Enemy *e3 = new Enemy(playwin, 4, 8, enemy3);
    Enemy *e4 = new Enemy(playwin, 4, 9, enemy3);

    while(1){
        mvwprintw(playwin, 1, 1, "TIME %d", 1);
        mvwprintw(playwin, 2, 1, "LIVES %d", p->getLives());
        mvwprintw(playwin, 3, 1, "SCORE %d", p->getScore());
        mvwprintw(playwin, 4, 1, "-----------------------------------------------------");
        
        if (p->getLives() != 0 && p->getmv() != 'x'){
            p->display();
            e1->display();
            e2->display();
            e3->display();
            e4->display();
            p->getmv();
            if (p->getShotsFired())
            {
                destroyEnemy(p, e1);
                destroyEnemy(p, e2);
                destroyEnemy(p, e3, e4);
                p->setShotsFired();
                p->deleteBullet();
                wrefresh(playwin);
            }
            p->display();
            e1->mvdown();
            e2->mvdown();
            e3->mvdown();
            e4->mvdown();
            e1->display();
            e2->display();
            e3->display();
            e4->display();
            collide(p, e1);
            collide(p, e2);
            collide(p, e3, e4);
            outOfRange(e1);
            outOfRange(e2);
            outOfRange(e3, e4);
            box(playwin, 0, 0);
            wrefresh(playwin);
        }
        if (p->getLives() == 0){
            std::cout << "GAME OVER" << std::endl;
            std::cin >> input;
            break;
        }
    }

    endwin();

return 0;
}