#include "prototypes.h"
#include <string.h>

void str_repeat(const char* input, int multiplier, char* t, int maxsize) {
    const size_t len = strlen(input);
    size_t offset = 0;
    int i;

    if(maxsize > 0) {
        for(i = 0; i < multiplier && offset < maxsize - 1; i++) {
            strncpy(t + offset, input, maxsize - offset);
            offset += len;
        }

        if(offset >= maxsize - 1) {
            offset = maxsize - 1;
        }

        t[offset] = '\0';
    }
}
