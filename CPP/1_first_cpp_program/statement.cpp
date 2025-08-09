/*
This program demonstrates the use of the main function in C++.
It includes the iostream library for input and output operations.
The main function prints the informations about me on the terminal output.
*/

#include <iostream>
#include <string>

int main() {
    std::string name = "Stephane Amiche";
    int age = 23;
    std::string occupation = "Big data engineer";

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Occupation: " << occupation << std::endl;

    return 0;
}