#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "stack.h"

enum op {
    LDC,
    ADD,
    DUP,
    PRINT
};

struct instr {
    enum op op;
    item arg1;
};

#endif
