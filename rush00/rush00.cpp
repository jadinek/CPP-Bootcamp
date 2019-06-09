#include "player.hpp"
#include "enemy.hpp"

#define playerPiece '^'
#define enemy1      '$'
#define enemy2      '&'
#define enemy3      '#'


void collide(WINDOW *win, Player *p, Enemy *e){
    if (p->getXLoc() == e->getXLoc() && p->getYLoc() == e->getYLoc())
    {
        // std::cout << "++++++++++++";
        mvwaddch(win, e->getYLoc(), e->getXLoc(), 'X');
        wrefresh(win);
        e->display();
        e->setYLoc();
        e->setXLoc();
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

int main(){

    // ncurses start
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);

    // get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // create a window for input
    WINDOW *playwin = newwin(23, 53, 0, 0);
    box(playwin, 0, 0);
    nodelay(playwin, TRUE);
    halfdelay(1);

    char input;

    // clock_t curr, start;
    // start = clock();

    Player *p = new Player(playwin, 21, 26, playerPiece);
    Enemy *e1 = new Enemy(playwin, 5, 26, enemy1);
    Enemy *e2 = new Enemy(playwin, 8, 20, enemy2);
    Enemy *e3 = new Enemy(playwin, 4, 8, enemy3);
    while(1){
        // curr = clock();
        // double secs = (curr-start)/ CLOCKS_PER_SEC;
        mvwprintw(playwin, 1, 1, "TIME %d", 1);
        mvwprintw(playwin, 2, 1, "LIVES %d", p->getLives());
        mvwprintw(playwin, 3, 1, "SCORE %d", 3);
        mvwprintw(playwin, 4, 1, "---------------------------------------------------");
        if (p->getLives() != 0 && p->getmv() != 'x'){
            p->display();
            e1->display();
            e2->display();
            e3->display();
            p->getmv();
            p->display();
            e1->getmv();
            e2->getmv();
            e3->getmv();
            e1->display();
            e2->display();
            e3->display();
            collide(playwin, p, e1);
            collide(playwin, p, e2);
            collide(playwin, p, e3);
            outOfRange(e1);
            outOfRange(e2);
            outOfRange(e3);
            wrefresh(playwin);
        }
        if (p->getLives() == 0){
            std::cout << "GAME OVER" << std::endl;
            std::cin >> input;
            break;
        }
    }

    // makes sure program waits before exit
    endwin();

return 0;
}