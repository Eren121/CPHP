#include "tests.h"

void test_implode() {
    char glue[] = ", ";
    const char* pieces[] = {"Hello", "World"};
    char buf[100];

    implode(glue, pieces, sizeof_arr(pieces), buf, sizeof(buf));
    ASSERT_EQUALS_STRINGS(buf, "Hello, World");
}
