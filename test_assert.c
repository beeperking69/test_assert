#include "test_assert.h"

void assert_equals(const void* expected, const void* actual, size_t size, char* (to_string)(const void*))
{
    if (memcmp(expected, actual, size) != 0)
    {
        printf(_TAB_1 "Failure\n");
        if (to_string != NULL)
        {
            printf(_TAB_2 "Expected:\n" _TAB_3 "%s\n", to_string(expected));
            printf(_TAB_2 "Actual:\n" _TAB_3 "%s\n", to_string(actual));
        }
        exit(1);
    }
    printf(_TAB_1 "Success\n");
}

void assert_array_equals(const void* expected, const void* actual, size_t size, size_t count, char* (to_string)(const void*))
{
    for (size_t i = 0; i < count; i++)
    {
        const void* e = expected + i * size;
        const void* a = actual + i * size;
        if (memcmp(e, a, size) != 0)
        {
            printf(_TAB_1 "Failure: Error at index [%lu].\n",  i);
            if (to_string != NULL)
            {
                printf(_TAB_2 "Expected:\n" _TAB_3 "%s\n", to_string(e));
                printf(_TAB_2 "Actual:\n" _TAB_3 "%s\n", to_string(a));
            }
            exit(1);
        }
    }
    printf(_TAB_1 "Success\n");
}
