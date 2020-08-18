
#define TRIGGERS 7

enum ErrorCodes
{
    NOERROR   = 0,
    ERRVALNOTSET = 1,
    ERRCALC   = 2,
    ERRXORDER    = 3
};

typedef struct Point2 {
    float x;
    float y;
} Point2;

int lininterp(float x[TRIGGERS], float y[TRIGGERS], float sp, float* res);
