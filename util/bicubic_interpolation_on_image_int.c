#include "header.h"
#include "proto.h"

double bicubic_interpolation_on_image_int(
 int *image_arr,
 double x,
 double y,
 int xdim,
 int ydim
)

/*
Interpolate the value of the intensity at (x,y)
*/

/*
x is assumed to be between 0 and (xdim-1)
0 <= x <= (xdim-1)
y is assumed to be between 0 and (ydim-1)
0 <= y <= (ydim-1)
*/

{

 int i0;
 int i1;
 int i2;
 int i3;
 int j0;
 int j1;
 int j2;
 int j3;
 double p00;
 double p01;
 double p02;
 double p03;
 double p10;
 double p11;
 double p12;
 double p13;
 double p20;
 double p21;
 double p22;
 double p23;
 double p30;
 double p31;
 double p32;
 double p33;
 double q0;
 double q1;
 double q2;
 double q3;
 double f;

 /*
 Recall that x is the horizontal coordinate
 going from left to right
 Recall that y is the vertical coordinate
 going from top to bottom
 It is assumed that 0 <= x <= (xdim-1)
 It is assumed that 0 <= y <= (ydim-1)
 */

 if ( !(x >= 0) )
  error_handler((char *)"bicubic_interpolation_on_image");
 if ( !(x <= (xdim-1)) )
  error_handler((char *)"bicubic_interpolation_on_image");
 if ( !(y >= 0) )
  error_handler((char *)"bicubic_interpolation_on_image");
 if ( !(y <= (ydim-1)) )
  error_handler((char *)"bicubic_interpolation_on_image");

 /*
 i is gonna represent the row
 j is gonna represent the column
 */

 /*
 Let's gather the 4x4 matrix of points
 Recall that (x,y) is supposed to lie somewhere
 in the p11,p12,p21,p22 square
 */

 i1= (int)y;
 if ( i1 == (ydim-1) )
  i1--;
 i0= i1-1;
 i2= i1+1;
 i3= i2+1;

 j1= (int)x;
 if ( j1 == (xdim-1) )
  j1--;
 j0= j1-1;
 j2= j1+1;
 j3= j2+1;

 /*
 Repeat the point if out of bounds
 */

 if ( i0 == -1 )
  i0= i1;
 if ( i3 == ydim )
  i3= i2;
 if ( j0 == -1 )
  j0= j1;
 if ( j3 == xdim )
  j3= j2;

 /*
 Row 0
 */

 p00= (double)image_arr[xdim*i0+j0];
 p01= (double)image_arr[xdim*i0+j1];
 p02= (double)image_arr[xdim*i0+j2];
 p03= (double)image_arr[xdim*i0+j3];

 /*
 Row 1
 */

 p10= (double)image_arr[xdim*i1+j0];
 p11= (double)image_arr[xdim*i1+j1];
 p12= (double)image_arr[xdim*i1+j2];
 p13= (double)image_arr[xdim*i1+j3];

 /*
 Row 2
 */

 p20= (double)image_arr[xdim*i2+j0];
 p21= (double)image_arr[xdim*i2+j1];
 p22= (double)image_arr[xdim*i2+j2];
 p23= (double)image_arr[xdim*i2+j3];

 /*
 Row 3
 */

 p30= (double)image_arr[xdim*i3+j0];
 p31= (double)image_arr[xdim*i3+j1];
 p32= (double)image_arr[xdim*i3+j2];
 p33= (double)image_arr[xdim*i3+j3];

 /*
 Let's first interpolate along the columns
 */

 /*
 Column 0
 */

 q0= cubic_interpolation(
  p00,
  p10,
  p20,
  p30,
  y-(double)i1
 );

 /*
 Column 1
 */

 q1= cubic_interpolation(
  p01,
  p11,
  p21,
  p31,
  y-(double)i1
 );

 /*
 Column 2
 */

 q2= cubic_interpolation(
  p02,
  p12,
  p22,
  p32,
  y-(double)i1
 );

 /*
 Column 3
 */

 q3= cubic_interpolation(
  p03,
  p13,
  p23,
  p33,
  y-(double)i1
 );

 /*
 Finally, interpolate horizontally
 */ 

 f= cubic_interpolation(
  q0,
  q1,
  q2,
  q3,
  x-(double)j1
 );

 return f;

}
