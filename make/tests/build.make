include tests/flags.make

tests/check_main.c.o: ../tests/check_main.c
	$(CC) $(C_FLAGS) -o $@ -c $^


tests/check_roman_converter_to_roman.c.o: ../tests/check_roman_converter_to_roman.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^


tests/check_roman_converter_to_arabic.c.o: ../tests/check_roman_converter_to_arabic.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^

tests/check_roman_numeral_pair.c.o: ../tests/check_roman_numeral_pair.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^

tests/test_roman: tests/check_main.c.o
tests/test_roman: tests/check_roman_converter_to_roman.c.o
tests/test_roman: tests/check_roman_converter_to_arabic.c.o
tests/test_roman: tests/check_roman_numeral_pair.c.o
	$(CC) $(C_FLAGS) $^ -o $@ `pkg-config --libs check` src/libroman_clib.a

tests/build: tests/test_roman

.PHONY : tests/build

tests/clean:
	rm -f tests/*.o
.PHONY : tests/clean