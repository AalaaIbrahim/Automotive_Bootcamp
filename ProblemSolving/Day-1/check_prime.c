#include <stdio.h>

int main() {
    unsigned int num, prime;
    char loop = 'y';

    printf("This is a program to check whether a positive integer is a prime number.\n");

    while(loop == 'y'){
        printf("\nEnter a Number: ");
        scanf("%d", &num);

        while(num <= 0){
            printf("\nInvalid input! Please enter a positive number: ");
            scanf("%d", &num);
        }

        prime=1;

        for(int i=2; i<num; i++){
            if (!(num%i)) {
                prime = 0;
                printf("%d is not a prime number.\n\n", num);
                break;
            }
        }

        if(prime) {printf("%d is a prime number.\n\n", num);}

        printf("Do you want to check another number?\n(press 'y' for Yes or any other key to exit.)\n");
        scanf(" %c", &loop);

    }

    return 0;
}
