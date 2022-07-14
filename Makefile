BUILD_DIRS = build \
	build/obj \
	build/lib \
	build/tests

TEST_BINS = build/tests/hello

OBJECTS = build/obj/io.o \
	build/obj/str.o

.PHONY: clean tests library install uninstall

tests: $(TEST_BINS)

library: build/lib/libcrex.a

# T E S T    B I N A R I E S

build/tests/%: build/obj/%.o $(OBJECTS)
	@echo -n COMPILING TEST $@...
	@gcc -g -Wall -o $@ $< $(OBJECTS)
	@echo DONE!

# T E S T    O B J E C T    F I L E S

build/obj/%.o: tests/%.c
	@ echo -n BUILDING $@...
	@ gcc -g -Wall -o $@ -c $<
	@ echo DONE!

# L I B R A R I E S

build/lib/libcrex.a: $(OBJECTS)
	@ echo -n ARCHIVING build/lib/libcrex.a...
	@ ar rcs build/lib/libcrex.a $(OBJECTS)
	@ echo DONE!

# O B J E C T    F I L E S 

build/obj/%.o: src/%.c src/crex.h
	@ echo -n BUILDING $@.o...
	@ gcc -g -Wall -o $@ -c $<
	@ echo DONE!

install: library
	@ echo -n COPYING FILES...
	@ cp build/lib/libcrex.a /usr/local/lib/libcrex.a
	@ cp src/crex.h /usr/local/include/crex.h
	@ echo DONE!

uninstall:
	@ echo -n DELETING FILES...
	@ rm -f /usr/local/lib/libcrex.a
	@ rm -f /usr/local/include/crex.h
	@ echo DONE!

clean:
	@ echo -n CLEANING BUILD DIRECTORY...
	@ rm -Rf build
	@ echo DONE!

$(shell mkdir -p $(BUILD_DIRS))