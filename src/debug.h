#define DEBUG 1

#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>

// http://stackoverflow.com/questions/1644868/c-define-macro-for-debug-printing
#define dprint(fmt, ...)                                                \
    do { if (DEBUG) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__,       \
                            __LINE__, __func__, __VA_ARGS__); } while (0)

#endif
