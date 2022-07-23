#include "header.h"
#include "proto.h"

void rgb_image_to_Lab(
 int *rgb_image_arr,
 double *Lab_image_arr,
 int width,
 int height
)

{

 int i;
 int j;
 int ind;
 double r;
 double g;
 double b;
 double x;
 double y;
 double z;
 double L;
 double a;
 //double b;

 for ( i= 0 ; i< height ; i++ ) {
    for ( j= 0 ; j< width ; j++ ) {
       ind= i*width+j;
       r= rgb_image_arr[3*ind+0];
       g= rgb_image_arr[3*ind+1];
       b= rgb_image_arr[3*ind+2];
       rgb2xyz(r,g,b,&x,&y,&z);
       xyz2Lab(x,y,z,&L,&a,&b);
       Lab_image_arr[3*ind+0]= L;
       Lab_image_arr[3*ind+1]= a;
       Lab_image_arr[3*ind+2]= b;
    }
 }

}
