#include <stdlib.h>
#include <stdio.h>
#include <png.h>

void write_rgba_image_arr_into_png(
 char *filename,
 int width,
 int height,
 int *image_arr,
 int *alpha_arr
)

/*
This is taken from libpng_test.c by Guillaume Cottenceau
found by searching the net for "libpng read write"
*/

{

png_bytep *row_pointers;

  int y;
  int x; 

  FILE *fp = fopen(filename, "wb");
  if(!fp) abort();

  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png) abort();

  png_infop info = png_create_info_struct(png);
  if (!info) abort();

  if (setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  // Output is 8bit depth, RGBA format.
  png_set_IHDR(
    png,
    info,
    width, height,
    8,
    PNG_COLOR_TYPE_RGBA,
    PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_DEFAULT,
    PNG_FILTER_TYPE_DEFAULT
  );
  png_write_info(png, info);

  // To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
  // Use png_set_filler().
  //png_set_filler(png, 0, PNG_FILLER_AFTER);

  /*
  Copy image into the proper the row_pointers data structure
  */

  row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);

  for(y = 0; y < height; y++) {
    row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
    png_bytep row = row_pointers[y];
    for(x = 0; x < width; x++) {
      row[x * 4+0]=image_arr[3*(y*width+x)+0];
      row[x * 4+1]=image_arr[3*(y*width+x)+1];
      row[x * 4+2]=image_arr[3*(y*width+x)+2];
      row[x * 4+3]=alpha_arr[y*width+x];
    }
  }

  /*
  Done copying
  */

  png_write_image(png, row_pointers);
  png_write_end(png, NULL);

  /* clean up after the write, and free any memory allocated */
  png_destroy_write_struct(&png, &info);

  for(y = 0; y < height; y++) {
    free(row_pointers[y]);
  }
  free(row_pointers);

  fclose(fp);

}
