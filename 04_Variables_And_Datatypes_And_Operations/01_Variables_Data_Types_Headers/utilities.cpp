#include "utilities.h"
#include <fmt/format.h>
#include <limits>

void number_systems() {
    int number1 =  15;
    int number2 = 017;
    int number3 = 0x0F;
    int number4 = 0b00001111;

    fmt::println("number1: {}", number1);
    fmt::println("number2: {}", number2);
    fmt::println("number3: {}", number3);
    fmt::println("number4: {}", number4);
}

void floating_point_types() {
    float single_precision = 1.123456789123456789f;
    double double_precision = 1.123456789123456789;
    long double long_double_precision = 1.123456789123456789123456789L;

    fmt::println("Float (single precision): {:.30f}", single_precision);
    fmt::println("Double (double precision): {:.30f}", double_precision);
    fmt::println("Long double (extended precision): {:.30Lf}", long_double_precision);

    fmt::println("Size of float: {} bytes", sizeof(float));
    fmt::println("Size of double: {} bytes", sizeof(double));
    fmt::println("Size of long double: {} bytes", sizeof(long double));
}

void numeric_limits() {
    fmt::println("The range for int is from {} to {}", 
                    std::numeric_limits<int>::min(),
                    std::numeric_limits<int>::max());
    fmt::println("The range for float is from {} to {}", 
                    std::numeric_limits<float>::min(),
                    std::numeric_limits<float>::max());

    fmt::println("The range for double is from {} to {}", 
                    std::numeric_limits<double>::min(),
                    std::numeric_limits<double>::max());

    fmt::println("The range for long double is from {} to {}", 
                    std::numeric_limits<long double>::min(),
                    std::numeric_limits<long double>::max());
}