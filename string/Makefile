CXXFLAGS = -Wall -Wextra -g
objects = string.o misc.o test.o

all: test

.PHONY: run
run: test
	valgrind ./test	

test: $(objects)
	gcc $(CXXFLAGS) -o test $(objects)

test.o: test.c string.h misc.h
string.o: string.c string.h
misc.o: misc.c misc.h

%.o: %.c %.h
	gcc $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm $(objects)
