extern void (*_TESTS[2048])();
int main()
{
    for (int i = 0; _TESTS[i] != 0; i++)
    {
        _TESTS[i]();
    }
    return 0;
}