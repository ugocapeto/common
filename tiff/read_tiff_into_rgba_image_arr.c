#include <stdlib.h>
#include <stdio.h>
#include <tiffio.h>
#include "tiff_proto.h"

void read_tiff_into_rgba_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr,
 int **palpha_arr
)

{

 TIFF* tif;
 uint32 w;
 uint32 h;
 size_t npixels;
 uint32* raster;
 uint32 i;
 uint32 j;
 uint32 ind;
 uint32 r;
 uint32 g;
 uint32 b;
 uint32 a;
 int size;
 int *image_arr;
 int *alpha_arr;

 tif= TIFFOpen(filename,"r");

 TIFFGetField(tif,TIFFTAG_IMAGEWIDTH,&w);

 TIFFGetField(tif,TIFFTAG_IMAGELENGTH,&h);

 npixels= w*h;

 raster= (uint32*)_TIFFmalloc(npixels*sizeof(uint32));

 TIFFReadRGBAImageOriented(tif,w,h,raster,ORIENTATION_TOPLEFT,0);

 TIFFClose(tif);

 size= w*h*3*sizeof(int);
 image_arr= (int *)malloc(size);
 size= w*h*1*sizeof(int);
 alpha_arr= (int *)malloc(size);

 for ( i= 0 ; i< h ; i++ ) {
    for ( j= 0 ; j< w ; j++ ) {
       ind= i*w+j;
       r= TIFFGetR(raster[ind]);
       g= TIFFGetG(raster[ind]);
       b= TIFFGetB(raster[ind]);
       a= TIFFGetA(raster[ind]);
       image_arr[3*ind+0]= r;
       image_arr[3*ind+1]= g;
       image_arr[3*ind+2]= b;
       alpha_arr[ind]= a;
    }
 }

 _TIFFfree(raster);

 (*pw)= w;
 (*ph)= h;
 (*pimage_arr)= image_arr;
 (*palpha_arr)= alpha_arr;

}
