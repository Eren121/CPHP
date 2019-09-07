#include "prototypes.h"
#include "generic/prototypes.h"

void array_sum_callback(void* t, int i, void* data) {
  int* sum = (int*)data;
  int* array = (int*)t;

  *sum += array[i];
}

int array_sum(int* array, int n) {
  int sum = 0;

  array_for_each(array, n, array_sum_callback, &sum);

  return sum;
}

void array_sum_float_callback(void* t, int i, void* data) {
  float* sum = (float*)data;
  float* array = (float*)t;

  *sum += array[i];
}

float array_sum_float(float* array, int n) {
  float sum = 0;

  array_for_each(array, n, array_sum_float_callback, &sum);

  return sum;
}
