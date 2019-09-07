#ifndef GENERIC_PROTOTYPES_H
#define GENERIC_PROTOTYPES_H

// Callback for for_each
// Arguments: array and current index
// For each in increasing order
typedef void (*array_for_each_callback)(void* t,
                                        int i,
                                        void* data);

void array_for_each(void* t,
                    int n,
                    array_for_each_callback callback,
                    void* data);


void array_print(int* t, int n);

#endif // GENERIC_PROTOTYPES_H
