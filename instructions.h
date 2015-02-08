#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "stack.h"

enum op {
    HALT,
    LDC,
    ADD,
    DUP,
    PRINT,
};

struct instr {
    enum op op;
    item arg1;
};

struct instr decode(int i);

struct instr make_instr(enum op op, item arg1);

#endif
