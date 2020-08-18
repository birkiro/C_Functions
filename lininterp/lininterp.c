#include <stdbool.h>
#include "lininterp.h"

float interpolate(Point2 p0, Point2 p1, float sp)
{
    return (p0.y + ((sp - p0.x) / (p1.x - p0.x)) * (p1.y - p0.y));
}

int lininterp(float x[TRIGGERS], float y[TRIGGERS], float sp, float* res)
{
    int i;
    Point2 p0 = {0,0};
    Point2 p1 = {0,0};

    // Check if x is increasing
    for (i = 0; i < (TRIGGERS - 1); i++)
        if (x[i] >= x[i+1]) return ERRXORDER;

    // check if the setpoint hits any of the x points
    for (i = 0; i < TRIGGERS; i++)
    {
        if (sp == x[i])
        {
            *res = y[i];
            return NOERROR;
        }
    }

    // Check if extrapolation is needed
    if (sp < x[0])
    {
        p0.x = x[0]; p0.y = y[0];
        p1.x = x[1]; p1.y = y[1];
    }
    else if (sp > x[TRIGGERS-1])
    {
        p0.x = x[TRIGGERS-2]; p0.y = y[TRIGGERS-2];
        p1.x = x[TRIGGERS-1]; p1.y = y[TRIGGERS-1];
    }
    else // interpolation is needed
    {
        bool done = false;
        for (i = 1; i < TRIGGERS; i++)
        {
            if (sp < x[i] && !done)
            {
                p0.x = x[i-1]; p0.y = y[i-1];
                p1.x = x[i]; p1.y = y[i];
                done = true;
            }
        }
    }

    *res = interpolate(p0, p1, sp);

    return NOERROR;
}
