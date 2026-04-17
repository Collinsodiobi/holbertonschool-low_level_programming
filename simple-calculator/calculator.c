#include <stdio.h>

int main(void)
{
    int choice;
    int a, b;

    while (1)
    {
        printf("Simple Calculator\n");
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("0) Quit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1)
            return (1);

        if (choice == 0)
        {
            printf("Bye!\n");
            break;
        }

        printf("A: ");
        if (scanf("%d", &a) != 1)
            return (1);

        printf("B: ");
        if (scanf("%d", &b) != 1)
            return (1);

        if (choice == 1)
            printf("Result: %d\n", a + b);

        else if (choice == 2)
            printf("Result: %d\n", a - b);

        else if (choice == 3)
            printf("Result: %d\n", a * b);

        else if (choice == 4)
        {
            if (b == 0)
                printf("Error: division by zero\n");
            else
                printf("Result: %d\n", a / b);
        }

        else
            printf("Invalid choice\n");
    }

    return 0;
}
