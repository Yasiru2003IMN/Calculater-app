#include <stdio.h>

int main() {
    //variable declaration
    float num1, num2;
    char op;
    char choice;

    do {
        // header
        printf("\n--- Simple Calculator ---\n");

        //input
        printf("Enter first number: ");
        if (scanf("%f", &num1) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }

        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &op);

        printf("Enter second number: ");
        if (scanf("%f", &num2) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }

        printf("------------------------\n");

        switch(op) {
            case '+':
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                break;
            case '/':
                if(num2 != 0)
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                else
                    printf("Error: Division by zero is not allowed!\n");
                break;
            default:
                printf("Error: '%c' is not a valid operator.\n", op);
        }

        printf("------------------------\n");
        printf("Perform another calculation? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}
