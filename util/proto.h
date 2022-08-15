double bicubic_interpolation_on_image(
 double *I,
 double x,
 double y,
 int xdim,
 int ydim
);

double bicubic_interpolation_on_image_int(
 int *image_arr,
 double x,
 double y,
 int xdim,
 int ydim
);

double bilinear_interpolation_on_image_int(
 int *image_arr,
 int width,
 int height,
 double x,
 double y
);

double cubic_interpolation(
 double p0,
 double p1,
 double p2,
 double p3,
 double x
);

void error_handler(
 char* from
);

double F(
 double input
);

void get_random_dbl(
 double min_dbl,
 double max_dbl,
 double *prand_dbl
);

void get_random_int(
 int min_int,
 int max_int,
 int *prand_int
);

double linear_interpolation(
 double p1,
 double p2,
 double x
);

void resize_rgb_image(
 char *filename,
 int width2,
 int height2,
 char *filename2
);

void rgb2xyz(
 double r,
 double g,
 double b,
 double *x,
 double *y,
 double *z
);

void rgb_image_to_Lab(
 int *rgb_image_arr,
 double *Lab_image_arr,
 int width,
 int height
);

void xyz2Lab(
 double x,
 double y,
 double z,
 double *L,
 double *a,
 double *b
);
