#include "header.h"

int load_rgba_image(
 char *filename,
 int **pimage_arr,
 int **palpha_arr,
 int *pwidth,
 int *pheight
)

/*
Returns 0 (no error) if was able to load the image
Otherwise returns 1 (error)
*/

{

 char *ext;
 int width;
 int height;
 int *image_arr;
 int *alpha_arr;

 ext= strrchr(filename,'.');

 if ( strcmp(ext+1,"tiff") == 0 ||
      strcmp(ext+1,"TIFF") == 0 ||
      strcmp(ext+1,"tif")  == 0 ||
      strcmp(ext+1,"TIF")  == 0 ) {

    read_tiff_into_rgba_image_arr(
     filename,
     &width,
     &height,
     &image_arr,
     &alpha_arr
    );
 }
 else if ( strcmp(ext+1,"png") == 0 ||
           strcmp(ext+1,"PNG") == 0 ) {

    read_png_into_rgba_image_arr(
     filename,
     &width,
     &height,
     &image_arr,
     &alpha_arr
    );
 }
 else {
    fprintf(stdout,"Filename extension for %s not recognized!\n",
     filename);
    fprintf(stdout,"Supported: tiff, TIFF, tif, TIF, png, PNG\n");
    return 1;
 }

 (*pimage_arr)= image_arr;
 (*palpha_arr)= alpha_arr;
 (*pwidth)= width;
 (*pheight)= height;

 return 0;

}
