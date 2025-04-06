#define BOARD_ROWS 9
#define BOARD_COLS 9

//This file handles game logic. duh.

typedef struct PlayerPosition {
  int x;
  int y;
} PlayerPosition;

typedef struct GameBoard {
  char boardGrid[BOARD_ROWS][BOARD_COLS];
  char OGboardGrid[BOARD_ROWS][BOARD_COLS];
  PlayerPosition PlayerPosition;
  
  int food;
  int villages;
  int end_flag;

} GameBoard;

void board_randomize(GameBoard* board);
int is_next_to_building(GameBoard* board);
int is_next_to_village(GameBoard* board);
void tile_recount(GameBoard* board);
