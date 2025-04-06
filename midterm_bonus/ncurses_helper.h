#include "logic.h"


//This file both handles ncurses input and render utilites

void board_render(GameBoard* board);
void color_init();
void input_handle(int s, int* cursor_x, int* cursor_y, GameBoard* board);
void game_end(GameBoard* board);
