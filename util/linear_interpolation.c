#include "header.h"
#include "proto.h"

double linear_interpolation(
 double p1,
 double p2,
 double x
)

/*
Do a linear interpolation for x
representing the parameter (between 0 and 1) of a point
placed between p1 and p2
*/

{

 double dval;

 if ( !(x >= 0) )
  error_handler((char *)"linear_interpolation");
 if ( !(x <= 1) )
  error_handler((char *)"linear_interpolation");

 dval= (1.-x)*p1+x*p2;

 return dval;

}
