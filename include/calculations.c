#include <stdio.h>
#include "calculations.h"


// Function Prototypes
void readString(const char* prompt, char* buffer, int size);
float readFloat(const char* prompt);
void updateMPG(struct MPG* mpg);
void calcMPG(struct MPG* mpg);
void calcSimplePay(struct SimplePay* sp);
void saveMPG(struct MPG* mpg, int count);
void saveSimplePay(struct SimplePay* sp, int count);
void viewMPGFile();
void viewSimplePayFile();
void clearData(struct SimplePay* sp, struct MPG* mpg, int* spCount, int* mpgCount);

// Basic Math Operations
float bg_add(float a, float b) { return a + b; }
float bg_sub(float a, float b) { return a - b; }
float bg_mult(float a, float b) { return a * b; }
float bg_div(float a, float b) {
    if (b == 0.0) {
        printf("Cannot divide by zero. Enter the numbers again.\n");
        return -1;
    }
    return a / b;
}

// Function to print calculation results
void print_result(char operation, float a, float b, float result) {
    printf("%.2f %c %.2f = %.2f\n", a, operation, b, result);
}

// Function to clear data for new data.
void clearData(struct SimplePay* sp, struct MPG* mpg, int *spCount, int *mpgCount) {
    // Clear SimplePay array and counter
    memset(sp, 0, sizeof(struct SimplePay) * (*spCount));
    *spCount = 0;

    // Clear MPG array and counter
    memset(mpg, 0, sizeof(struct MPG) * (*mpgCount));
    *mpgCount = 0;
}

// Function to read a string input from the user
void readString(const char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    strtok(buffer, "\n"); // Remove trailing newline if it exists
}

// Function to read a float input from the user
float readFloat(const char* prompt) {
    printf("%s", prompt);
    float value;
    scanf("%f", &value);

    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return value;
}

// Function to calculate MPG
void updateMPG(struct MPG* mpg) {
    mpg->mpg = bg_div(mpg->milesDriven, mpg->gasUsed);
}

// Function to calculate Pay
void updatePAY(struct SimplePay* sp) {
    sp->pay = bg_mult(sp->hourlyRate, sp->hoursWorked);
}

// Function to handle MPG calculations
void calcMPG(struct MPG* mpg) {
    readString("Enter Car Name: ", mpg->carName, sizeof(mpg->carName));
    readString("Enter Trip Name: ", mpg->tripName, sizeof(mpg->tripName));
    mpg->gasUsed = readFloat("Enter Gas Used: ");
    mpg->milesDriven = readFloat("Enter Miles Driven: ");
    updateMPG(mpg);

    printf("Car Name: %s, Trip Name: %s, Miles Driven: %.2f, Gas Used: %.2f, Calculated MPG: %.2f\n",
           mpg->carName, mpg->tripName, mpg->milesDriven, mpg->gasUsed, mpg->mpg);
}

// Function to calculate Simple Pay
void calcSimplePay(struct SimplePay* sp) {
    readString("Enter Employee Name: ", sp->empName, sizeof(sp->empName));
    sp->hourlyRate = readFloat("Enter Hourly Rate: ");
    sp->hoursWorked = readFloat("Enter Hours Worked: ");
    updatePAY(sp);
    
    printf("Employee Name: %s, Hours Worked: %.2f, Hourly Rate: $%.2f, Calculated Pay: $%.2f\n", 
           sp->empName, sp->hoursWorked, sp->hourlyRate, sp->pay);
}

// Function to save MPG calculations to a file
void saveMPG(struct MPG* mpg, int count) {
    // Open file in append mode
    FILE *file = fopen("mpg_results.txt", "a");
    
    // Check if file opening succeeded
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    
    // Loop through each MPG record and write to file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s|%.2f|%.2f|%.2f\n", 
                mpg[i].carName, mpg[i].tripName, 
                mpg[i].gasUsed, mpg[i].milesDriven, 
                mpg[i].mpg);
    }
    
    // Close the file
    fclose(file);
    
    // Output success message
    printf("Success: MPG data has been saved to mpg_results.txt.\n");
}

// Function to save Simple Pay calculations to a file
void saveSimplePay(struct SimplePay* sp, int count) {
    // Open file in append mode
    FILE *file = fopen("spc_results.txt", "a");

    // Check if file opening succeeded
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    // Loop through each Simple Pay record and write to file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%.2f|%.2f|%.2f\n", 
                sp[i].empName, sp[i].hourlyRate, 
                sp[i].hoursWorked, sp[i].pay);
    }

    // Close the file
    fclose(file);

    // Output success message
    printf("Simple Pay data saved.\n");
}

// Function to view saved MPG data from the file
void viewMPGFile() {
    // Open the file in read mode
    FILE *file = fopen("mpg_results.txt", "r");
    
    // Local variables to store read values
    char carName[50], tripName[50];
    float gasUsed, milesDriven, mpg;

    // Check if file opening succeeded
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    
    // Output header
    printf("\nMPG Data:\n");
    
    // Loop through each line in the file and print
    while (fscanf(file, "%[^|]|%[^|]|%f|%f|%f\n", carName, tripName, &gasUsed, &milesDriven, &mpg) != EOF) {
        printf("%s | %s | miles = %.2f | gallons = %.2f | mpg = %.2f\n", carName, tripName, milesDriven, gasUsed, mpg);
    }
    
    // Close the file
    fclose(file);
}

// Function to view saved Simple Pay data from the file
void viewSimplePayFile() {
    // Open the file in read mode
    FILE *file = fopen("spc_results.txt", "r");

    // Local variables to store read values
    char empName[50];
    float hourlyRate, hoursWorked, pay, totalPay;

    // Check if file opening succeeded
    if (file == NULL) {
        printf("Could not open file for reading.\n");
        return;
    }

    // Output header
    printf("\nSimple Pay Data:\n");

    // Loop through each line in the file and print
    while (fscanf(file, "%[^|]|%f|%f|%f\n", empName, &hourlyRate, &hoursWorked, &pay) != EOF) {
        printf("%s | hours worked = %.2f | hourly rate = $%.2f | pay = $%.2f\n", empName, hoursWorked, hourlyRate, pay);
        totalPay += pay; // Add the individual pay to totalPay   
    }
    // Print the Total Pay
    printf("Total Payroll: $%.2f\n", totalPay);

    // Close the file
    fclose(file);
}

