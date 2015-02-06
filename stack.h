#ifndef STACK_H
#define STACK_H

typedef unsigned int item;
typedef item stack[100];

item stack_pop();

void stack_push(item si);

item stack_peek();

#endif
