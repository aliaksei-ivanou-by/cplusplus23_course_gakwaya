#include "exercise.h"

bool check_number_systems() {
    int decimal = 15;
    int octal = 017;
    int hex = 0x0F;
    int binary = 0b00001111;

    return (decimal == octal) && (decimal == hex) && (decimal == binary);
}