#include <iostream>

/*
* Integer Initialization in C++
* 
* There are three main ways to initialize integers in C++:
* 1. Copy Initialization: int n = value;    (most common, readable)
* 2. Direct Initialization: int n(value);   (less common for integers)
* 3. Brace Initialization: int n{value};    (safest, modern C++)
*
* Key Benefits of Brace Initialization:
* - Prevents narrowing conversions (losing data from decimals/large numbers)
* - Catches errors at compile time instead of runtime
* - More secure and recommended for modern C++
*
* This example demonstrates all three methods and shows where errors can occur.
*/

int main() 
{
    std::cout << "=== INTEGER INITIALIZATION EXAMPLES ===" << std::endl;
    
    // ========================================
    // 1. COPY INITIALIZATION (using =)
    // ========================================
    std::cout << "\n1. Copy Initialization (using =):" << std::endl;
    
    int age = 25;
    int score = 95;
    int year = 2024;
    int zero = 0;
    
    std::cout << "age = " << age << std::endl;
    std::cout << "score = " << score << std::endl;
    std::cout << "year = " << year << std::endl;
    std::cout << "zero = " << zero << std::endl;
    
    // ========================================
    // 2. DIRECT INITIALIZATION (using parentheses)
    // ========================================
    std::cout << "\n2. Direct Initialization (using parentheses):" << std::endl;
    
    int height(180);
    int weight(75);
    int temperature(72);
    int count(0);
    
    std::cout << "height = " << height << std::endl;
    std::cout << "weight = " << weight << std::endl;
    std::cout << "temperature = " << temperature << std::endl;
    std::cout << "count = " << count << std::endl;
    
    // ========================================
    // 3. BRACE INITIALIZATION (using curly braces)
    // ========================================
    std::cout << "\n3. Brace Initialization (using curly braces):" << std::endl;
    
    int students{30};
    int maxPoints{100};
    int currentLevel{5};
    int lives{3};
    
    // Special case: empty braces initialize to zero
    int defaultValue{};  // This becomes 0
    
    std::cout << "students = " << students << std::endl;
    std::cout << "maxPoints = " << maxPoints << std::endl;
    std::cout << "currentLevel = " << currentLevel << std::endl;
    std::cout << "lives = " << lives << std::endl;
    std::cout << "defaultValue = " << defaultValue << std::endl;
    
    // ========================================
    // 4. COPYING FROM OTHER VARIABLES
    // ========================================
    std::cout << "\n4. Copying from other variables:" << std::endl;
    
    int original = 42;
    int copy1 = original;    // Copy initialization
    int copy2(original);     // Direct initialization
    int copy3{original};     // Brace initialization
    
    std::cout << "original = " << original << std::endl;
    std::cout << "copy1 = " << copy1 << std::endl;
    std::cout << "copy2 = " << copy2 << std::endl;
    std::cout << "copy3 = " << copy3 << std::endl;
    
    // ========================================
    // 5. ARITHMETIC WITH DIFFERENT INITIALIZATION STYLES
    // ========================================
    std::cout << "\n5. Arithmetic examples:" << std::endl;
    
    int a = 10;
    int b(20);
    int c{30};
    
    int sum = a + b + c;
    int product{a * b};
    int difference(c - a);
    
    std::cout << "a + b + c = " << sum << std::endl;
    std::cout << "a * b = " << product << std::endl;
    std::cout << "c - a = " << difference << std::endl;
    
    // ========================================
    // 6. DANGEROUS EXAMPLES (COMMENTED OUT - UNCOMMENT TO TEST ERRORS)
    // ========================================
    std::cout << "\n6. Error examples (commented out):" << std::endl;
    
    // NARROWING CONVERSIONS - These work but lose data:
    // int lossy1 = 3.7;        // Becomes 3, loses .7 (no error with = and ())
    // int lossy2(3.9);         // Becomes 3, loses .9 (no error with = and ())
    
    // These will cause COMPILATION ERRORS (brace initialization prevents data loss):
    // int safe1{3.7};          // ERROR: narrowing conversion not allowed
    // int safe2{3.9};          // ERROR: narrowing conversion not allowed
    
    // LARGE NUMBERS - These might overflow without warning:
    // int overflow1 = 999999999999999;     // May become negative or wrong value
    // int overflow2(999999999999999);      // May become negative or wrong value
    
    // This will cause COMPILATION ERROR (brace initialization catches overflow):
    // int safe3{999999999999999};          // ERROR: value too large for int
    
    // UNINITIALIZED VARIABLES (bad practice):
    // int uninitialized;                   // Contains random garbage value
    // std::cout << uninitialized << std::endl;  // Undefined behavior!
    
    std::cout << "All error examples are commented out for safety." << std::endl;
    std::cout << "Uncomment them one by one to see the errors!" << std::endl;
    
    // ========================================
    // 7. BEST PRACTICES SUMMARY
    // ========================================
    std::cout << "\n=== BEST PRACTICES SUMMARY ===" << std::endl;
    std::cout << "For beginners: Use int name = value; (most readable)" << std::endl;
    std::cout << "For safety: Use int name{value}; (prevents errors)" << std::endl;
    std::cout << "Always initialize your variables!" << std::endl;
    
    return 0;
}