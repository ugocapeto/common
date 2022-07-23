#include "header.h"
#include "proto.h"

void math_singular_value_decomposition_solve(
 int m,
 int n,
 double *A,
 double *b,
 double *x
)

/*
Solve A*x=b where
A is a mxn matrix
b is a vector of size m
x is a vector of size n
*/

/*
Perform a Singular Value Decomposition
follwed by a back substitution
*/

{

 double **A2;
 int i;
 int j;
 double *w2;
 double **V2;
 double wmax;
 double wmin;
 double *b2;
 double *x2;
 double *Ax;

 /*
 Copy A into A2
 A is indexed from 0 to m-1 for the rows and 0 to n-1 for the columns
 A2 is indexed from 1 to n for the rows and 1 to n for the columns
 */

 A2= (double **)calloc(m+1,sizeof(double *));
 for ( i= 0 ; i< m ; i++ ) {
    A2[i+1]= (double *)calloc(n+1,sizeof(double));
    for ( j= 0 ; j< n ; j++ )
     A2[i+1][j+1]= A[i*n+j];
 }

 /*
 Allocator memory for w2
 w2 is indexed from 1 to n
 */

 w2= (double *)calloc(n+1,sizeof(double));

 /*
 Allocator memory for V2
 V2 is indexed from 1 to n
 */

 V2= (double **)calloc(n+1,sizeof(double *));
 for ( i= 0 ; i< n ; i++ ) {
    V2[i+1]= (double *)calloc(n+1,sizeof(double));
 }

 math_svdcmp(
  A2,
  m,
  n,
  w2,
  V2
 );

 /*
 As suggested in the Numerical Recipes book,
 zero the small singular values
 to avoid an ill-conditioned system
 */

 wmax= 0;
 for ( j= 1 ; j<= n ; j++ ) {
    if ( w2[j] > wmax ) wmax= w2[j];
 }
 wmin= wmax*1.0e-6;

 for ( j= 1 ; j<= n ; j++ ) {
    if ( w2[j] < wmin ) w2[j]= 0.0;
 }

 /*
 Copy b into b2
 b is indexed from 0 to m-1
 b2 is indexed from 1 to m
 */

 b2= (double *)calloc(m+1,sizeof(double));
 for ( i= 0 ; i< m ; i++ )
  b2[i+1]= b[i];

 /*
 Allocate memory for x2
 */

 x2= (double *)calloc(n+1,sizeof(double));

 /*
 Perform the back substitution
 */

 /*
 Recall that the U matrix in the svd decomposition
 is returned into the A matrix
 */

 math_svbksb(
  A2,
  w2,
  V2,
  m,
  n,
  b2,
  x2
 );

 /*
 Copy x2 into x
 x is indexed from 0 to n-1
 x2 is indexed from 1 to n
 */

 for ( j= 0 ; j< n ; j++ )
  x[j]= x2[j+1];

 /*
 Free A2
 */

 for ( i= 0 ; i< m ; i++ ) {
    free(A2[i+1]);
 }
 free(A2);

 /*
 Free w2
 */

 free(w2);

 /*
 Free V2
 */

 for ( i= 0 ; i< n ; i++ ) {
    free(V2[i+1]);
 }
 free(V2);

 /*
 Free b2
 */

 free(b2);

 /*
 Free x2
 */

 free(x2);

 /*
 Check!
 */

 Ax= (double *)calloc(m,sizeof(double));

 math_matrix_vector_product(
  A,
  m,
  n,
  x,
  n,
  Ax
 );

 free(Ax);

}
