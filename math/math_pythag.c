#include "header.h"
#include "proto.h"

double math_pythag(
 double a,
 double b
)
/* compute (a2 + b2)^1/2 without destructive underflow or overflow */
{
        double absa,absb;
        absa=fabs(a);
        absb=fabs(b);
        if (absa > absb) return absa*sqrt(1.0+(absb/absa)*(absb/absa));
        else return (absb == 0.0 ? 0.0 : absb*sqrt(1.0+(absa/absb)*(absa/absb)));
}
