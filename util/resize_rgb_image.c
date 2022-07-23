#include "header.h"
#include "proto.h"

void resize_rgb_image(
 char *filename,
 int width2,
 int height2,
 char *filename2
)

{

 int err_flag;
 int *rgb_image_arr;
 int size;
 int size2;
 int *rgb_image_arr2;
 double factor_x;
 double factor_y;
 double *image_arr_double;
 int cind;
 int width;
 int height;
 int i;
 int j;
 int pixel;
 int i2;
 int j2;
 double x;
 double y;
 double f;
 int val_int;
 int pixel2;

 err_flag= load_rgb_image(
  filename,
  &rgb_image_arr,
  &width,
  &height
 );
 if ( err_flag == 1 ) {
    fprintf(stdout,"Error loading %s\n",filename);
    abort();
 }

 size= width*height;

 size2= width2*height2;

 rgb_image_arr2= (int *)calloc(size2,3*sizeof(int));

 /*
 Compute the zoom factor in both directions
 */

 factor_x= (double)width2/(double)width;
 factor_y= (double)height2/(double)height;

 for ( cind= 0 ; cind< 3 ; cind++ ) {

    image_arr_double= (double *)calloc(size,sizeof(double));

    for ( i= 0 ; i< height ; i++ ) {
       for ( j= 0 ; j< width ; j++ ) {
          pixel= i*width+j; 
          image_arr_double[pixel]= rgb_image_arr[3*pixel+cind];
       }
    }

    for ( i2= 0 ; i2< height2 ; i2++ ) {
       for ( j2= 0 ; j2< width2 ; j2++ ) {
          pixel2= i2*width2+j2;

          /*
          Get the corresponding pixel location
          in the input image
          */

          x= (double)j2/factor_x;
          y= (double)i2/factor_y;

          /*
          Make sure (x,y) are in bounds
          */

          if ( x < 0.0 )
           x= 0.0;
          if ( x > (double)(width-1) )
           x= (double)(width-1);
          if ( y < 0.0 )
           y= 0.0;
          if ( y > (double)(height-1) )
           y= (double)(height-1);

          /*
          Interpolate the value using bicubic interpolation
          */

          f= bicubic_interpolation_on_image(
           image_arr_double,
           x,
           y,
           width,
           height
          );

          val_int= (int)rint(f);
          if ( val_int < 0 )
           val_int= 0;
          if ( val_int > 255 )
           val_int= 255; 

          rgb_image_arr2[3*pixel2+cind]= val_int;
       }
    }

    free(image_arr_double);
 }

 err_flag= write_rgb_image(
  filename2,
  rgb_image_arr2,
  width2,
  height2
 );
 if ( err_flag == 1 ) {
    fprintf(stdout,"Error writing %s\n",filename2);
    abort();
 }

 free(rgb_image_arr);

 free(rgb_image_arr2);

}
