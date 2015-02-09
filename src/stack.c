#include "stack.h"

static item s[100];             /* global stack */
static int sp = 0;              /* stack pointer */

item stack_pop()
{
    return s[--sp];
}

void stack_push(item si)
{
    s[sp++] = si;
}

item stack_peek()
{
    return s[sp - 1];
}
