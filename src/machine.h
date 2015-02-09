#ifndef MACHINE_H
#define MACHINE_H

#include <stdio.h>
#include "stack.h"
#include "instructions.h"

extern void exit(int);

void mach_step(struct instr instr);

void exec_halt();
void exec_add();
void exec_ldc(item c);
void exec_print();
void exec_dup();

#endif
