#include <string.h>

#include "roman_converter.h"
#include "roman_numeral_pair.h"

void convert_to_roman(unsigned int value, char *result) {
    int num_pairs = 7;

    struct RomanNumeralPair *pairs[num_pairs];
    pairs[0] = new_rn_pair(1000, "M");
    pairs[1] = new_rn_pair(500, "D");
    pairs[2] = new_rn_pair(100, "C");
    pairs[3] = new_rn_pair(50, "L");
    pairs[4] = new_rn_pair(10, "X");
    pairs[5] = new_rn_pair(5, "V");
    pairs[6] = new_rn_pair(1, "I");

    for (int i = 0; i < num_pairs; i++) {
        unsigned int arabic = get_arabic(pairs[i]);
        char *roman = get_roman(pairs[i]);

        while (value >= arabic) {
            strcpy(result, roman);
            result += strlen(roman);
            value -= arabic;
        }
    }

    for (int i = 0; i < num_pairs; i++) {
        free_rn_pair(pairs[i]);
    }
}
