#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player_X_wins;
    int player_O_wins;
    int draws;
    int total_games;
} Game;

// 游戏核心函数
void initialize_board(Game *game);
int check_win(const Game *game);
int check_draw(const Game *game);

// 用户界面函数
void print_board(Game *game);
void get_player_input(int *row, int *col);
void show_statistic(const Game *game);
void show_instruction(Game *game);

// 游戏流程控制
void play_game(Game *game);
int main_menu(void);

// 辅助函数
void clear_input_buffer(void);

#endif