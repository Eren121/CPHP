#include "prototypes.h"

void array_for_each(void* t,
                    int n,
                    array_for_each_callback callback,
                    void* data) {
  int i;

  for(i = 0; i < n; i++) {
    callback(t, i, data);
  }
}
