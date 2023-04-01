#include "../inc/main.h"

int main()
{
    uint8_t another = LOOP_AGAIN;
    uint8_t text[150];

    while (another == LOOP_AGAIN)
    {
        system("cls");
        printf("This program checks whether all occurences of () & {} are balanced\n");
        printf("\nEnter the sentence: \n");
        scanf("%[^\n]%*c", text);

        int8_t result = isBalancedParanthethes(text);

        switch (result)
        {
        case ALL_BALANCED:
            printf("\nAll the braces and/or curly braces in the text are balanced.\n");
            break;

        case UNBALANCED:
            printf("\nThe braces and curly braces in the text are unbalanced.\n");
            break;

        case NO_PARENTHESES:
            printf("\nThe entered text has neither braces nor curly braces.\n");
            break;

        default:
            break;
        }

        printf("\nCheck another sentence?\n");
        printf("Press 'y' for yes and any other key to exit.\n");
        another = getchar();
        getchar();
    }
}
