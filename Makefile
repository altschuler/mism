CC = gcc

CC_FLAGS = -std=c11

C_FILES = machine.c stack.c instructions.c

build:
	$(CC) $(CC_FLAGS) main.c $(C_FILES) -g -o mism
