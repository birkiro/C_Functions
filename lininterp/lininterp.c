#include <stdbool.h>
#include <math.h>
#include "lininterp.h"

double interpolate(Point2 p0, Point2 p1, double sp)
{
    return (p0.y + ((sp - p0.x) / (p1.x - p0.x)) * (p1.y - p0.y));
}


int lininterp(double x[], double y[], double sp, int size, double* res)
{
    int i;
    Point2 p0 = { 0,0 };
    Point2 p1 = { 0,0 };
    bool foundInterpolation = false;
    bool needInterpolation = true;

    // Check if extrapolation is needed
    if (sp < x[0])
    {
        p0.x = x[0]; p0.y = y[0];
        p1.x = x[1]; p1.y = y[1];
        needInterpolation = false;
    }
    else if (sp > x[size - 1])
    {
        p0.x = x[size - 2]; p0.y = y[size - 2];
        p1.x = x[size - 1]; p1.y = y[size - 1];
        needInterpolation = false;
    }

    // Check if setpoint hits any of the setpoints and if the ORDER is OK
    for (i = 1; i < size; ++i)
    {
        if (x[i - 1] >= x[i]) return ERRXORDER;
        if (needInterpolation && i == 1) // Check for x[0] in the first loop - done inside for-loop to make sure XORDER check is carried out first
        {
            if (fabs(sp - x[0]) < SP_TOLLERANCE) // Use SP_TOLLERANCE to compare floats
            {
                *res = y[0];
                return NOERROR;
            }
        }
        if (needInterpolation && fabs(sp - x[i]) < SP_TOLLERANCE)
        {
            *res = y[i];
            return NOERROR;
        }
        if (needInterpolation && sp < x[i] && !foundInterpolation)
        {
            p0.x = x[i - 1]; p0.y = y[i - 1];
            p1.x = x[i]; p1.y = y[i];
            foundInterpolation = true;
        }
    }

    *res = interpolate(p0, p1, sp);

    return NOERROR;
}

