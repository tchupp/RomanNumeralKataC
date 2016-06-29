#include <memory.h>
#include "roman_converter.h"

void convertToRoman(unsigned int value, char *result) {
    switch (value) {
        case 1:
            strcpy(result, "I");
            break;
        case 5:
            strcpy(result, "V");
            break;
        case 10:
            strcpy(result, "X");
            break;
        case 50:
            strcpy(result, "L");
            break;
        case 100:
            strcpy(result, "C");
            break;
        case 500:
            strcpy(result, "D");
            break;
        case 1000:
            strcpy(result, "M");
            break;
        default:
            strcpy(result, "");
            break;
    }
}
