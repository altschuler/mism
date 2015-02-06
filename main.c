#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "instructions.h"
#include "machine.h"

#define PLEN 8

int main (int argc, char **argv)
{
    struct instr program[PLEN] = {
        { .op = LDC, .arg1 = 13 },
        { .op = LDC, .arg1 = 37 },
        { .op = ADD },
        { .op = DUP },
        { .op = PRINT },
        { .op = LDC, .arg1 = 1 },
        { .op = ADD },
        { .op = PRINT },
    };

    for (int i = 0; i < PLEN; i++) {
        mach_step(program[i]);
    }

    return 0;
}
