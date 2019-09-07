#include "tests.h"

void test_str_repeat() {
    char str[] = "Repeat";
    char buf[100];
    str_repeat(str, 10, buf, sizeof(buf));

    printf("%s\n", buf);
}
