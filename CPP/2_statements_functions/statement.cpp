#include <iostream>

/*
* What are statements in C++?
* Statements in C++ are the building blocks of a program. 
* They represent actions or commands that the program executes.
* Each statement typically ends with a semicolon.
* Examples include variable declarations, assignments, function calls, and control flow statements.
* In this example, we will declare two integer variables and assign them values.

*/

int main() 
{
    int firstNumber = 12;
    int secondNumber = 8;

    int sum = firstNumber + secondNumber; // This is a statement that adds two numbers
    std::cout<< "The sum of " << firstNumber << " and " << secondNumber << " is: " << sum << std::endl;
    
    return 0;
}