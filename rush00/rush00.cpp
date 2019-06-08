#include "player.hpp"
#include "enemy.hpp"

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
    WINDOW *playwin = newwin(20, 53, 0, 0);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    // start_color();
    // init_pair(1, COLOR_BLUE, COLOR_GREEN);
    // wattron(playwin, COLOR_PAIR(1));
    char playerPiece = '@';
    char enemyPiece = '?';

    // int x = 18, y = 26;
    
    Player *p = new Player(playwin, 18, 26, playerPiece);
    Enemy *e = new Enemy(playwin, 1, 26, enemyPiece);
    do{
        p->display();
        e->display();

        wrefresh(playwin);
    } while(p->getmv()!= 'x');

    // makes sure program waits before exit
    endwin();

return 0;
}