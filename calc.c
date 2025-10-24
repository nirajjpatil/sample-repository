#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int choice;
    double x, y;
    long long xi, yi;

    while (1) {
        printf("\nSimple Calculator\n");
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("5) Modulo (integers)\n");
        printf("6) Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Exiting.\n");
            return 1;
        }

        if (choice == 6) break;

        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers separated by space: ");
            if (scanf("%lf %lf", &x, &y) != 2) {
                fprintf(stderr, "Invalid numbers. Exiting.\n");
                return 1;
            }
            switch (choice) {
                case 1:
                    printf("%g + %g = %g\n", x, y, x + y);
                    break;
                case 2:
                    printf("%g - %g = %g\n", x, y, x - y);
                    break;
                case 3:
                    printf("%g * %g = %g\n", x, y, x * y);
                    break;
                case 4:
                    if (y == 0) {
                        printf("Error: Division by zero.\n");
                    } else {
                        printf("%g / %g = %g\n", x, y, x / y);
                    }
                    break;
            }
        } else if (choice == 5) {
            printf("Enter two integers separated by space: ");
            if (scanf("%lld %lld", &xi, &yi) != 2) {
                fprintf(stderr, "Invalid integers. Exiting.\n");
                return 1;
            }
            if (yi == 0) {
                printf("Error: Modulo by zero.\n");
            } else {
                printf("%lld %% %lld = %lld\n", xi, yi, xi % yi);
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }

        /* consume leftover newline or non-numeric input to avoid infinite loop */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("Goodbye.\n");
    return 0;
}