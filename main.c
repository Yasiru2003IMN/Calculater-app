#include <stdio.h>

// Function declarations to keep main() clean
void clear_input_buffer(void);
float get_number_input(const char *prompt);
char get_operator_input(void);

int main() {
    char choice;

    do {
        printf("\n=== Simple Calculator ===\n");

        // Get robust inputs using specialized functions
        float num1 = get_number_input("Enter first number: ");
        char op = get_operator_input();
        float num2 = get_number_input("Enter second number: ");

        printf("------------------------\n");

        // Calculate and display result
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
                if (num2 != 0.0f) {
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                } else {
                    printf("Error: Division by zero is not allowed!\n");
                }
                break;
            default:
                printf("Error: Unexpected operator state.\n");
        }

        printf("------------------------\n");
        printf("Perform another calculation? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}

// Clears remaining characters in input buffer to prevent infinite loops
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Repeatedly asks for a number until a valid float is entered
float get_number_input(const char *prompt) {
    float num;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &num) == 1) {
            return num;
        }
        printf("Invalid input! Please enter a valid number.\n");
        clear_input_buffer();
    }
}

// Repeatedly asks for an operator until a valid one (+, -, *, /) is provided
char get_operator_input(void) {
    char op;
    while (1) {
        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &op);

        if (op == '+' || op == '-' || op == '*' || op == '/') {
            return op;
        }
        printf("Invalid operator! Try again.\n");
    }
}
