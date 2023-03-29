#ifndef STACK_H_
#define STACK_H_

#define     MAX_SIZE        10

#define     STACK_EMPTY     -2
#define     STACK_FULL      -1

typedef struct stack
{
    uint8_t elements[MAX_SIZE];
    int8_t top;
}ST_stack_t;

/*-----------------function prototypes-------------------*/
/**
 * @brief initializes the given stack as empty 
 * 
 * @param stack reference to the desired stack
 */
void stackInit(ST_stack_t* stack);

/**
 * @brief pushes data into the stack
 * 
 * @param stack reference to the desired stack
 * @param data the value to push in the stack
 * @return int8_t : -1: if the given stack is full
 *                   0: otherwise
 */
int8_t push(ST_stack_t *stack, uint8_t data);

/**
 * @brief pop the value on top of the stack
 * 
 * @param stack reference to the desired stack
 * @param data 
 * @return int8_t : -2: if the given stack is empty
 *                   0: otherwise 
 */
int8_t pop(ST_stack_t *stack, uint8_t *data);

/**
 * @brief prints all the stack data starting from the top
 * 
 * @param stack reference the stack to print 
 * @return int8_t : -2: if the given stack is empty
 *                  -1: if the given stack is full
 *                   0: otherwise
 */
int8_t printStack(ST_stack_t *stack);

/**
 * @brief Get the Stack Top object
 * 
 * @param stack reference to the desired stack
 * @param topData 
 * @return int8_t : -2: if the given stack is empty
 *                   0: otherwise 
 */
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);

/**
 * @brief 
 * 
 * @param stack reference to the desired stack 
 * @return int8_t : -1: if the given stack is full
 *                   0: otherwise
 */
int8_t isFull(ST_stack_t *stack);

/**
 * @brief Function to check if the stack is empty
 * 
 * @param stack reference to the desired stack
 * @return int8_t : -2: if the given stack is empty
 *                   0: otherwise 
 */
int8_t isEmpty(ST_stack_t *stack);

#endif