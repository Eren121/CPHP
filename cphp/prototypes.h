#ifndef PROTOTYPE_H
#define PROTOTYPE_H

int array_sum(int* array, int n);
float array_sum_float(float* array, int n);

// step must be positive
void range(int start, int end, int step, int* t);

void array_merge(int *t, ... /* int *p, int n, ..., NULL */);

void implode(const char* glue,
             const char** pieces,
             int n,
             char* t,
             int maxisze);

void join(const char* glue,
          const char** pieces,
          int n,
          char* t,
          int maxsize); // implode alias

void str_repeat(const char* input, int multiplier, char* t, int maxsize);

#endif // PROTOTYPE_H
