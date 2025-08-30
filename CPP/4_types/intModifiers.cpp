#include <iostream>
#include <climits>  // For INT_MAX, INT_MIN, etc.

/*
* Integer Modifiers in C++
* 
* Integer modifiers change the size and/or sign properties of integer types:
* 
* SIZE MODIFIERS:
* - short int (or just 'short'): Usually 16 bits, smaller range
* - int: Usually 32 bits, standard size
* - long int (or just 'long'): Usually 32 or 64 bits, larger range
* - long long int (or just 'long long'): Usually 64 bits, largest range
*
* SIGN MODIFIERS:
* - signed: Can store positive and negative numbers (default for int)
* - unsigned: Can only store positive numbers (and zero), but larger positive range
*
* COMBINATIONS:
* You can combine size and sign modifiers like: unsigned long, signed short, etc.
*
* KEY BENEFITS:
* - Choose the right size for memory efficiency
* - Use unsigned when you know values are always positive
* - Prevent overflow by choosing appropriate ranges
*/

int main() 
 {
    std::cout << "=== INTEGER MODIFIERS EXAMPLES ===" << std::endl;
    
    // ========================================
    // 1. SIZE MODIFIERS - Different Sizes
    // ========================================
    std::cout << "\n1. Size Modifiers (Different Memory Sizes):" << std::endl;
    
    short shortNum = 32000;           // Usually 16 bits
    int normalNum = 2000000000;       // Usually 32 bits  
    long longNum = 2000000000L;       // Usually 32 or 64 bits (L suffix)
    long long bigNum = 9000000000000000000LL;  // Usually 64 bits (LL suffix)
    
    std::cout << "short: " << shortNum << std::endl;
    std::cout << "int: " << normalNum << std::endl;
    std::cout << "long: " << longNum << std::endl;
    std::cout << "long long: " << bigNum << std::endl;
    
    // Show memory sizes
    std::cout << "\nMemory sizes (in bytes):" << std::endl;
    std::cout << "sizeof(short): " << sizeof(short) << " bytes" << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << " bytes" << std::endl;
    std::cout << "sizeof(long): " << sizeof(long) << " bytes" << std::endl;
    std::cout << "sizeof(long long): " << sizeof(long long) << " bytes" << std::endl;
    
    // ========================================
    // 2. SIGN MODIFIERS - Positive vs Negative
    // ========================================
    std::cout << "\n2. Sign Modifiers (Signed vs Unsigned):" << std::endl;
    
    signed int signedNum = -1500;        // Can be negative (default behavior)
    unsigned int unsignedNum = 3000000000U;  // Only positive (U suffix)
    
    // These are equivalent (signed is default):
    int normalInt = -42;
    signed int explicitSigned = -42;
    
    std::cout << "signed int: " << signedNum << std::endl;
    std::cout << "unsigned int: " << unsignedNum << std::endl;
    std::cout << "normal int (signed by default): " << normalInt << std::endl;
    std::cout << "explicitly signed: " << explicitSigned << std::endl;
    
    // ========================================
    // 3. COMBINATIONS - Size + Sign Together
    // ========================================
    std::cout << "\n3. Combined Modifiers (Size + Sign):" << std::endl;
    
    unsigned short smallPositive = 65000;           // 0 to ~65,535
    signed short smallSigned = -32000;              // ~-32,768 to ~32,767
    unsigned long bigPositive = 4000000000UL;       // Very large positive
    unsigned long long hugePositive = 18000000000000000000ULL;  // Massive positive
    
    std::cout << "unsigned short: " << smallPositive << std::endl;
    std::cout << "signed short: " << smallSigned << std::endl;
    std::cout << "unsigned long: " << bigPositive << std::endl;
    std::cout << "unsigned long long: " << hugePositive << std::endl;
    
    // ========================================
    // 4. RANGE LIMITS - What's the Maximum/Minimum?
    // ========================================
    std::cout << "\n4. Range Limits for Each Type:" << std::endl;
    
    std::cout << "int range: " << INT_MIN << " to " << INT_MAX << std::endl;
    std::cout << "short range: " << SHRT_MIN << " to " << SHRT_MAX << std::endl;
    std::cout << "long range: " << LONG_MIN << " to " << LONG_MAX << std::endl;
    std::cout << "long long range: " << LLONG_MIN << " to " << LLONG_MAX << std::endl;
    std::cout << "unsigned int max: " << UINT_MAX << std::endl;
    
    // ========================================
    // 5. PRACTICAL USE CASES
    // ========================================
    std::cout << "\n5. When to Use Each Type:" << std::endl;
    
    // Age: small positive number
    unsigned short age = 25;
    std::cout << "Age (unsigned short): " << age << " years" << std::endl;
    
    // Temperature: can be negative
    signed int temperature = -15;
    std::cout << "Temperature (signed int): " << temperature << "°C" << std::endl;
    
    // File size: large positive number
    unsigned long long fileSize = 5000000000ULL;  // 5GB
    std::cout << "File size (unsigned long long): " << fileSize << " bytes" << std::endl;
    
    // Array index: always positive, usually small
    unsigned int index = 42;
    std::cout << "Array index (unsigned int): " << index << std::endl;
    
    // Money in cents: can be negative (debt), medium range
    long accountBalance = -150000;  // -$1,500.00
    std::cout << "Account balance in cents (long): " << accountBalance << std::endl;
    
    // ========================================
    // 6. ARITHMETIC WITH DIFFERENT TYPES
    // ========================================
    std::cout << "\n6. Arithmetic with Different Types:" << std::endl;
    
    short a = 100;
    int b = 200;
    long c = 300L;
    
    // Results are promoted to larger type
    auto result1 = a + b;  // Becomes int
    auto result2 = b + c;  // Becomes long
    
    std::cout << "short + int = " << result1 << " (type: int)" << std::endl;
    std::cout << "int + long = " << result2 << " (type: long)" << std::endl;
    
    // ========================================
    // 7. INITIALIZATION WITH DIFFERENT SYNTAXES
    // ========================================
    std::cout << "\n7. Initialization Examples:" << std::endl;
    
    // Copy initialization
    unsigned int count1 = 1000;
    short height1 = 180;
    
    // Direct initialization  
    unsigned long distance1(50000);
    long long bigNumber1(9999999999999LL);
    
    // Brace initialization (safest)
    unsigned short score1 {95};
    signed int temperature1 {-20};
    unsigned long long huge1 {18446744073709551615ULL};
    
    std::cout << "All initialization methods work with modifiers!" << std::endl;
    
    // ========================================
    // 8. COMMON MISTAKES (COMMENTED OUT - UNCOMMENT TO TEST)
    // ========================================
    std::cout << "\n8. Common Mistakes (commented out):" << std::endl;
    
    // OVERFLOW EXAMPLES:
    // short tooLarge = 100000;              // May overflow! short max is ~32,767
    // unsigned int negative = -5;           // Becomes huge positive number!
    // int wayTooBig = 5000000000;           // Overflow! int max is ~2 billion
    
    // NARROWING CONVERSIONS:
    // long bigValue = 9999999999999LL;
    // int smallValue = bigValue;            // Data loss! long -> int
    // short tinyValue {bigValue};            // ERROR with brace initialization
    
    // MIXING SIGNED AND UNSIGNED (dangerous):
    // unsigned int positive = 10;
    // int negative = -5;
    // auto dangerous = positive + negative;  // Unexpected behavior!
    
    // SUFFIX MISTAKES:
    // long shouldBeLong = 9999999999999;    // Missing L suffix, may not work
    // unsigned int shouldBeUnsigned = 4000000000;  // Missing U, may overflow
    
    std::cout << "Error examples are commented out. Uncomment to see warnings/errors!" << std::endl;
    
    // ========================================
    // 9. BEST PRACTICES SUMMARY  
    // ========================================
    std::cout << "\n=== BEST PRACTICES ===" << std::endl;
    std::cout << "✅ Use 'int' for most general-purpose integers" << std::endl;
    std::cout << "✅ Use 'unsigned' when values are always positive" << std::endl;
    std::cout << "✅ Use 'long long' for very large numbers" << std::endl;
    std::cout << "✅ Use 'short' only when memory is very limited" << std::endl;
    std::cout << "✅ Add suffixes: L for long, U for unsigned, LL for long long" << std::endl;
    std::cout << "✅ Use brace initialization  {} to catch overflow errors" << std::endl;
    std::cout << "⚠️  Be careful mixing signed and unsigned types" << std::endl;
    std::cout << "⚠️  Watch out for overflow - choose appropriate size" << std::endl;
    
    return 0;
}