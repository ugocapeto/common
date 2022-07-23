void read_tiff_into_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr
);

void read_tiff_into_image_alpha_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr,
 int **palpha_arr
);

void read_tiff_into_rgb_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr
);

void read_tiff_into_rgba_image_arr(
 char *filename,
 int *pw,
 int *ph,
 int **pimage_arr,
 int **palpha_arr
);

void write_image_arr_into_tiff(
 char *file_name,
 int width,
 int heigh,
 int *image_arr
);

void write_rgb_image_arr_into_tiff(
 char *file_name,
 int width,
 int heigh,
 int *image_arr
);

void write_rgba_image_arr_into_tiff(
 char *file_name,
 int width,
 int heigh,
 int *image_arr,
 int *alpha_arr
);

void write_tiff(
 char *filename,
 unsigned char *data,
 int w,
 int h,
 int sampleperpixel
);
