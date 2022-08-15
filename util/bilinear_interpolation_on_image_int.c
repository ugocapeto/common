#include "header.h"
#include "proto.h"

double bilinear_interpolation_on_image_int(
 int *image_arr,
 int width,
 int height,
 double x,
 double y
)

/*
image_arr is a grayscale image (1 color channel)
where the values are between 0 and 255
*/

/*
0 <= x < width
0 <= y < height
*/

{

 int i1;
 int i2;
 int j1;
 int j2;
 double p11;
 double p12;
 double p21;
 double p22;
 double q1;
 double q2;
 double dval;

 if ( !(0 <= x) )
  error_handler((char *)"bilinear_interpolation_on_image");
 if ( !(x < width) )
  error_handler((char *)"bilinear_interpolation_on_image");
 if ( !(0 <= y) )
  error_handler((char *)"bilinear_interpolation_on_image");
 if ( !(y < height) )
  error_handler((char *)"bilinear_interpolation_on_image");

 i1= (int)y;
 i2= i1+1;

 j1= (int)x;
 j2= j1+1;

 /*
 Repeat the point if out of bounds
 */

 if ( i2 == height )
  i2= height-1;
 if ( j2 == width )
  j2= width-1;

 /*
 Row 1
 */

 p11= (double)image_arr[i1*width+j1];
 p12= (double)image_arr[i1*width+j2];

 /*
 Row 2
 */

 p21= (double)image_arr[i2*width+j1];
 p22= (double)image_arr[i2*width+j2];

 /*
 Let's first interpolate along the columns
 */

 /*
 Column 1
 */

 q1= linear_interpolation(
  p11,
  p21,
  y-i1
 );

 /*
 Column 2
 */

 q2= linear_interpolation(
  p12,
  p22,
  y-i1
 );

 /*
 Finally, interpolate horizontally
 */

 dval= linear_interpolation(
  q1,
  q2,
  x-j1
 );

 return dval;

}
