#ifndef BALANCED_H_
#define BALANCED_H_

#define ALL_BALANCED         0
#define UNBALANCED          -1
#define NO_PARENTHESES      -2


/**
 * @brief takes an expression and checks if all the parentheses in it are balanced
 *         (only checks on "()" and "{}")
 * @param expression reference to the text to evaluate
 * @return int8_t  NO_PARENTHESES: expression has neither braces nor curly braces
 *                 UNBALANCED: expression has unbalanced parentheses
 *                 ALL_BALANCED: all parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t *expression);

#endif