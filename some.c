#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculations.h"

int main() {
    struct MPG mpg[10];
    struct SimplePay sp[10];
    int mpgCount = 0, spCount = 0;
    int option;

    while (1) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Calc MPG\n");
        printf("2. Calc Simple Pay\n");
        printf("3. Save MPG to file\n");
        printf("4. Save Simple Pay Calc to file\n");
        printf("5. View MPG file\n");
        printf("6. View Simple Calc file\n");
        printf("7. Exit\n");
        printf("Choose: ");
        scanf("%d", &option);

        // Clear the input buffer
        while (getchar() != '\n');

        switch (option) {
            case 1:
                // Clear previous data before entering new set
                clearData(sp, mpg, &spCount, &mpgCount);
                calcMPG(&mpg[mpgCount]);
                mpgCount++;
                break;
            case 2:
                // Clear previous data before entering new set
                clearData(sp, mpg, &spCount, &mpgCount);
                calcSimplePay(&sp[spCount]);
                spCount++;
                break;
            case 3:
                saveMPG(mpg, mpgCount);
                break;
            case 4:
                saveSimplePay(sp, spCount);
                break;
            case 5:
                viewMPGFile();
                break;
            case 6:
                viewSimplePayFile();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}







