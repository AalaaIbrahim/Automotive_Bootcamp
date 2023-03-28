
#define gameWon			0
#define gameDrawn		1

/*--------------------- function prototypes ------------------*/
/**
 * @brief prints the current game state to console
 * 
 * @param board a pointer to the array of the current game state
 */
void drawBoard(uint8_t *board);

/**
 * @brief updates the game board with each player's turn
 * 
 * @param board the current board
 * @param position the position where the player wants to place his symbol
 * @param value 'x' or 'o' (case insensetive)
 */
void updateBoard (uint8_t *board, uint8_t position, uint8_t value);

/**
 * @brief Get the Player Symbol object
 * 
 * @param playerNumber 
 * @param symbol 'x' or 'o' (case insensetive)
 * @return uint8_t  0: when the input symbol is not wrong and/or was not choosen before
 *                  1: when the input symbol is wrong and/or was choosen before
 */
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);

/**
 * @brief prompts players about their preferred symbols and save it in configArray
 * 
 * @param configArray pointer to the configArray
 */
void setPlayerConfig(uint8_t *configArray);

/**
 * @brief take player's number then load his config, asks him for the position then updates the board
 * 
 * @param playerNumber 
 */
void loadAndUpdate(uint8_t playerNumber);

/**
 * @brief Get the Game State object
 * 
 * @param board a pointer to the game board array
 * @param gameState 
 *                 0: for winning
 *                 1: for draw
 *                 2: for continue
 */
void getGameState(uint8_t *board, uint8_t *gameState);

/**
 * @brief Resets the game back to the initial state
 *        (for using the loop in testing)
 * @param board reference to the game board
 */
void resetGame(uint8_t* board);