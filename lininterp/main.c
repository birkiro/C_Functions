#include <stdio.h>
#include "lininterp.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#define ARRSIZE 7

int main()
{
    double x[ARRSIZE] = {1000,2000,3000,4000,5000,6000,7000};
    double y[ARRSIZE] = {4500,5500,6500,8500,10000,12000,15000};

    while(1)
    {
        double setpoint;
        printf("Enter Setpoint: ");
        scanf_s("%lf", &setpoint);
        double myRes = 0;

        if (lininterp(x, y, setpoint, ARRSIZE, &myRes) == NOERROR)
            printf("Result: %f \n", myRes);
        else
            printf("ERROR!");

    }
    return 0;
}
