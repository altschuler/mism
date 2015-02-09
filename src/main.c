#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "instructions.h"
#include "machine.h"
#include "debug.h"

#define PLEN 9

int main (int argc, char **argv)
{
    dprint("%s\n", "Debug enabled");

    int program[PLEN] = {
        0x400000D,     /* 00000100 000000000000000000001101: LDC 13 */
        0x4000025,     /* 00000100 000000000000000000100101: LDC 37 */
        0x1000000,     /* 00000001 000000000000000000000000: ADD */
        0x2000000,     /* 00000010 000000000000000000000000: DUP */
        0x3000000,     /* 00000011 000000000000000000000000: PRINT */
        0x4000001,     /* 00000100 000000000000000000000001: LDC 1 */
        0x1000000,     /* 00000001 000000000000000000000000: ADD */
        0x3000000,     /* 00000011 000000000000000000000000: PRINT */
        0x0000000      /* 00000000 000000000000000000000000: HALT */
    };

    for (int i = 0; i < PLEN; i++) {
        struct instr instr = decode(program[i]);
        mach_step(instr);
    }

    return 0;
}
