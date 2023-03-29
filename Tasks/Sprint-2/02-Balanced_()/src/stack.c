#include <stdio.h>
#include <stdint.h>

#include "../inc/stack.h"

void stackInit(ST_stack_t* stack)
{
    /* Initialize the stack as empty */
    stack->top = -1;
}

int8_t push(ST_stack_t *stack, uint8_t data)
{
    /* Check if the stack is full */
    if(stack->top == MAX_SIZE-1) return STACK_FULL;
    
    stack->top++;
    stack->elements[stack->top] = data;
    
    return 0;
}

int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    /* Check if the stack is empty */
    if(stack->top == -1) return STACK_EMPTY;
    
    *data = stack->elements[stack->top];
    stack->top--;

    return 0;
}

/**
 * @brief prints all the stack data starting from the top
 * 
 * @param stack the stack to print 
 * @return int8_t : -2: if the given stack is empty
 *                  -1: if the given stack is full
 *                   0: otherwise
 */
int8_t printStack(ST_stack_t *stack)
{
    /* Check if stack is empty */
    if(stack->top == -1) return STACK_EMPTY;
    int8_t n = stack->top;

    while (n >= 0)
    {
        printf("%c\n", stack->elements[n]);
        n--;
    }
    printf("\n");
    
    /* Check if stack is full */
    if(stack->top == MAX_SIZE-1) return STACK_FULL;

    return 0;
}

int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    if (stack->top == -1) {
        *topData = NULL;
        return STACK_EMPTY;
    }

    *topData = stack->elements[stack->top];

    return 0;    
}

int8_t isFull(ST_stack_t *stack)
{
    /* Check if stack is full */
    if(stack->top == MAX_SIZE-1) return STACK_FULL;

    return 0;    
}

int8_t isEmpty(ST_stack_t *stack){
    if (stack->top == -1) return STACK_EMPTY;
    return 0;
}
