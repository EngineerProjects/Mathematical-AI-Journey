#include <iostream>

/*
We call main() a "main function" because it is the entry point of the program.
It is where the execution of the program begins.
In C++, the main function must return an integer value, typically 0 to indicate successful execution.
This is a requirement of the C++ language standard, including C++23.
*/

/*
Commenting in C++ is done using // for single-line comments and /* for multi-line comments.
Generally, comments are used to explain the code, making it easier to understand. 
That's mean we can't see comments in the compiled code.
*/

int main() {
    // One line comment: This is the main function of the program.

    /**
     * Multi-line comment: This program prints "Hello, World!" to the console.
     * Another line
     * Oh! And one more line.
     */
    std::cout << "Hello, World!" << std::endl;
    
    return 0;
}
