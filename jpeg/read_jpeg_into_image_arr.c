#include <stdlib.h>
#include <stdio.h>
#include "jpeg_proto.h"

void read_jpeg_into_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr
)

{

 int width;
 int height;
 int *rgb_image_arr;
 int i;
 int j;
 int *image_arr;
 int r;
 int g;
 int b;
 double intensity;
 int ind;

 /*
 Read image as if it were a rgb image with 3 channels
 */

 read_jpeg_into_rgb_image_arr(
  filename,
  &width,
  &height,
  &rgb_image_arr
 );

 /*
 Allocate memory for the single channel (grayscale) image
 */

 image_arr= (int *)calloc(width*height,sizeof(int));

 for ( i= 0 ; i< height ; i++ ) {
    for ( j= 0 ; j< width ; j++ ) {
       ind= i*width+j;
       r= rgb_image_arr[3*ind+0];
       g= rgb_image_arr[3*ind+1];
       b= rgb_image_arr[3*ind+2];
       intensity= .2989*(double)r+.5870*(double)g+.1140*(double)b;
       image_arr[ind]= r;
    }
 }

  (*pw)= width;
  (*ph)= height;
  (*pimage_arr)= image_arr;

 /*
 Free the rgb image
 */

 free(rgb_image_arr);

}
