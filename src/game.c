#include "tictactoe.h"

void initialize_board(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = ' ';
        }
    }
}

int check_win(const Game *game) {
    // 检查行和列
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] != ' ' && 
            game->board[i][0] == game->board[i][1] && 
            game->board[i][1] == game->board[i][2]) {
            return 1;
        }
        if (game->board[0][i] != ' ' && 
            game->board[0][i] == game->board[1][i] && 
            game->board[1][i] == game->board[2][i]) {
            return 1;
        }
    }
    
    // 检查对角线
    if (game->board[1][1] != ' ') {
        if ((game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2]) ||
            (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0])) {
            return 1;
        }
    }
    
    return 0;
}

int check_draw(const Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}