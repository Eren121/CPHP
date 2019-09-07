#ifndef TESTS_ASSERTIONS_H
#define TESTS_ASSERTIONS_H

#include <math.h>   // fabs
#include <string.h> // memcmp, strcmp
#include <stdio.h>  // printf
#include "ansi.h"   // Color codes

#define sizeof_arr(t) (sizeof(t) / sizeof(*t))
#define DELTA          0.001

#define BOOL_1         (BG_GREEN "1" CLEAR)
#define BOOL_0         (BG_RED "0" CLEAR)
#define BOOL_STR(x)    ((x) ? BOOL_1 : BOOL_0)
#define EXPR(x)        ANSI_ESCAPE(43) x CLEAR
#define VALUE(x)       ANSI_ESCAPE(1) ANSI_ESCAPE(104) x CLEAR
#define ASSERT_EQUALS(A, B) \
  printf(EXPR("%s == %s") " ?: " VALUE("%d == %d") " ?: %s\n", \
    #A, #B, (int)(A), (int)(B), BOOL_STR((A) == (B)));

#define ASSERT_EQUALS_FLOAT(A, B) \
  printf(EXPR("%s == %s") " ?: " VALUE("%f == %f") " ?: %s\n", \
    #A, #B, (float)(A), (float)(B), BOOL_STR(fabs((A) - (B)) < DELTA));

#define ASSERT_EQUALS_ARRAYS(A, B) \
  printf(EXPR("%s == %s") " ?: %s\n", \
    #A, #B, BOOL_STR(memcmp((A), (B), sizeof(A)) == 0));

#define ASSERT_EQUALS_STRINGS(A, B) \
  printf(EXPR("%s == %s") " ?: " VALUE("\"%s\" == \"%s\"") " ?: %s\n", \
    #A, #B, (A), (B), BOOL_STR(strcmp((A), (B)) == 0));

#endif // TESTS_ASSERTIONS_H
