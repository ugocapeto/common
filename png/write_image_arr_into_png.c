#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include "png_proto.h"

void write_image_arr_into_png(
 char *filename,
 int width,
 int height,
 int *image_arr
)

{

 int *image_rgb_arr;
 int i;
 int j;
 int ind;

 image_rgb_arr= (int *)calloc(width*height,3*sizeof(int));

 for ( i= 0 ; i< height ; i++ ) {
    for ( j= 0 ; j< width ; j++ ) {
       ind= i*width+j;
       image_rgb_arr[3*ind+0]= image_arr[ind];
       image_rgb_arr[3*ind+1]= image_arr[ind];
       image_rgb_arr[3*ind+2]= image_arr[ind];
    }
 }

 write_rgb_image_arr_into_png(
  filename,
  width,
  height,
  image_rgb_arr
 );

 free(image_rgb_arr);

}
