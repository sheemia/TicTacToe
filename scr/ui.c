#include"tictactoe.h"

void print_board(Game *game)
{
    printf("\n  ");
    for(int i=0;i<BOARD_SIZE;i++)
    {
        printf("   %d",i+1);
    }
    printf("\n   ");
    for(int j=0;j<BOARD_SIZE;j++)
    {
        printf("+---");
    }
    printf("+\n");
    for(int k=0;k<BOARD_SIZE;k++)
    {
        printf(" %c",'A'+k);
        for(int m=0;m<BOARD_SIZE;m++)
        {
            printf(" | %c",game->board[k][m]);
        }
        printf(" |\n");
        printf("   ");
        for(int n=0;n<BOARD_SIZE;n++)
        {
            printf("+---");
        }
    printf("+\n");
    }
}

void get_player_input(int *row,int *col)
{
    char input[10];
    char row_char,col_char;

    while(1)
    {
        if(fgets(input,sizeof(input),stdin)==NULL)
        {
            printf("Error reading input.\n");
            printf("Please try again:");
            continue;
        }

        input[strcspn(input,"\n")]=0;

        if(strlen(input)!=2)
        {
            printf("Invalid input.\n");
            printf("Please enter exactly two characters(e.g.A1):");
            continue;
        }

        row_char=toupper(input[0]);
        col_char=input[1];

        if(row_char<'A'||row_char>'C')
        {
            printf("Invalid row'%c'.\n",input[0]);
            printf("Please enter A,B or C:");
            continue;
        }

        if(col_char<'1'||col_char>'3')
        {
            printf("Invalid column'%d'\n",input[1]);
            printf("Please enter 1,2 or 3:");
            continue;
        }

        *row=row_char-'A';
        *col=col_char-'1';
        return;
    }
}

void statistic(const Game *game)
{
    printf("\n   Game Statistic\n");
    printf("+---------------+---+\n");
    printf("|  Total Games  |%3d|\n",game->total_games);
    printf("+---------------+---+\n");
    printf("| Player X Wins |%3d|\n",game->player_X_wins);
    printf("| Player O Wins |%3d|\n",game->player_O_wins);
    printf("|     Draws     |%3d|\n",game->draws);
    printf("+---------------+---+\n");
}

void instruction(Game *game)
{
    printf("\nTHE INSTRUCTION OF THE GAME\n");
    printf("---------------------------\n");
    printf("1.The game is played on a 3x3 grid.\n");
    printf("2.Players take turns marking the square.\n");
    printf("3.Player X goes first, then player O.\n");
    printf("4.Enter moves using the grid references\n");

    print_board(game);

    printf("For example:To play in the center, enter 'B2'\n");
    printf("The first player to get 3 in a row wins!\n");
}

void clear_input_buffer()
{
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
}