#pragma once

#include <fmt/format.h>

int add_number(int first_parameter, int second_parameter) {
    return first_parameter + second_parameter;
}

void do_work() {
    fmt::print("Hello");
    fmt::print("World");
    fmt::print("\n");

    int num1 {5};
    int num2 {6};
    int result1 = num1 + num2;
    int result2 = add_number(num1, num2);
    fmt::print("Result1: {}\n", result1);
    fmt::print("Result2: {}\n", result2);
}