#include <stdio.h>

int main(void)
{
    int choice;

    while (1)
    {
        printf("Simple Calculator\n");
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("0) Quit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Bye!\n");
            break;
        }
        else if (choice == 1)
{
    int a, b;

    printf("A: ");
    scanf("%d", &a);

    printf("B: ");
    scanf("%d", &b);

    printf("Result: %d\n", a + b);
}
        else if (choice == 2)
        {
            int a, b;
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("Result: %d\n", a - b);
        }
        else if (choice == 3)
        {
            int a, b;
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("Result: %d\n", a * b);
        }
        else if (choice == 4)
        {
            int a, b;
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);

            if (b == 0)
                printf("Error: division by zero\n");
            else
                printf("Result: %d\n", a / b);
        }
    }

    return 0;
}
