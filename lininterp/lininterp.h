#define SP_TOLLERANCE 0.02

enum ErrorCodes
{
    NOERROR   = 0x00,
    ERRVALNOTSET = 0x08,
    ERRCALC   = 0x10,
    ERRXORDER    = 0x20
};

typedef struct Point2 {
    double x;
    double y;
} Point2;

int lininterp(double x[], double y[], double sp, int size, double* res);
