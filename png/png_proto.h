void read_png_into_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr
);

void read_png_into_rgba_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr,
 int **palpha_arr
);

void read_png_into_rgb_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr
);

void write_image_arr_into_png(
 char *filename,
 int width,
 int height,
 int *image_arr
);

void write_rgba_image_arr_into_png(
 char *filename,
 int width,
 int heigh,
 int *image_arr,
 int *alpha_arr
);

void write_rgb_image_arr_into_png(
 char *filename,
 int width,
 int height,
 int *image_arr
);
