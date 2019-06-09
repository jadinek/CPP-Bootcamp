#include "player.hpp"
#include "enemy.hpp"
#include "timer.hpp"

void collide( Player *p, Enemy *e){
    if (p->getXLoc() == e->getXLoc() && p->getYLoc() == e->getYLoc())
    {
        // std::cout << "yes";
        mvwaddch(e->getWin(), e->getYLoc(), e->getXLoc(), 'X');
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
    // refresh();
    // wrefresh(playwin);


    char playerPiece = '@';
    char enemyPiece = '?';

    // timer();
    double timer = clock();
	int		curr_time = timer - clock() / (CLOCKS_PER_SEC / 1000);
    
    Player *p = new Player(playwin, 21, 26, playerPiece);
    Enemy *e = new Enemy(playwin, 5, 26, enemyPiece);
    while(1){
        mvwprintw(playwin, 1, 1, "TIME %d", (curr_time-timer)/ CLOCKS_PER_SEC);
        mvwprintw(playwin, 2, 1, "LIVES %d", p->getLives());
        mvwprintw(playwin, 3, 1, "SCORE %d", 3);
        mvwprintw(playwin, 4, 1, "---------------------------------------------------");
    if (p->getLives() != 0 && p->getmv() != 'x'){

        p->display();
        e->display();
        p->getmv();
        p->display();
        e->getmv();
        e->display();
        collide(p, e);
        outOfRange(e);
        wrefresh(playwin);
    }}

    // makes sure program waits before exit
    endwin();

return 0;
}