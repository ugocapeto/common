int load_image(
 char *filename,
 int **pimage_arr,
 int *pwidth,
 int *pheight
);

int load_rgba_image(
 char *filename,
 int **pimage_arr,
 int **palpha_arr,
 int *pwidth,
 int *pheight
);

int load_rgb_image(
 char *filename,
 int **pimage_arr,
 int *pwidth,
 int *pheight
);

int write_image(
 char *filename,
 int *image_arr,
 int width,
 int height
);

int write_rgba_image(
 char *filename,
 int *image_arr,
 int *alpha_arr,
 int width,
 int height
);

int write_rgb_image(
 char *filename,
 int *image_arr,
 int width,
 int height
);
