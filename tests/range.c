#include "tests.h"

void test_range() {
    int v1[] = {0, 1, 2, 3};
    int v2[] = {0, 2, 4, 6};
    int v3[] = {0, -2, -4, -6};
    int t[4];

    range(0, 3, 1, t);
    ASSERT_EQUALS_ARRAYS(t, v1);

    range(0, 6, 2, t);
    ASSERT_EQUALS_ARRAYS(t, v2);

    range(0, -6, 2, t);
    ASSERT_EQUALS_ARRAYS(t, v3);
}
