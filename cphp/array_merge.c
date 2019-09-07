#include "prototypes.h"
#include <stdarg.h>
#include <string.h>

void array_merge(int *t, ... /* int *p, int n, ..., NULL */) {
  int *p;
  int n;
  va_list va;

  va_start(va, t);
  p = va_arg(va, int*);

  while(p) {
    n = va_arg(va, int);

    memcpy(t, p, sizeof(*t) * n);

    t += n;

    p = va_arg(va, int*);
  }

  va_end(va);
}
