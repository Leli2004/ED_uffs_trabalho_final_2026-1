
########################################
# make => compilar
# make run => compilar e executar
# make clean => limpar o executável
########################################

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = app/main.c app/library.c
OUT = biblioteca

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

