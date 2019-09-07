#include "prototypes.h"

void array_print(int* t, int n) {
  int i;

  for(i = 0; i < n; i++) {
    printf("%d", t[i]);

    if(i == n - 1) {
      putchar('\n');
    }
    else {
      printf(", ");
    }
  }
}
