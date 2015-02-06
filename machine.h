#ifndef MACHINE_H
#define MACHINE_H

#include <stdio.h>
#include "stack.h"
#include "instructions.h"

void mach_step(struct instr instr);

void exec_ldc(item c);
void exec_add();
void exec_print();
void exec_dup();

#endif
