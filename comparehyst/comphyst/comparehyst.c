#include "comparehyst.h"

bool comparehyst(float input, int limit, int hyst)
{
    static bool out_old;
    bool out = false;

    if((input >= limit) || ((input < limit) && ((limit-hyst) && out_old))) out = true;
    else out = false;

    out_old = out;
    return out;
}


