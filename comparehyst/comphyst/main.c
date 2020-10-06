#include "comparehyst.h"

int main()
{
    Compare compare;            // create an instance
    compare.opt = comp_high;    // tell it what function to use, be it comp_high, comp_low or comp_window

    int i;
    int hyst = 60;
    int limit = 200;
    for (i = 0; i < 500; i = i + 25)
    {
        compare.result = compare.opt(i, limit, hyst, compare.result);  // important! save the result because it will depend on it in next loop
        printf("input: %d, hyst: %d, result: %d \n", i, hyst, compare.result);
    }
    for (i = 500; i > 0; i = i - 25)
    {
        compare.result = compare.opt(i, limit, hyst, compare.result);   // important! save the result because it will depend on it in next loop
        printf("input: %d, hyst: %d, result: %d \n", i, hyst, compare.result);
    }

    return 0 ;
}
