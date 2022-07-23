void read_jpeg_into_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr
);

void read_jpeg_into_rgb_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr
);

void write_image_arr_into_jpeg(
 char *filename,
 int width,
 int height,
 int *image_arr
);

void write_rgb_image_arr_into_jpeg(
 char *filename,
 int width,
 int height,
 int *image_arr
);
