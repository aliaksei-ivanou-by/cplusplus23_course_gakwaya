module;

#include <fmt/format.h>

export module utilities;

export int add_number(int first_parameter, int second_parameter) {
    return first_parameter + second_parameter;
}

export void do_work() {
    fmt::print("Hello");
    fmt::print("World");
    fmt::print("\n");

    int num1 {5};
    int num2 {6};
    int result1 = num1 + num2;
    int result2 = add_number(num1, num2);
    fmt::println("Result1: {}", result1);
    fmt::println("Result2: {}", result2);
    fmt::println("Doing something inside do_work");
}