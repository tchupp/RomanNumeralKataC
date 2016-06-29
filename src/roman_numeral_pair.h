#ifndef ROMAN_CLIB_ROMAN_NUMERAL_PAIR_H
#define ROMAN_CLIB_ROMAN_NUMERAL_PAIR_H

typedef struct RomanNumeralPair RomanNumeralPair;

RomanNumeralPair *new_rn_pair(unsigned int arabic, char *roman);
void free_rn_pair(RomanNumeralPair *pair);

unsigned int get_arabic(RomanNumeralPair *pair);
char *get_roman(RomanNumeralPair *pair);

#endif //ROMAN_CLIB_ROMAN_NUMERAL_PAIR_H
