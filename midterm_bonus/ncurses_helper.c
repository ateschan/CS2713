#include "ncurses_helper.h"
#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cursor_bound_check(int cursor_x, int cursor_y);

void color_init(){
  if (has_colors())
  {
    start_color();
    init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(2, COLOR_GREEN,   COLOR_BLACK);
    init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
    init_pair(4, COLOR_BLUE,    COLOR_BLACK);
    init_pair(5, COLOR_CYAN,    COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_WHITE,   COLOR_BLACK);
    init_pair(8, COLOR_WHITE,   COLOR_WHITE);
    init_pair(9, COLOR_BLACK,   COLOR_WHITE);
  }
}

void board_render(GameBoard* board) {
  // Character positoning relative
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char lit[2] = {board->boardGrid[i][j], '\0'};
      if (strcmp(lit,".") == 0) {
        attrset(COLOR_PAIR(3));
      }
      else if (strcmp(lit,"*") == 0) {
        attrset(COLOR_PAIR(2));
      }
      else if (strcmp(lit,"C") == 0) {
        attrset(COLOR_PAIR(6));
      }
      else if (strcmp(lit,"+") == 0) {
        attrset(COLOR_PAIR(9));
      }
      else if (strcmp(lit,"V") == 0) {
        attrset(COLOR_PAIR(4));
      }
      else if (strcmp(lit,"F") == 0) {
        attrset(COLOR_PAIR(5));
      }
      else {
        attrset(COLOR_PAIR(1));
      }
      mvaddstr((i + getmaxy(stdscr) / 2) - 7, (j + j + getmaxx(stdscr) / 2) - 9, lit);
    }
  }
  
  attrset(COLOR_PAIR(8));
  mvhline(getmaxy(stdscr)/2 - 10, getmaxx(stdscr)/2 - 11, '~', 21); //Hor above
  mvhline(getmaxy(stdscr)/2 - 11, getmaxx(stdscr)/2 - 11, '~', 21); //Hor above

  mvhline(getmaxy(stdscr)/2 - 8, getmaxx(stdscr)/2 - 11, '~', 21); //Hor above
  mvvline(getmaxy(stdscr)/2 - 7, getmaxx(stdscr)/2 - 10, '~', 9); // Ver in L
  mvvline(getmaxy(stdscr)/2 - 7, getmaxx(stdscr)/2 + 8, '~', 9); // Vert in R
  mvvline(getmaxy(stdscr)/2 - 7, getmaxx(stdscr)/2 - 11, '~', 9); // Vert out L
  mvvline(getmaxy(stdscr)/2 - 7, getmaxx(stdscr)/2 + 9, '~', 9); // Vert out R
  mvhline(getmaxy(stdscr)/2 + 2, getmaxx(stdscr)/2 - 11, '~', 21); // Hor below
  
  attrset(COLOR_PAIR(9));
  for (int i = 0; i < 9; i++) { // 1-9
     char num[2] = {48 + i, '\0'};
     mvaddstr(getmaxy(stdscr)/2 - 8, (i + i+ getmaxx(stdscr) / 2) - 9, num);
  }

  for (int i = 0; i < 9; i++) { // a-i
     char let[2] = {97 + i, '\0'};
     mvaddstr(i + getmaxy(stdscr)/2 - 7, getmaxx(stdscr)/2 - 11, let); 
  }

  mvaddstr(getmaxy(stdscr)/2 - 11, getmaxx(stdscr)/2 - 9, "CIV MAKER 20XX");
  mvaddstr(getmaxy(stdscr)/2 - 10, getmaxx(stdscr)/2 - 7, "Addison Teschan");
  
  //Right panel
    mvvline(getmaxy(stdscr)/2 - 8, getmaxx(stdscr)/2 + 12, ' ', 11); // Vert out R
    mvaddstr(getmaxy(stdscr)/2 - 7, getmaxx(stdscr)/2 + 13, "ARROW/HJKL ");
    mvaddstr(getmaxy(stdscr)/2 - 6, getmaxx(stdscr)/2 + 13, "Q END GAME ");
    mvaddstr(getmaxy(stdscr)/2 - 5, getmaxx(stdscr)/2 + 13, "R ROAD     ");
    mvaddstr(getmaxy(stdscr)/2 - 4, getmaxx(stdscr)/2 + 13, "V VILLAGE  ");
    mvaddstr(getmaxy(stdscr)/2 - 3, getmaxx(stdscr)/2 + 13, "F FARM     ");
    mvaddstr(getmaxy(stdscr)/2 - 2, getmaxx(stdscr)/2 + 13, "X DESTROY  ");
    
  // Bottom Panel
  char foodBuf[20];
  char intFood[5];
  char villBuf[20];
  char intVill[5];
  

  strcpy(foodBuf, " FOOD: ");
  sprintf(intFood,"%d",board->food);
  strcat(foodBuf, intFood);
  strcpy(villBuf, " VILLAGE: ");
  sprintf(intVill,"%d",board->villages);
  strcat(villBuf, intVill);
  mvaddstr(getmaxy(stdscr)/2 + 4, getmaxx(stdscr)/2 - 11, "                     ");
  mvaddstr(getmaxy(stdscr)/2 + 5, getmaxx(stdscr)/2 - 11, "                     ");

  mvaddstr(getmaxy(stdscr)/2 + 4, getmaxx(stdscr)/2 - 11, foodBuf);
  mvaddstr(getmaxy(stdscr)/2 + 5, getmaxx(stdscr)/2 - 11, villBuf);
  //Seperate food and village messages
}

void input_handle(int s, int* cursor_x, int* cursor_y, GameBoard* board) {
  switch(s) {
    case 'f': //FARM PLACEMENT - Recount Farm Reward
    if (is_next_to_building(board) == 1  && board->boardGrid[board->PlayerPosition.x][board->PlayerPosition.y] != 'C') {
      board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x] = 'F';
      tile_recount(board);
      board_render(board);
    }
    break;

    case 'v': //Villiage PLACEMENT - Recount Villages
    if (is_next_to_building(board) == 1 && is_next_to_village(board) == 0 && board->boardGrid[board->PlayerPosition.x][board->PlayerPosition.y] != 'C') {
      board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x] = 'V';
      tile_recount(board);
      board_render(board);
    }
    break;

    case 'r': //Road PLACEMENT
    if (is_next_to_building(board) == 1 && board->boardGrid[board->PlayerPosition.x][board->PlayerPosition.y] != 'C') {
      board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x] = '+';
      tile_recount(board);
      board_render(board);
    }
    break;

    case 'x': //DESTROY - Recount villages, Recount farm reward
    if (board->boardGrid[board->PlayerPosition.x][board->PlayerPosition.y] != 'C') {
      board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x] = board->OGboardGrid[board->PlayerPosition.y][board->PlayerPosition.x];
      tile_recount(board);
      board_render(board);
    }
    break;
  
    case ('j'):
    case (KEY_DOWN):
    if (cursor_bound_check(*cursor_x, *cursor_y + 2)) {
      *cursor_y += 1;
      move(*cursor_y, *cursor_x);
      board->PlayerPosition.y += 1;
    }
    break;

    case ('k'):
    case KEY_UP:
    if (cursor_bound_check(*cursor_x, *cursor_y - 1)) {
    *cursor_y -= 1;
      move(*cursor_y, *cursor_x);
       board->PlayerPosition.y -= 1;
      }
    break;

    case ('h'):
    case KEY_LEFT:
    if (cursor_bound_check(*cursor_x - 2, *cursor_y)) {
      *cursor_x -= 2;
      move(*cursor_y, *cursor_x - 1);
      board->PlayerPosition.x -= 1;
    }
    break;

    case ('l'):
    case KEY_RIGHT:
    if (cursor_bound_check(*cursor_x + 2, *cursor_y)) {
      *cursor_x += 2;
      move(*cursor_y, *cursor_x + 1);
      board->PlayerPosition.x += 1;
    }
    break;
    case 'q':
    board->end_flag = 1;
    break;
  }
    refresh();
}


int cursor_bound_check(int cursor_x, int cursor_y) {
  if (cursor_x < getmaxx(stdscr)/2 - 9) {
    return 0;
  }
  if (cursor_x > getmaxx(stdscr)/2 + 7) {
    return 0;
  }
  if (cursor_y < getmaxy(stdscr)/2 - 7) {
    return 0;
  }
  if (cursor_y > getmaxy(stdscr)/2 + 2) {
    return 0;
  }

  return 1;
}


void game_end(GameBoard *board) {
  if (board->food >= board->villages) {
    attrset(COLOR_PAIR(2));
    mvaddstr(getmaxy(stdscr)/2 - 4, getmaxx(stdscr)/2 - 20, "                YOU WON                 ");
    mvaddstr(getmaxy(stdscr)/2 - 3 , getmaxx(stdscr)/2 - 20, "               :)                       ");
  }
  else {
    attrset(COLOR_PAIR(1));
    mvaddstr(getmaxy(stdscr)/2 - 4, getmaxx(stdscr)/2 - 20, "                YOU LOST                 ");
    mvaddstr(getmaxy(stdscr)/2 - 3 , getmaxx(stdscr)/2 - 20, "           YOUR VILLAGE DIED :(          ");
  }
  refresh();
  for (;;) {
    
  }
}



