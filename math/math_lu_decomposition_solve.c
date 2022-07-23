#include "header.h"
#include "proto.h"

void math_lu_decomposition_solve(
 int n,
 double *A,
 double *b,
 double *x
)

/*
Solve A*x=b where
A is a nxn matrix
b is a vector of size n
x is a vector of size n
*/

{

 double **A2;
 double d;
 int i;
 int j;
 double *b2;
 int *indx;

 /*
 Copy A into A2
 A is indexed from 0 to n-1
 A2 is indexed from 1 to n
 */

 A2= (double **)calloc(n+1,sizeof(double *));
 for ( i= 0 ; i< n ; i++ ) {
    A2[i+1]= (double *)calloc(n+1,sizeof(double));
    for ( j= 0 ; j< n ; j++ )
     A2[i+1][j+1]= A[i*n+j];
 }

 /*
 Copy b into b2
 b is indexed from 0 to n-1
 b2 is indexed from 1 to n
 */

 b2= (double *)calloc(n+1,sizeof(double));
 for ( i= 0 ; i< n ; i++ ) 
  b2[i+1]= b[i];

 /*
 Allocate memory for indx
 */

 indx= (int *)calloc(n+1,sizeof(int));

 /*
 Perform LU decomposition
 */

 math_ludcmp(
  A2,
  n,
  indx,
  &d
 );

 /*
 Perform forward substitution and backward substitution
 The solution is put into b2
 */

 math_lubksb(
  A2,
  n,
  indx,
  b2
 );

 /*
 Copy b2 into x
 x is indexed from 0 to n-1
 b2 is indexed from 1 to n
 */

 for ( i= 0 ; i< n ; i++ )
  x[i]= b2[i+1];

 /*
 Free A2
 */

 for ( i= 0 ; i< n ; i++ ) {
    free(A2[i+1]);
 }
 free(A2);

 /*
 Free b2
 */

 free(b2);

 /*
 Free indx
 */

 free(indx);

}
