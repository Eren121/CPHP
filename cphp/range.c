#include "prototypes.h"

void range(int start, int end, int step, int* t) {
  int n;
  int i;
  int v;

  if(end < start) {
    step = -step;
  }

  n = (end - start) / step + 1;

  for(i = 0, v = start; i < n; i++, v += step) {
      t[i] = v;
  }
}


/*
  void range(int start, int end, int step, int* t) {
    int i;
    int v;

    if(end < start) {
      step = -step;
    }

    for(i = 0, v = start; (start <= end && v <= end)
                       || (start > end && v >= end); i++, v += step) {
      t[i] = v;
    }
  }
*/
