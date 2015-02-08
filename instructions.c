#include "instructions.h"

struct instr decode(int raw_instr)
{
    int op_code = raw_instr >> 24;

    switch (op_code) {

    case 0x1:
        return make_instr(ADD, 0);

    case 0x2:
        return make_instr(DUP, 0);

    case 0x3:
        return make_instr(PRINT, 0);

    case 0x4:
        return make_instr(LDC, raw_instr & ~(0x4000000));

    case 0x0:
    default:
        return make_instr(HALT, 0);
    }

}

struct instr make_instr(enum op op, item arg1)
{
    struct instr instr;
    instr.op = op;
    instr.arg1 = arg1;

    return instr;
}
