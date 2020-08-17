#include <stdio.h>
#include "lininterp.h"

int main()
{
    float x[7] = {1,2,3,4,5,6,7};
    float y[7] = {100,200,300,400,500,600,700};

    float setpoint = 2;
    float myRes = 0;

    if (lininterp(x, y, setpoint, &myRes) == NOERROR)
        printf("SUCCESS: Result: %f \n", myRes);
    else
        printf("ERROR!");

    printf("Hello World!\n");
    return 0;
}
