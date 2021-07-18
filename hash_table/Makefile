CXXFLAGS = -Wall -Wextra -g
objects = ht.o misc.o test.o

all: test

.PHONY: run
run: test
	valgrind ./test	

test: $(objects)
	gcc $(CXXFLAGS) -o test $(objects)

test.o: test.c ht.h misc.h
string.o: ht.c ht.h
misc.o: misc.c misc.h

%.o: %.c %.h
	gcc $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm $(objects)
