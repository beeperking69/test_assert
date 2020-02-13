#ifndef __TEST_ASSERT_TEST_ASSERT_H__
#define __TEST_ASSERT_TEST_ASSERT_H__

#include <stdio.h>  // printf()
#include <stdlib.h> // exit()
#include <string.h> // memcmp()

#define _MAX_TESTS 512
#define _TEST "[TEST]"
#define _TAB_1 _TEST "     "
#define _TAB_2 _TEST "         "
#define _TAB_3 _TEST "             "

#define TEST_SUITE(...) void (*_TESTS[_MAX_TESTS]) = { __VA_ARGS__, 0 }

void assert_array_equals(const void* expected, const void* actual,
    size_t size, size_t count, char* (to_string)(const void*));

#endif