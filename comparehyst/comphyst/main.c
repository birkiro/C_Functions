#include <stdio.h>
#include "comparehyst.h"

int main()
{
    int i;
    int hyst = 500;
    int limit = 500;
    for (i = 0; i < 1000; i = i + 50)
    {
        printf("input: %d, hyst: %d, result: %d \n", i, hyst, comparehyst(i, limit, hyst));
    }

    for(i = 1000; i > 0; i = i - 50)
    {
        printf("input: %d, hyst: %d, result: %d \n", i, hyst, comparehyst(i, limit, hyst));
    }
    return 0;
}
