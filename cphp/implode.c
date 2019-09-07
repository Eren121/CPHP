#include "prototypes.h"
#include <string.h>

void join(const char* glue,
          const char** pieces,
          int n,
          char* t,
          int maxsize) {

  implode(glue, pieces, n, t, maxsize);
}

void implode(const char* glue,
             const char** pieces,
             int n,
             char* t,
             int maxsize) {
  char* dest = t;
  int remain_size = maxsize - 1;
  int glue_length = strlen(glue);
  int length;
  int i;

  for(i = 0; i < n && remain_size > 0; i++) {

    length = strlen(pieces[i]);
    strncpy(dest, pieces[i], remain_size);
    dest += length;
    remain_size -= length;

    if(i != n - 1 && remain_size > 0) {

      strncpy(dest, glue, remain_size);
      dest += glue_length;
      remain_size -= glue_length;
    }
  }

  if(remain_size >= 0) {
    *dest = '\0';
  }
  else {
    t[maxsize - 1] = '\0';
  }
}
