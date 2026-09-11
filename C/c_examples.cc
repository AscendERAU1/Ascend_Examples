// c_examples.cc
/*
// File: c_examples.cc
// Author: Tommy Boston
// Date: 11/09/26
// 
// Compile 
// g++ c_examples.cc 
// 
//
//  Created for ASCEND! ERAU to teach new members how to code specifically C++
//  Shows basic functionality of C++ and fundemental coding skills
//
*/

// REQUIRED LIBRARY FOR C PROGRAMS
#include <stdio.h>

// Needed for string manipulations
#include <string.h>

// Custom Header file
#include "AzimuthFull.h"

// Custom function
void printTable()
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("        ~~~~~~~~\n");
    printf(" | \033[31m3\033[37m | \033[36m6\033[37m | \033[31m9\033[37m | \033[31m12\033[37m | \033[36m15\033[37m | \033[31m18\033[37m | \033[31m21\033[37m | \033[36m24\033[37m | \033[31m27\033[37m | \033[31m30\033[37m | \033[36m33\033[37m | \033[31m36\033[37m |");
    printf("       / \\ \033[31m1\033[37m  \033[36m2\033[37m/\\ \n");
    printf("-----------------------------------------------------------");
    printf("      / \033[32m0\033[37m \\   /\033[32m00\033[37m\\ \n");
    printf(" | \033[36m2\033[37m | \033[31m5\033[37m | \033[36m8\033[37m | \033[36m11\033[37m | \033[31m14\033[37m | \033[36m17\033[37m | \033[36m20\033[37m | \033[31m23\033[37m | \033[36m26\033[37m | \033[36m29\033[37m | \033[31m32\033[37m | \033[36m35\033[37m |");
    printf("     / \033[31m5\033[37m   \\ /  \033[36m10\033[37m\\ \n");
    printf("-----------------------------------------------------------");
    printf("    (~~~~~~~o~~~~~~) \n");
    printf(" | \033[31m1\033[37m | \033[36m4\033[37m | \033[31m7\033[37m | \033[36m10\033[37m | \033[36m13\033[37m | \033[31m16\033[37m | \033[31m19\033[37m | \033[36m22\033[37m | \033[31m25\033[37m | \033[36m28\033[37m | \033[36m31\033[37m | \033[31m34\033[37m |");
    printf("     \\ \033[31m7\033[37m   / \\   \033[31m9\033[37m/ \n");
    printf("-----------------------------------------------------------");
    printf("      \\ \033[36m8\033[37m /   \\ \033[36m4\033[37m/ \n");
    printf("|      | \033[32m0\033[37m | \033[32m00\033[37m | 1-12 | 12-24 | 24-36 | 1-18 | 19-36 |    |");
    printf("      \\ / \033[36m6\033[37m \033[31m3\033[37m \\/ \n");
    printf("-----------------------------------------------------------");
    printf("        ~~~~~~~~ \n");
    printf("|                  EVEN | \033[31mRED\033[37m | \033[36mBLUE\033[37m | ODD |               |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

// Custom functions with inputs
int plus(int num1, int num2)
{
    return num1 + num2;
}

int minus(int num1, int num2)
{
    return num1 - num2;
}

int multi(int num1, int num2)
{
    return num1 * num2;
}

int divid(int num1, int num2)
{
    if (num2 == 0)
    {
        printf("invalid operation");
        return 0;
    }
    else
    {
        return num1 / num2;
    }
}

// Custom function with char input
int manipulations(int num1, char op, int num2)
{
    int num3 = 0;
    if (op == '+')
    {
        num3 = plus(num1, num2);
    }
    else if (op == '-')
    {
        num3 = minus(num1, num2);
    }
    else if (op == 'x')
    {
        num3 = multi(num1, num2);
    }
    else if (op == '/')
    {
        num3 = divid(num1, num2);
    }
    printf(":%d\n", num3);
    return num3;
}

int main()
{

    // int is a number
    int counter = 0;
    int number;

    // Bool is a true or false otherwise known as a boolean
    bool statement = true;

    // Simple if statement
    if (statement == true)
    {
        number = rand() % 100;
        printf("Number is %d\n", number);
    }

    // Char type is usually text read until a null or enter
    char input[10];

    // Simple while loop
    while (statement == true)
    {

        printf("y/n");
        scanf("%s", input);

        if (strcmp(input, "y") == 0)
        {
            statement = true;
            counter++;
        }
        else if (strcmp(input, "n") == 0)
        {
            statement = false;
        }
        else
        {
            statement = false;
        }
    }

    // User input
    printf("Counting done adding ");
    printf("num1:%d num2:%d\n", number, counter);

    int added = plus(number, counter);
    printf("Added %d + % d = %d\n", number, counter, added);

    int num1, num2, num3 = 0;
    char op;

    printf("Type a full equation eg: 1+1, 2*2, 3/3 ,49-2 ");
    scanf("%d%c%d", &num1, &op, &num2);
    manipulations(num1, op, num2);

    static AzimuthResult output;

    float coordinate1[2] = {34.614716, -112.450387}; // Given Coords
    float coordinate2[2] = {33.24044, -112.03417};   // Pheonix
    float altitude1 = 4500.0;                        // given altitude
    float altitude2 = 70000;
    // Run custom header
    output = azmuth_Range(coordinate1, coordinate2, altitude1, altitude2);
    printf("S:%f\n",output.S);
    printf("Elevation Angle:%f deg\n",output.ElevationAngle);
    printf("Forward Azimuth:%f deg\n",output.ForwardAzimuth);   // degrees

    
    // Arrays
    int numtable[11], idx, idx2;
    // Simple for loop
    for (idx = 0; idx < 12; idx++)
    {
        numtable[idx] = idx + 1;
        printf("\n%d", numtable[idx]);
    }
    printf("\n%d", numtable[1]);
    printf("\n%d", numtable[2]);

    // Run custom function
    printTable();
}