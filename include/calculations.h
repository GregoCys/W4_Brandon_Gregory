#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
struct MPG {
    char carName[50];
    char tripName[50];
    float gasUsed;
    float milesDriven;
    float mpg;
};

struct SimplePay {
    char empName[50];
    float hourlyRate;
    float hoursWorked;
    float pay;
};

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

// Basic Math Operations Prototypes
float bg_add(float a, float b);
float bg_sub(float a, float b);
float bg_mult(float a, float b);
float bg_div(float a, float b);

#endif
