#include <iostream>

consteval int getValue() {
    return 42;
}

int main() {
    constexpr int value = getValue();
    std::cout << "The value is: " << value << std::endl;

    // Demystify how cout and endl work
    std::cout << "This is a cout usage with endl." << std::endl;
    std::cout << "This is a cout usage without endl.";
    std::cout << " Continuing on the same line.\n" << std::flush;

    /*
    The above code demonstrates the use of `consteval` to compute a value at compile time,
    and how to use `std::cout` for output. 
    The `std::endl` manipulator flushes the output buffer (which means it forces the output to be written immediately and adds a newline),
    while `std::flush` can be used to flush without adding a newline.
    This is a simple C++ program that adheres to the C++23 standard.
    */

    return 0;
}
