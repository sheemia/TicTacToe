#include "tictactoe.h"

int main_menu()
{
    int choice;
    printf("\nTIC-TAC-TOE GAME\n");
    printf("================\n");
    printf("1.Play Game\n");
    printf("2.View Instruction\n");
    printf("3.View Statistic\n");
    printf("4.Exit\n");
    printf("Please enter the number:");

    while(1)
    {
        if((scanf("%d",&choice))!=1)
        {
            clear_input_buffer();
            printf("Invalid input!\n");
            printf("Please enter the correct number:");
            continue;
        }

        if(choice>=1&&choice<=4)
        {
            clear_input_buffer();
            return choice;
        }
        else
        {
            clear_input_buffer();
            printf("Invalid input!\n");
            printf("Please enter the correct number(1~4):");
        }
    }
}

void play_game(Game *game)
{
    char player='X';
    int game_over=0;
    int row,col;

    initialize_board(game);
    game->total_games++;

    printf("\nA new game started!\n");
    printf("player 'X' goes first\n\n");

    while(!game_over)
    {
        print_board(game);

        printf("Player %c ,enter your move(e.g.A1):",player);

        get_player_input(&row,&col);

        if(game->board[row][col]!=' ')
        {
            printf("Position %c%c is already taken.\n",'A'+row,'1'+col);
            printf("Please choose another.\n");
            continue;
        }

        game->board[row][col]=player;
        
        if(check_win(game))
        {
            print_board(game);
            printf("\n******************\n");
            printf("  Player %c wins! \n",player);
            printf("Congratulations!!!\n");
            printf("******************\n");

            if(player=='X')
            {
                game->player_X_wins++;
            }
            else
            {
                game->player_O_wins++;
            }

            game_over=1;
        }
        else if(check_draw(game))
        {
            print_board(game);
            printf("\n****************\n");
            printf(" It's a draw!!! \n");
            printf("****************\n");

            game->draws++;

            game_over=1;
        }
        else
        {
            player=(player=='X')?'O':'X';
        }
    }
    statistic(game);
}

int main()
{
    Game game={0};
    initialize_board(&game);
    int choice;

    printf("Welcome to Tic-Tac-Toe!\n");

    while(1)
    {
        choice=main_menu();
        switch(choice)
        {
            case 1:
            play_game(&game);
            break;

            case 2:
            instruction(&game);
            break;

            case 3:
            statistic(&game);
            break;

            case 4:
            printf("Thank you for playing Tic-Tac-Toe!");
            return 0;
        }
        printf("\nPress Enter to return the main menu...");
        getchar();
    }
    return 0;
}