#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../inc/xo.h"

#pragma warning(disable:4996)

extern uint8_t gameBoard[9];
extern uint8_t configArray[2];


int main()
{
    uint8_t player, gameState, play = 'y';

    /* print rules and initial game state */
    printf("To play XO, 2 Players take turns putting their marks (x/o) in empty squares.\n");
    printf("The first player to fill a row, column or diagonal with his mark is the winner.\n");
    printf("When all 9 squares are full, the game is over and it's considered a draw.\n\n\n");

    /*********** Loop For Testing ***********/
    while (play == 'y')
    {
        player = 0;
        setPlayerConfig(configArray);
        drawBoard(gameBoard);

        for (uint8_t i = 0; i < 9; i++)
        {
            /* get position of the player-in-turn and update the board */
            loadAndUpdate(player);

            /* Display the current game board */
            drawBoard(gameBoard);

            getGameState(gameBoard, &gameState);

            if (gameState == gameDrawn)
            {
                printf("It's a draw!!\n");
                break;
            }
            else if (gameState == gameWon)
            {
                printf("Player %d won! Congratulations!\n", player + 1);
                break;
            }
            /* Toggle players */
            player = player ^ 1;
        }

        printf("\nDo you want to play again?\n");
        printf("(Press 'y' for yes or press any other key to exit)\n");
        scanf(" %c", &play);
        system("cls");
        resetGame(gameBoard);
    }

    return 0;
}