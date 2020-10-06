#include <stdio.h>
#include <stdbool.h>

typedef   bool (*Operation)(float in, int lim, int hy, bool old);

typedef struct compare {
    int  result ;       // to sotre the resut
    Operation  opt;     // funtion pointer
 } Compare;

bool comp_high(float input, int limit, int hyst, bool old_res);

bool comp_low(float input, int limit, int hyst, bool old_res);
