
////////////////////////////////////////
// Brandon Gregory                    //
// CSCI140 C001 Summer 2023           //
// Instructor name: Dr. Frank Appiah  //
// Week #: Week 4                     //
// Date completed: 09/07/2023         //
////////////////////////////////////////
//                                    //
// How-to Instructions in README.txt  //
//                                    //
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"
#include "calculations.c"

void print_result(char op, float num1, float num2, float result);

int main() {

    char selection;
    float num1, num2, result;
    char name[50];
    struct MPG mpg[50];
    struct SimplePay sp[50];
    int mpgCount = 0, spCount = 0;

    printf("Enter your name: ");
    scanf("%s", name);

    do {
        printf("\nMenu:\n");
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("5) Calc MPG\n");
        printf("6) Calc Simple Pay\n");
        printf("7) Save MPG to file\n");
        printf("8) Save Simple Pay Calc to file\n");
        printf("9) View MPG file\n");
        printf("v) View Simple Calc file\n");
        printf("q) Exit\n");
        printf("Choose: ");

        scanf(" %c", &selection);

        // Clear the input buffer
        while (getchar() != '\n');

        if (selection >= '1' && selection <= '4') {
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
        }

        switch (selection) {
            case '1' :
                result = bg_add(num1, num2);
                print_result('+', num1, num2, result);
                break;
            case '2' :
                result = bg_sub(num1, num2);
                print_result('-', num1, num2, result);
                break;
            case '3' :
                result = bg_mult(num1, num2);
                print_result('*', num1, num2, result);
                break;
            case '4' :
                if (num2 == 0) {
                    printf("Cannot divide by zero. Enter the second number again: ");
                    scanf("%f", &num2);
                    continue;
                }
                result = bg_div(num1, num2);
                print_result('/', num1, num2, result);
                break;
            case '5':
                // Clear previous data before entering new set
                clearData(sp, mpg, &spCount, &mpgCount);
                calcMPG(&mpg[mpgCount]);
                mpgCount++;
                break;
            case '6':
                // Clear previous data before entering new set
                clearData(sp, mpg, &spCount, &mpgCount);
                calcSimplePay(&sp[spCount]);
                spCount++;
                break;
            case '7':
                saveMPG(mpg, mpgCount);
                break;
            case '8':
                saveSimplePay(sp, spCount);
                break;
            case '9':
                viewMPGFile();
                break;
            case 'v':
                viewSimplePayFile();
                
                break;
            case 'q':
                printf("%s, thank you for using my application.\n", name);
                printf("Press any key to close...");
                getchar();
                exit(0);
            default:
                printf("Invalid option\n");
        }

    } while(1);

    return 0;
}