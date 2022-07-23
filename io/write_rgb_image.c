#include "header.h"

int write_rgb_image(
 char *filename,
 int *image_arr,
 int width,
 int height
)

/*
Returns 0 (no error) if was able to write the image
Otherwise returns 1 (error)
*/

{

 char *ext;

 ext= strrchr(filename,'.');

 if ( strcmp(ext+1,"tiff") == 0 ||
      strcmp(ext+1,"TIFF") == 0 ||
      strcmp(ext+1,"tif")  == 0 ||
      strcmp(ext+1,"TIF")  == 0 ) {

    write_rgb_image_arr_into_tiff(
     filename,
     width,
     height,
     image_arr
    );
 }
 else if ( strcmp(ext+1,"png") == 0 ||
           strcmp(ext+1,"PNG") == 0 ) {

    write_rgb_image_arr_into_png(
     filename,
     width,
     height,
     image_arr
    );
 }
 else if ( strcmp(ext+1,"jpeg") == 0 ||
           strcmp(ext+1,"JPEG") == 0 ||
           strcmp(ext+1,"jpg")  == 0 ||
           strcmp(ext+1,"JPG")  == 0 ) {

    write_rgb_image_arr_into_jpeg(
     filename,
     width,
     height,
     image_arr
    );
 }
 else {
    fprintf(stdout,"Filename extension for %s not recognized!\n",
     filename);
    fprintf(stdout,"Supported: tiff, TIFF, tif, TIF, png, PNG, jpeg, JPEG, jpg, JPG\n");
    return 1;
 }

 return 0;

}
