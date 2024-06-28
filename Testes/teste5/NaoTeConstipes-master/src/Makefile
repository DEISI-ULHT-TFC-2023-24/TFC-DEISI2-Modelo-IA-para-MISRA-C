CC = gcc
override CFLAGS += -g -Wvla -Wall -Wpedantic -Wextra -Wdeclaration-after-statement -fprofile-arcs -ftest-coverage --coverage

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
OBJS = $(patsubst %.c, %.o, $(SRCS))

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main -lm

clean:
	rm -f $(OBJS) main *.gcno *.gcov *.gcda
	clear

test: main
	mkdir -p ./tests
	gcov main.c board.c
	python testgen.py testset.json ./main ./tests PF
	rm -rf tests.zip
	zip -r tests.zip tests/*.in tests/*.out
	gcov main.c board.c


zip:
	rm -rf src.zip
	zip -r src.zip *.c *.h

