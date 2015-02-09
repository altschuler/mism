CC ?= gcc

CCWARN ?= -W -pedantic -Werror -Wall -std=gnu99 \
	-fno-strict-aliasing -fno-common -Wno-unused-parameter
CCOPT  ?= -fstrict-aliasing -fstrict-overflow
CFLAGS ?= $(CCWARN) $(CCOPT)

TARGET = bin/mini
LIBS =

SDIR = src
ODIR = bin

DEBUG ?= 0
DEBUG_FILE = $(SDIR)/debug.h

SRC = $(wildcard $(SDIR)/*.c)
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

.PHONY: all sed debug release build run test clean

all: debug run

debug: DEBUG = 1
debug: CFLAGS += -O0 -gdwarf-2
debug: build

release: CFLAGS += -O3 -gdwarf-2
release: clean build

sed: $(SDIR)/main.c
	sed -i "s/^\#define DEBUG ./#define DEBUG $(DEBUG)/" $(DEBUG_FILE)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

build: sed $(TARGET)

run: $(TARGET)
	./$(TARGET)

test:
	@echo TODO: test

clean:
	-rm -f $(OBJ) $(TARGET)
