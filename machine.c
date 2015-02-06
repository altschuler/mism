#include "machine.h"

void mach_step(struct instr instr)
{
    switch (instr.op) {
    case ADD:
        exec_add();
        break;

    case LDC:
        exec_ldc(instr.arg1);
        break;

    case PRINT:
        exec_print();
        break;

    case DUP:
        exec_dup();
        break;
    }
}

void exec_ldc(item c)
{
    stack_push(c);
}

void exec_add()
{
    item i1 = stack_pop();
    item i2 = stack_pop();

    stack_push(i1 + i2);
}

void exec_dup()
{
    item i = stack_peek();

    stack_push(i);
}

void exec_print()
{
    item i = stack_pop();

    printf("%i\n", i);
}
