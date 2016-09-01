default: all

.PHONY : default


all: roman_clib test_roman clean
	tests/test_roman

.PHONY : all


roman_clib:
	$(MAKE) -f src/build.make src/build
.PHONY : roman_clib


test_roman:
	$(MAKE) -f tests/build.make tests/build
.PHONY : test_roman


clean:
	$(MAKE) -f src/build.make src/clean
	$(MAKE) -f tests/build.make tests/clean
.PHONY : clean