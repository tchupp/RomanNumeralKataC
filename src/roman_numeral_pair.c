#include <stddef.h>
#include <stdlib.h>

#include "roman_numeral_pair.h"

struct RomanNumeralPair {
    unsigned int arabic;
    char *roman;
};

RomanNumeralPair *new_rn_pair(unsigned int arabic, char *roman) {
    RomanNumeralPair *pair = malloc(sizeof(RomanNumeralPair));

    if (pair) {
        pair->arabic = arabic;
        pair->roman = roman;
    }

    return pair;
}

void free_rn_pair(RomanNumeralPair *pair) {
    free(pair);
}

unsigned int get_arabic(RomanNumeralPair *pair) {
    return pair->arabic;
}

char *get_roman(RomanNumeralPair *pair) {
    return pair->roman;
}
