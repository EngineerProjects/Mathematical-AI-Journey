#include <iostream>

/*
* What are functions in C++?
* Functions in C++ are reusable blocks of code that perform a specific task.
* They can take inputs (parameters) and return outputs (return values).
* Functions help organize code, making it more modular and easier to maintain.
*/

int addNumbers(int firstNumber, int secondNumber) {
    return firstNumber + secondNumber; // This function returns the sum of two numbers
}

int main() {
    int firstNumber {12};
    int secondNumber {8};

    int sum = addNumbers(firstNumber, secondNumber); // This is a function call that adds two numbers
    std::cout << "The sum of " << firstNumber << " and " << secondNumber << " is: " << sum << std::endl;

    // Direct usage

    std::cout << "Directly adding 5 and 10 gives: " << addNumbers(5, 10) << std::endl; // Direct function call

    return 0;
}