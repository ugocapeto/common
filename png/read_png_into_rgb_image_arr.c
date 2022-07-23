#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include "png_proto.h"

void read_png_into_rgb_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr
)

{

 int w;
 int h;
 int *image_arr;
 int *alpha_arr;

 read_png_into_rgba_image_arr(
  filename,
  &w,
  &h,
  &image_arr,
  &alpha_arr
 );

 free(alpha_arr);

 (*pw)= w;
 (*ph)= h;

 (*pimage_arr)= image_arr;

}
