
#define TRIGGERS 7

enum ErrorCodes
{
    NOERROR   = 0,
    VALNOTSET = 1,
    CALCERR   = 2,
    XORDER    = 3
};

typedef struct Point2 {
    float x;
    float y;
} Point2;

int lininterp(float x[TRIGGERS], float y[TRIGGERS], float sp, float* res);

float interpolate(Point2 p0, Point2 p1, float sp);
