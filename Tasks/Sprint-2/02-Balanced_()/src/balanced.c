#include <stdint.h>

#include "../inc/stack.h"
#include "../inc/balanced.h"

int8_t isBalancedParanthethes(uint8_t *expression)
{
    /* Create a new stack and initialize it as empty */
    ST_stack_t bracesST;
    stackInit(&bracesST);

    uint8_t val, neither = 1, n = 0;
    int8_t ST_checkEmpty;

    while ((expression[n] != '\0'))
    {
        /* Push any open parenthesis into the stack */
        if (expression[n] == '(' || expression[n] == '{')
        {
            neither = 0;
            push(&bracesST, expression[n]);
        }
        else if (expression[n] == ')')
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
        else if (expression[n] == '}')
        {
            neither = 0;
            ST_checkEmpty = pop(&bracesST, &val);
            if (val != '{' || ST_checkEmpty == -2)
            {
                /* push it back to make sure stack is not empty*/
                push(&bracesST, expression[n]);
                break;
            }
        }
        n++;
    }

    if (neither)
        return -2;

    if (isEmpty(&bracesST) == STACK_EMPTY)
        return 0;

    return -1;
}