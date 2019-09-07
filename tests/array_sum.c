#include "tests.h"

void test_array_sum_builtin() {
    int tab[] = {100, 100, 100, 10, 10, 1, 1, 1};

    ASSERT_EQUALS(323, array_sum(tab, sizeof_arr(tab)));
}

void test_array_sum_float() {
    float tab[] = {100.1f, 100.1f, 100.1f, 10.1f, 10.1f, 1.1f, 1.1f, 1.1f};

    ASSERT_EQUALS_FLOAT(323.8f, array_sum_float(tab, sizeof_arr(tab)));
}

void test_array_sum() {

    test_array_sum_builtin();
    test_array_sum_float();
}
