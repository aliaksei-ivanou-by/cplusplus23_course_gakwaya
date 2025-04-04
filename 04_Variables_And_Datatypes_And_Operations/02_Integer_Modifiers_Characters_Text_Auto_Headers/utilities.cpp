#include "utilities.h"

void braced_initialization() {
    int elephant_count;
    int lion_count {};
    int dog_count {20};
    int cat_count {15};
    int domesticated_animals {dog_count + cat_count};

    fmt::println("Elephant count: {}", elephant_count );
    fmt::println("Lion count: {}", lion_count);
    fmt::println("Dog count: {}", dog_count);
    fmt::println("Cat count: {}", cat_count);
    fmt::println("Domesticated animals: {}", domesticated_animals);
}

void functional_initialization() {
    int apple_count(5);
    int orange_count(10);
    int fruit_count(apple_count + orange_count);
    int narrowing_conversion_functional (2.9);

    fmt::println("Apple count: {}", apple_count);
    fmt::println("Orange count: {}", orange_count);
    fmt::println("Fruit count: {}", fruit_count);
    fmt::println("Narrowing conversion: {}", narrowing_conversion_functional);
}

void assignment_initialization() {
    int bike_count = 2;
    int truck_count = 7;
    int vehicle_count = bike_count +truck_count;
    int narrowing_conversion_assignment = 2.9;

    fmt::println("Bike count: {}", bike_count);
    fmt::println("Truck count: {}", truck_count);
    fmt::println("Vehicle count: {}", vehicle_count);
    fmt::println("Narrowing conversion: {}", narrowing_conversion_assignment);

    //Check the size with sizeof
    fmt::println("sizeof int: {}", sizeof(int));
    fmt::println("sizeof truck_count: {}", sizeof(truck_count));
}

void integer_modifiers() {
    signed int value1 {10};
    signed int value2 {-20};
    unsigned int value3 {300};

    fmt::println("Value1: {}", value1);
    fmt::println("Value2: {}", value2);
    fmt::println("Value3: {}", value3);

    short int short_var {-32768};
    short int short_int {455};//
    signed short signed_short {122};
    signed short int signed_short_int {-456}
    unsigned short int unsigned_short_int {456};

    long long_var {88};
    long int long_int {33};
    signed long signed_long {44};
    signed long int signed_long_int {44};
    unsigned long int unsigned_long_int {44};

    long long long_long {888};
    long long int long_long_int {999};
    signed long long signed_long_long {444};
    signed long long int signed_long_long_int {1234};
    unsigned long long int unsigned_long_long_int {1234};

    fmt::println("Short variable: {}, size: {} bytes", short_var, sizeof(short));
    fmt::println("Short int: {}, size: {} bytes", short_int, sizeof(short int));
    fmt::println("Signed short: {}, size: {} bytes", signed_short, sizeof(signed short));
    fmt::println("Signed short int: {}, size: {} bytes", signed_short_int, sizeof(signed short int));
    fmt::println("unsigned short int: {}, size: {} bytes", unsigned_short_int, sizeof(unsigned short int));
    fmt::println("");

    fmt::println("Long variable: {}, size: {} bytes", long_var, sizeof(long));
    fmt::println("Long int: {}, size: {} bytes", long_int, sizeof(long int));
    fmt::println("Signed long: {}, size: {} bytes", signed_long, sizeof(signed long));
    fmt::println("Signed long int: {}, size: {} bytes", signed_long_int, sizeof(signed long int));
    fmt::println("unsigned long int: {}, size: {} bytes", unsigned_long_int, sizeof(unsigned long int));
    fmt::println("");

    fmt::println("Long long: {}, size: {} bytes", long_long, sizeof(long long));
    fmt::println("Long long int: {}, size: {} bytes", long_long_int, sizeof(long long int));
    fmt::println("Signed long long : {}, size: {} bytes", signed_long_long, sizeof(signed long long));
    fmt::println("Signed long long int: {}, size: {} bytes", signed_long_long_int, sizeof(signed long long int));
    fmt::println("unsigned long long int: {}, size: {} bytes", unsigned_long_long_int, sizeof(unsigned long long int));
    fmt::println("");
}

void floating_point_numbers() {
    float number1 {1.12345678901234567890f};
    double number2 {1.12345678901234567890};
    long double number3 {1.12345678901234567890L};

    fmt::println("number1 is: {}", number1);
    fmt::println("number2 is: {}", number2);
    fmt::println("number3 is: {}", number3);

    fmt::println("");
    double number5 {192400023};
    double number6 {1.92400023e8};
    double number7 {1.924e8};
    double number8 {0.00000000003498};
    double number9 {3.498e-11};

    fmt::println("number5 is: {}", number5);
    fmt::println("number6 is: {}", number6);
    fmt::println("number7 is: {}", number7);
    fmt::println("number8 is: {}", number8);
    fmt::println("number9 is: {}", number9);
}

void infinity_nan() {
    double number10 {-5.6};
    double number11 {0};
    double number12 {0};
    double result = number10 / number11;

    fmt::println("{} / {} yields {}", number10, number11, result);
    fmt::println("{} + {} yields {}", result, number10, result + number10);

    result = number11 / number12;
    fmt::println("{} / {} = {}", number11, number12, result);
}

void bool_type() {
    bool red_light {false};
    bool green_light {true};

    fmt::println("Red light: {}", red_light);
    fmt::println("Green light: {}", green_light);

    if(red_light == true) {
        fmt::println("Red light is true");
    } else {
        fmt::println("Red light is not true");
    }

    fmt::println("Size of bool is: {}", sizeof(bool));

    fmt::println("Red light: {}", red_light);
    fmt::println("Green light: {}", green_light);
}

void characters_and_text() {
    char character1 {'a'};
    char character2 {'r'};
    char character3 {'r'};
    char character4 {'o'};
    char character5 {'w'};

    fmt::println("{}",character1);
    fmt::println("{}",character2);
    fmt::println("{}",character3);
    fmt::println("{}",character4);
    fmt::println("{}",character5);
    
    char value = 65;
    fmt::println("value: {}", value);
    fmt::println("value(int): {}", static_cast<unsigned int>(value));
}

void collections_of_characters() {
    std::vector<int> numbers {10, 20 , 100, 200};

    std::string message {"arrow"};
    
	fmt::println("Message is: {}", message);

    std::string greeting {"Hello"};
    
	fmt::println("Greeting: {}", greeting);

    greeting.append(" there!");
    fmt::println("Greeting: {}", greeting);
}

void auto_keyword() {
    auto var1 {12};
    auto var2 {13.0};
    auto var3 {14.0f};
    auto var4 {15.0l};
    auto var5 {'e'};

    auto var6 {123u};
    auto var7 {123ul};
    auto var8 {123ll};

    fmt::println("var1 occupies: {} bytes", sizeof(var1));
    fmt::println("var2 occupies: {} bytes", sizeof(var2));
    fmt::println("var3 occupies: {} bytes", sizeof(var3));
    fmt::println("var4 occupies: {} bytes", sizeof(var4));
    fmt::println("var5 occupies: {} bytes", sizeof(var5));
    fmt::println("var6 occupies: {} bytes", sizeof(var6));
    fmt::println("var7 occupies: {} bytes", sizeof(var7));
    fmt::println("var8 occupies: {} bytes", sizeof(var8));
}