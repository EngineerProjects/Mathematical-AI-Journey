#include <iostream>
#include <string>

/*
* This program demonstrates basic input and output in C++.
* It takes two numbers from the user, adds them, and displays the result.

* We have 4 streams: cin, cout, cerr, clog
* cin is used for input, cout for output, cerr for error messages, and clog for logging.
*/

int main() {
    // Prompt the user for their full name that  supports spaces
    std::cout << "Your Full Name: ";
    std::string fullName;
    std::getline(std::cin, fullName); // Read the full name from standard input
    // std::cin >> fullName; // Read the full name from standard input

    // Prompt the user for their age : cin don't support reading integers or string (datas) with spaces
    std::cout << "Your Age (in years): ";
    int age;
    std::cin >> age; // Read the age from standard input

    std::clog << "Logging: User's full name is " << fullName << " and age is " << age << std::endl;

    std::cout << "Hello, " << fullName 
                << "! You are " << age << " years old." << std::endl;

    // Example of error output
    if (age < 0) {
        std::cerr << "Error: Age cannot be negative!" << std::endl;
    }

    return 0;
}