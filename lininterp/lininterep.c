#include "lininterp.h"

int lininterp(float x[TRIGGERS], float y[TRIGGERS], float sp, float* res)
{
    Point2 p0;
    Point2 p1;

    // Check if x is increasing
    for (int i = 0; i < (TRIGGERS - 1); i++)
        if (x[i] <= x[i+1]) return XORDER;

    // check if the setpoint hits any of the x points
    for (int i = 0; i < TRIGGERS; i++)
    {
        if (sp == x[i]) *res = sp;
        return NOERROR;
    }

    // Check if extrapolation is needed
    if (sp < x[0])
    {
        p0.x = x[0]; p0.y = y[0];
        p1.x = x[1]; p1.y = y[1];
    }
    else if (sp > x[TRIGGERS])
    {
        p0.x = x[TRIGGERS-1]; p0.y = y[TRIGGERS-1];
        p1.x = x[TRIGGERS]; p1.y = y[TRIGGERS];
    }
    else // interpolation is done
    {
        for (int i = 1; i < TRIGGERS; i++)
        {
            if (sp < x[i])
            {
                p0.x = x[i-1]; p0.y = y[i-1];
                p1.x = x[i]; p1.y = y[i];
            }
        }
    }

    interpolate(p0, p1, sp);

    return NOERROR;
}

float interpolate(Point2 p0, Point2 p1, float sp)
{
    return (p0.y + ((sp - p0.x) / (p1.x - p0.x)) * (p1.y - p0.y));
}
