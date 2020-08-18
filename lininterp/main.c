#include <stdio.h>
#include "lininterp.h"

int main()
{
    float x[7] = {1000,2000,3000,4000,5000,6000,7000};
    float y[7] = {300,350,400,450,500,550,600};

    float setpoint = 11.0f;
    float myRes = 0;

    if (lininterp(x, y, setpoint, &myRes) == NOERROR)
        printf("SUCCESS: Result: %f \n", myRes);
    else
        printf("ERROR!");

    return 0;
}
