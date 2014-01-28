.PHONY: all clean

CFLAGS = -Wall
SRCDIR = src
SRC := $(wildcard $(SRCDIR)/*.c)

OBJ  := $(patsubst %.c,%.o,$(SRC))

TARGET = dogpaw

all: $(TARGET)

dogpaw: $(OBJ)
	$(CC) $^ -o $@

clean:
	-rm -rf src/*.o $(TARGET)
