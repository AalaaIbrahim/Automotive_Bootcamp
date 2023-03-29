#include <stdio.h>
#include <stdint.h>

#include "stack.h"

int main()
{
     uint8_t ST_top, ST_pop;
     /* 1. Create an empty stack */
     ST_stack_t stack;
     stack.top = -1;

     /* 2. Push 5 different characters to the stack */
     printf("Pushing 5 different characters to the stack (a->e):\n");
     for(int i=0; i<5; i++)
         {push(&stack, 'a'+i);}


     /* 3. Print all stack data */
     printStack(&stack);

     /* 4. Pop one character from the stack */
     printf("\nPopping one character from the stack\n\n");
     pop(&stack, &ST_pop);
     printf("popped: %c\n", ST_pop);

     /* 5. Print the stack's top */
     getStackTop(&stack, &ST_top);
     printf("Stack top: %c\n", ST_top);

     /* 6. Print all stack data */
     printStack(&stack);

     /* 7. Push another 7 different characters to the stack */
     printf("\nPushing 7 different characters to the stack (f->l):\n");
     for(int i=0; i<7; i++)
     {
         if (isFull(&stack) == STACK_FULL)
         {
             printf("Stack is full! pop first before pushing again!\n");
             break;
         }
         push(&stack, 'f'+i);
     }

     /* 8. Print the stack's top */
     getStackTop(&stack, &ST_top);
     printf("Stack top: %c\n", ST_top);

     /* 9. Print all stack data */
     printStack(&stack);

     /* 10. Pop 4 characters from the stack */
     printf("\nPopping 4 characters from the stack\n\n");
     printf("Popped: ");
     for(int i=0; i<4; i++)
     {
         pop(&stack, &ST_pop);
         printf("%c ", ST_pop);
     }

     /* 11. Print the stack's top */
     getStackTop(&stack, &ST_top);
     printf("\nStack top: %c\n", ST_top);

     /* 12. Print all stack data */
     printStack(&stack); 

     /* 13. Pop 7 more times from the stack */
     printf("\nPopping 7 characters from the stack\n\n");
     printf("Popped: ");
     for(int i=0; i<7; i++)
     {
         if (isEmpty(&stack) == STACK_EMPTY)
         {
             printf("\nStack empty!\n");
             break;
         }
        pop(&stack, &ST_pop);
        printf("%c ", ST_pop);
     }

     /* 14. Print the stack's top  */
     getStackTop(&stack, &ST_top);
     printf("Stack top: %c\n", ST_top);
    
     /* 15. Print all stack data */
     printf("printing stack data:\n");
     printStack(&stack);    

     while(1){}
}


