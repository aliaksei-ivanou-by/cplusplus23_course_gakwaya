#include <fmt/format.h>

import utilities;

int main() {
    int value1 {10};
    int value2 {20};
    int result = value1 + value2;
    fmt::print("Result: {}\n", result);
}