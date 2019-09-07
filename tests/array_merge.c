#include "tests.h"

void test_array_merge() {
    int t1[] = {1, 2, 3};
    int t2[] = {4, 5, 6};
    int t3[] = {7, 8, 9};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int t[sizeof_arr(t1) + sizeof_arr(t2) + sizeof_arr(t3)];

    array_merge(t, t1, sizeof_arr(t1), t2, sizeof_arr(t2), t3, sizeof_arr(t3), NULL);
    ASSERT_EQUALS_ARRAYS(t, expected);
}
