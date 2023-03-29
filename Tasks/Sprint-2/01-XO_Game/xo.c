#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../inc/xo.h"


#pragma warning(disable:4996)

uint8_t gameBoard[9] = { '1','2','3',
                        '4','5','6',
                        '7','8','9' };

uint8_t configArray[2] = {0};

/* All possible winning combinations for a symbol */
static uint8_t winningStates[8][3] = {{0,1,2}, {3,4,5}, {6,7,8},
                                      {0,3,6}, {1,4,7}, {2,5,8},
                                      {0,4,8}, {2,4,6}};

/* The total number of taken positions on the game board */
static uint8_t busyCount = 0;

/**
 * @brief prints the current game state to console
 * 
 * @param board a pointer to the array of the current game state
 */
void drawBoard(uint8_t *board)
{
    printf(" _______________________\n");
    printf("|       |       |       |\n");
    for(uint8_t i=0; i<9; i++)
    {
        printf("|");
        switch(board[i])
        {
            /* display 'x's in green */
            case 'x': printf("\033[0;32m");
                      printf("   x   ");
                      break;

            /* display 'o's in blue */
            case 'o': printf("\033[0;34m");
                      printf("   o   ");
                      break;
            default:  printf("   %c   ", board[i]);
        }
        printf("\033[0m");

        if((i+1)%3 == 0) {
            printf("|\n|_______|_______|_______|\n");
            if(i == 8) break;
            printf("|       |       |       |\n");
        }
    }
    printf("\n");
}

/**
 * @brief updates the game board with each player's turn
 * 
 * @param board the current board
 * @param position the position where the player wants to place his symbol
 * @param value 'x' or 'o' (case insensetive)
 */
void updateBoard (uint8_t *board, uint8_t position, uint8_t value)
{
    /* Update the game board */
    board[position-1] = value;
}

/**
 * @brief Get the Player Symbol object
 * 
 * @param playerNumber 
 * @param symbol 'x' or 'o' (case insensetive)
 * @return uint8_t  0: when the input symbol is not wrong and/or was not choosen before
 *                  1: when the input symbol is wrong and/or was choosen before
 */
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol)
{
        /* get the symbol from player */
        scanf(" %c", symbol);

        /* Check that the symbol is valid */
        if (((*symbol != 'x') && (*symbol != 'X') && (*symbol != 'o') && (*symbol != 'O'))
            || (playerNumber==2 && *symbol==configArray[0]))
        {
            return 1;
        }
        
        if(*symbol == 'X') *symbol = 'x';
        if(*symbol == 'O') *symbol = 'o';

        return 0;    
}

/**
 * @brief prompts players about their preferred symbols and save it in configArray
 * 
 * @param configArray pointer to the configArray
 */
void setPlayerConfig(uint8_t *configArray)
{
    printf("Player 1, Enter your preferred symbol (x / o): ");
    while(getPlayerSymbol(1, &configArray[0])){
        printf("Player 1, Invalid symbol! please enter 'x' or 'o': ");
    }

    printf("\nPlayer 2, Enter your preferred symbol (x / o): ");
    while(getPlayerSymbol(2, &configArray[1])){
        if(configArray[0] == 'x')
            printf("Player 2, Invalid symbol! please enter 'o': ");
        else
            printf("Player 2, Invalid symbol! please enter 'x': ");
    }
    system("cls");
}

/**
 * @brief take player's number then load his config, asks him for the position then updates the board
 * 
 * @param playerNumber 
 */
void loadAndUpdate(uint8_t playerNumber)
{
    int position;
    /* Prompt the player for where he wants to play */
    printf("Player %d, Where do you want to play? ", playerNumber+1);

    /* Check if the position is already taken or out of range, prompt the player to enter it again*/
    while((scanf("%i", &position)!=1 && scanf("%*[^\n]") == 0) || 'x' == gameBoard[position-1] || 'o' == gameBoard[position-1] || position > 9 || position < 1)
    {
        printf("\033[0;31mInvalid position! Pick another one:\033[0m ");
    }

    /* Update the board with the player's turn */
    updateBoard(gameBoard, position, configArray[playerNumber]);

    /* Increment the number of busy positions */
    busyCount++;

    system("cls");
}

/**
 * @brief check if there is a winning, draw, or continue playing
 * 
 * @param gameState 
 *                 0: for winning
 *                 1: for draw
 *                 2: for continue
 */
void getGameState(uint8_t *board, uint8_t *gameState)
{
    for(uint8_t i=0; i<8; i++)
    {
        /* Check if all the elements in the row/column/diagonal are equal */
        if(board[winningStates[i][0]]==board[winningStates[i][1]] && board[winningStates[i][0]]==board[winningStates[i][2]])
        {
            *gameState = 0;
            return;
        }
    }
    
    /* if all the positions are busy and no winning state is satisfied, it's a draw */
    if(9 == busyCount) {
        *gameState = 1;
        return;
    }

    *gameState =  2;
}


/**
 * @brief Resets the game back to the initial state
 *        (for using the loop in testing)
 * @param board reference to the game board
 */
void resetGame(uint8_t* board)
{
    busyCount = 0;

    for (uint8_t i = 0; i < 9; i++) {
        board[i] = i + 1 + '0';
    }
}