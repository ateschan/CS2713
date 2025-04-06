#include "logic.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

void board_randomize(GameBoard* board) {
  srand(time(NULL));
  for (int i = 0; i < BOARD_COLS; i++) {
    for (int j = 0; j < BOARD_ROWS; j++) {
      int trand = rand() % 100;
      if (trand <= 15) {
        board->boardGrid[i][j] = '*';
      }
    }
  }
}

//Helper function to determine legality of grid checking
int is_valid_pos(int x, int y) {
  if (x < 0 || x == BOARD_COLS || y < 0 || y == BOARD_ROWS) {
    return 0;
  }
  return 1; 
}

//Loop through adjecent tiles (udlr) must be next to at least one building
int is_next_to_building(GameBoard* board) {
  if (is_valid_pos(board->PlayerPosition.y - 1, board->PlayerPosition.x)) {
    if (board->boardGrid[board->PlayerPosition.y - 1][board->PlayerPosition.x] != '.' &&
      board->boardGrid[board->PlayerPosition.y - 1][board->PlayerPosition.x] != '*'){
      return 1;
    }  
  }
  if (is_valid_pos(board->PlayerPosition.y, board->PlayerPosition.x - 1)) {
    if (board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x - 1] != '.' && 
      board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x - 1] != '*'){
      return 1;
    }  
  }
  if (is_valid_pos(board->PlayerPosition.y + 1, board->PlayerPosition.x)) {
    if (board->boardGrid[board->PlayerPosition.y + 1][board->PlayerPosition.x] != '.' &&
      board->boardGrid[board->PlayerPosition.y + 1][board->PlayerPosition.x] != '*'){
      return 1;
    }  
  }
  if (is_valid_pos(board->PlayerPosition.y, board->PlayerPosition.x + 1)) {
    if (board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x + 1] != '.' &&
      board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x + 1] != '*'){
      return 1;
    }  
  }
  return 0;
}

//Loop through adjectent tiles (udlr) cannot be placed next to other villages 
//Must be next to at least one building
int is_next_to_village(GameBoard* board) {
  if (is_valid_pos(board->PlayerPosition.y - 1, board->PlayerPosition.x)) {
    if (board->boardGrid[board->PlayerPosition.y - 1][board->PlayerPosition.x] == 'V') {
      return 1;
    }  
  }
  if (is_valid_pos(board->PlayerPosition.y, board->PlayerPosition.x - 1)) {
    if (board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x - 1] == 'V') {
      return 1;
    }  
  }
  if (is_valid_pos(board->PlayerPosition.y + 1, board->PlayerPosition.x)) {
    if (board->boardGrid[board->PlayerPosition.y + 1][board->PlayerPosition.x] == 'V') {
      return 1;
    }  
  }
  if (is_valid_pos(board->PlayerPosition.y, board->PlayerPosition.x + 1)) {
    if (board->boardGrid[board->PlayerPosition.y][board->PlayerPosition.x + 1] == 'V') {
      return 1;
    }  
  }
  return 0;
}

//Loop through all tiles, count villages. -1 food per tile
//Must recount food tiles
//This is called on every placement. Inefficient but yeah.
void tile_recount(GameBoard* board) {
  board->villages = 0;
  board->food = 0;
  for (int j = 0; j < BOARD_ROWS; j++) {
    for (int i = 0; i < BOARD_COLS; i++) {
      if (board->boardGrid[i][j] == 'V') {
        board->villages += 1;
        board->food -= 1;
      }
      if (board->boardGrid[i][j] == 'F') {
        if (is_valid_pos(i - 1, j)) {
          if (board->boardGrid[i - 1][j] == '*') {
            board->food += 1;
          } 
        }
        if (is_valid_pos(i + 1, j)) {
          if (board->boardGrid[i + 1][j] == '*') {
            board->food += 1;
          } 
        }
        if (is_valid_pos(i, j - 1)) {
          if (board->boardGrid[i][j - 1] == '*') {
            board->food += 1;
          } 
        }
        if (is_valid_pos(i, j + 1)) {
          if (board->boardGrid[i][j + 1] == '*') {
            board->food += 1;
          } 
        }
      }
    }
  }
}


