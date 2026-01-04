CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = seekc

SRC = main.c scanner.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) 

run: all
	./$(TARGET)

.PHONY: all clean run