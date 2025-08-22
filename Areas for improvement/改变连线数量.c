\\把“硬编码的 0、1、2”全部换成变量，用双重循环扫描任意行列、对角线即可。
\\下面给出一份可扩展版  check_win ，你只需改两个宏就能适配任意棋盘大小与连珠数：


#define BOARD_SIZE  5          // 棋盘边长
#define LINE_LEN    4          // 需要连成多少个才赢

int check_win(const Game *game, char player)
{
    /* 1. 检查所有行、列 */
    for (int i = 0; i < BOARD_SIZE; ++i) {
        int rowCnt = 0, colCnt = 0;
        for (int j = 0; j < BOARD_SIZE; ++j) {
            rowCnt = (game->board[i][j] == player) ? rowCnt + 1 : 0;
            colCnt = (game->board[j][i] == player) ? colCnt + 1 : 0;
            if (rowCnt == LINE_LEN || colCnt == LINE_LEN) return 1;
        }
    }

    /* 2. 检查主对角线方向（↘） */
    for (int r = 0; r <= BOARD_SIZE - LINE_LEN; ++r)
        for (int c = 0; c <= BOARD_SIZE - LINE_LEN; ++c) {
            int cnt = 0;
            for (int k = 0; k < LINE_LEN; ++k)
                if (game->board[r + k][c + k] == player) ++cnt;
            if (cnt == LINE_LEN) return 1;
        }

    /* 3. 检查副对角线方向（↙） */
    for (int r = 0; r <= BOARD_SIZE - LINE_LEN; ++r)
        for (int c = LINE_LEN - 1; c < BOARD_SIZE; ++c) {
            int cnt = 0;
            for (int k = 0; k < LINE_LEN; ++k)
                if (game->board[r + k][c - k] == player) ++cnt;
            if (cnt == LINE_LEN) return 1;
        }

    return 0;
}


\\使用方式
\\把  BOARD_SIZE  改成 3、4、5…
\\把  LINE_LEN  改成 3、4、5…
\\其余代码 无需再改任何数字。
\\核心思路
\\“滑动窗口”：用连续计数器  cnt  在行列或对角线上滑动，只要出现  LINE_LEN  个相同符号就赢。
\\双循环 + 宏：所有索引、边界、步长全部由变量和宏控制，彻底告别手写 0/1/2。