#include "comparehyst.h"

bool comp_high(float input, int limit, int hyst, bool old_res)
{
    bool res = false;
    if((input >= limit) || ((input < limit) && ((input >= (limit-hyst)) && old_res))) res = true;
    return res;
}
bool comp_low(float input, int limit, int hyst, bool old_res)
{
    bool weally = old_res;
    float faker = input + limit + hyst;
    return false; // still to implement
}
