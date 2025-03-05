// Copyright (c) 2025 Jack Turcotte All rights reserved.
//
// Created by: Jack Turcotte
// Date: February 26, 2025
// This program calculates the area and circumference of
// a circle using a modified version of archimedes' pi
// approximation based on user input

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

// array to store startup messages

const float RADIAN = M_PI / 180;

const std::string MESSAGES_TO_PRINT[4] = {
    "Welcome to Jack's Pi Approximation tool, \n"
    "a tool used for approximating pi and calculating \n"
    "the circumference and area of a circle from it.\n",

    "To start, please enter the approximation for pi \n"
    "(3-1,000,000 and must be an integer):",

    "Now please enter your radius (cm - float number):\n",

    "How many decimals do you want to round it to? (Integer 1-12)\n"};

int main() {
    std::cout << std::fixed << std::setprecision(100000000);
    int iterations = 1000000;
    double piApprox;
    float radius;
    int roundTo;
    float marginOfError;

    // Display startup messages
    for (int i = 1; i <= 4; i++) {
        // Print message at i index
        std::cout << MESSAGES_TO_PRINT[i - 1] << std::endl;  

        if (i == 2) {
            std::cin >> iterations;  // Ask for pi approx iterations
        }
        if (i == 3) {
            std::cin >> radius;  // Ask for radius
        }
        if (i == 4) {
            std::cin >> roundTo;  // Ask for round to place
        }
    }

    // Calculate pi approximation
    if (iterations 
        and iterations >= 3 
        and iterations <= 1000000 
    ) {
        // we add a lot of decimal places so that
        // it doesn't round down to 0

        float innerAng = 360.000000 / iterations;
        float outerAng = (180.000000 - innerAng) / 2.000000;
        float outerSideLength = sin(RADIAN * innerAng) / sin(RADIAN * outerAng);
        piApprox = outerSideLength * (iterations) / 2;
    } else {
        piApprox = 0;
    }

    if (piApprox > 0) {
        marginOfError = (100 * (M_PI / piApprox) - 100);  // Margin of error as num from 0 - 100
        float circumference = 2 * piApprox * radius;      // circumference of your circle
        float area = piApprox * pow(radius, 2);           // circumference of your circle
        std::cout << std::fixed << std::setprecision(roundTo);

        std::cout << "The circumference of your circle is " << circumference << "cm" << std::endl;
        std::cout << "The area of your circle is " << area << "cm^2" << std::endl;
        std::cout << "The margin of error for your approximation was: " << marginOfError << "%" << std::endl;
    } else {
        std::cout << "Please enter valid numbers!" << std::endl;
        main();
    }
}
