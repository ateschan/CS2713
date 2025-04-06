//Addison Teschan Mar 22, 25 

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "ncurses_helper.h"

static void finish(int sig);

int main(int argc, char *argv[])
{
    GameBoard board;
    board.villages = 0;
    board.food = 0;
    board.end_flag = 0;

    memset(board.boardGrid, '.', sizeof board.boardGrid); // *
    board_randomize(&board);
    board.boardGrid[4][4] = 'C';

    //COPY ALL FROM BOARDGRID INTO OG FOR LATER DESTROY PURPOSES
    for (int i = 0; i < BOARD_COLS; i++) {
      for (int j = 0; j < BOARD_COLS; j++) {
        board.OGboardGrid[i][j] = board.boardGrid[i][j];
      }
    }

    PlayerPosition PlayerPosition;

    PlayerPosition.x = 4;
    PlayerPosition.y = 4;

    board.PlayerPosition = PlayerPosition;

    //ncurses stuff
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    curs_set(2);
    color_init();
  
    board_render(&board);

    int cursor_x = (4 + 4 + getmaxx(stdscr) / 2) - 9;
    int cursor_y = (4 + getmaxy(stdscr) / 2) - 7;
    move(cursor_y, cursor_x);

   for (;;) {
    refresh();
    int ch = getch();
    input_handle(ch, &cursor_x, &cursor_y, &board);
    move(cursor_y, cursor_x);
    if (board.end_flag == 1) {
      game_end(&board);
      return 0;
    }
  }
}

static void finish(int sig)
{
    endwin();
    exit(0);
}
