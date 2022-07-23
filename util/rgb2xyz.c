#include "header.h"
#include "proto.h"

void rgb2xyz(
 double r,
 double g,
 double b,
 double *x,
 double *y,
 double *z
)

{

 /*
 (*x)= 0.412453*r+0.357580*g+0.189423*b;
 */
 (*x)= 0.412453*r+0.357580*g+0.180423*b;
 (*y)= 0.212671*r+0.715160*g+0.072169*b;
 (*z)= 0.019334*r+0.119193*g+0.950227*b;

}
