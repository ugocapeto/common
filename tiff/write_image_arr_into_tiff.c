#include <stdlib.h>
#include <stdio.h>
#include <tiffio.h>
#include "tiff_proto.h"

void write_image_arr_into_tiff(
 char *file_name,
 int width,
 int heigh,
 int *image_arr
)

{

 int size;
 int sampleperpixel;
 unsigned char *I_char;
 int ind;

 sampleperpixel= 1;
 size= width*heigh*sampleperpixel*sizeof(unsigned char);
 I_char= (unsigned char *)malloc(size);
 for ( ind= 0 ; ind< width*heigh*sampleperpixel ; ind++ )
  I_char[ind]= (unsigned char)image_arr[ind];
 write_tiff(file_name,I_char,width,heigh,sampleperpixel);
 free(I_char);

}
