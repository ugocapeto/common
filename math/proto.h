void math_amoeba(
 double **p,
 double y[],
 int ndim,
 double ftol,
 double (*funk)(double []),
 int *nfunk
);

double math_amotry(
 double **p,
 double *y,
 double *psum,
 int ndim,
 double (*funk)(double []),
 int ihi,
 int *nfunk,
 double fac
);

double math_brent(
 double ax,
 double bx,
 double cx,
 double (*f)(double),
 double tol,
 double *xmin
);

void math_cross_product_matrix(
 double x[3],
 double A[3*3]
);

double **math_dmatrix(
 int nrl,
 int nrh,
 int ncl,
 int nch
);

double *math_dvector(
 int nl,
 int nh
);

void math_error_handler(
 char* from
);

double math_f1dim(
 double x
);

void math_free_dvector(
 double *v,
 int nl,
 int nh
);

void math_linmin(
 double p[],
 double xi[],
 int n,
 double *fret,
 double (*func)(double [])
);

void math_lubksb(
 double **a,
 int n,
 int *indx,
 double *b
);

void math_ludcmp(
 double **a,
 int n,
 int *indx,
 double *d
);

double math_lu_decomposition_determinant(
 int n,
 double *A
);

void math_lu_decomposition_inverse(
 int n,
 double *A,
 double *B
);

void math_lu_decomposition_solve(
 int n,
 double *A,
 double *b,
 double *x
);

double math_matrix2x2_determinant(
 double A[2*2]
);

double math_matrix3x3_determinant(
 double A[3*3]
);

void math_matrix3x3_inverse(
 double A[3*3],
 double B[3*3]
);

void math_matrix_matrix_product(
 double *A1,
 int nrow1,
 int ncol1,
 double *A2,
 int nrow2,
 int ncol2,
 double *B
);

void math_mnbrak(
 double *ax,
 double *bx,
 double *cx,
 double *fa,
 double *fb,
 double *fc,
 double (*func)(double)
);

void math_matrix_remove_row_col(
 double *A,
 int nrow,
 int ncol,
 int inp_i,
 int inp_j,
 double *B
);

void math_matrix_transpose(
 double *A,
 int nrow,
 int ncol,
 double *B
);

void math_matrix_vector_product(
 double *A1,
 int nrow1,
 int ncol1,
 double *a2,
 int nrow2,
 double *b
);

void math_nrerror(
 char error_text[]
);

void math_powell(
 double p[],
 double **xi,
 int n,
 double ftol,
 int *iter,
 double *fret,
 double (*func)(double [])
);

double math_pythag(
 double a,
 double b
);

void math_singular_value_decomposition(
 int m,
 int n,
 double *A,
 double *U,
 double *w,
 double *V
);

void math_singular_value_decomposition_solve(
 int m,
 int n,
 double *A,
 double *b,
 double *x
);

void math_svbksb(
 double **u,
 double w[],
 double **v,
 int m,
 int n,
 double b[],
 double x[]
);

void math_svdcmp(
 double **a,
 int m,
 int n,
 double w[],
 double **v
);

double math_vector_vector_product(
 double *a1,
 int n1,
 double *a2,
 int n2
);
