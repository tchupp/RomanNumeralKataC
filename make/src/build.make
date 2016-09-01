include src/flags.make

src/roman_converter.c.o: ../src/roman_converter.c
	$(CC) $(C_FLAGS) -o $@ -c $^


src/roman_numeral_pair.c.o: ../src/roman_numeral_pair.c
	$(CC) $(C_FLAGS) -o $@ -c $^


src/libroman_clib.a: src/roman_converter.c.o
src/libroman_clib.a: src/roman_numeral_pair.c.o
	rm -f $@
	ar qc $@ $^

src/build: src/libroman_clib.a

.PHONY : src/build

src/clean:
	rm -f src/*.o
.PHONY : src/clean
