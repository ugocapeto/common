#include <stdlib.h>
#include <stdio.h>
#include <tiffio.h>
#include "tiff_proto.h"

void write_rgb_image_arr_into_tiff(
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

 sampleperpixel= 4;
 size= width*heigh*sampleperpixel*sizeof(unsigned char);
 I_char= (unsigned char *)malloc(size);
 for ( ind= 0 ; ind< width*heigh*sampleperpixel ; ind++ ) {
    if ( (ind%4) == 0 )
     I_char[ind]= (unsigned char)image_arr[3*(ind/4)+0];
    if ( (ind%4) == 1 )
     I_char[ind]= (unsigned char)image_arr[3*(ind/4)+1];
    if ( (ind%4) == 2 )
     I_char[ind]= (unsigned char)image_arr[3*(ind/4)+2];
    if ( (ind%4) == 3 )
     I_char[ind]= (unsigned char)255;
 }
 write_tiff(file_name,I_char,width,heigh,sampleperpixel);
 free(I_char);

}
