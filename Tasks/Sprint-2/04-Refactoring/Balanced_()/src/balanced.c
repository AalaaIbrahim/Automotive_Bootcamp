#include <stdint.h>

#include "../inc/stack.h"
#include "../inc/balanced.h"

int8_t isBalancedParanthethes(uint8_t *expression)
{
    /* Create a new stack and initialize it as empty */
    ST_stack_t bracesST;
    stackInit(&bracesST);

    uint8_t val, neither = 1, Local_CharIterator = 0;
    int8_t ST_checkEmpty;

    while ((expression[Local_CharIterator] != '\0'))
    {
        /* Push any open parenthesis into the stack */
        if (expression[Local_CharIterator] == '(' || expression[Local_CharIterator] == '{')
        {
            neither = 0;
            push(&bracesST, expression[Local_CharIterator]);
        }
        else if (expression[Local_CharIterator] == ')')
        {
            neither = 0;
            ST_checkEmpty = pop(&bracesST, &val);
            /* Check that stack top is an open parenthesis of the same type*/
            if (val != '(' || ST_checkEmpty == -2)
            {
                /* push it back to make sure stack is not empty*/
                push(&bracesST, val);
                break;
            }
        }
        else if (expression[Local_CharIterator] == '}')
        {
            neither = 0;
            ST_checkEmpty = pop(&bracesST, &val);
            if (val != '{' || ST_checkEmpty == -2)
            {
                /* push it back to make sure stack is not empty*/
                push(&bracesST, expression[Local_CharIterator]);
                break;
            }
        }
        Local_CharIterator++;
    }

    if (neither)
        return NO_PARENTHESES;

    if (isEmpty(&bracesST) == STACK_EMPTY)
        return ALL_BALANCED;

    return UNBALANCED;
}