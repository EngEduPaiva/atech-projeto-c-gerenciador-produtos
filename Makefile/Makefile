CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
SRC = src
OBJ = $(SRC)/produto.c $(SRC)/main.c
TARGET = gerenciador

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
    rm -f $(TARGET) *.o produtos.dat produtos_tmp.dat

.PHONY: all clean
