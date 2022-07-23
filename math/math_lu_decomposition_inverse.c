#include "header.h"
#include "proto.h"

void math_lu_decomposition_inverse(
 int n,
 double *A,
 double *B
)

/*
Compute B = A^-1
*/

{

 double **A2;
 double d;
 int i;
 int j;
 int *indx;
 double *col;
 double **B2;

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
 Allocate memory for col
 */

 col= (double *)calloc(n+1,sizeof(double));

 /*
 Allocate memory for B2
 */

 B2= (double **)calloc(n+1,sizeof(double *));
 for ( i= 0 ; i< n ; i++ ) {
    B2[i+1]= (double *)calloc(n+1,sizeof(double));
 }

 for(j=1;j<=n;j++) {
      for(i=1;i<=n;i++) col[i]=0.0;
      col[j]=1.0;
      math_lubksb(
       A2,
       n,
       indx,
       col
      );
      for(i=1;i<=n;i++) B2[i][j]=col[i];
 }

 /*
 Copy B2 into B
 B is indexed from 0 to n-1
 B2 is indexed from 1 to n
 */

 for ( i= 0 ; i< n ; i++ ) {
    for ( j= 0 ; j< n ; j++ ) {
       B[i*n+j]= B2[i+1][j+1];
    }
 }

 /*
 Free A2
 */

 for ( i= 0 ; i< n ; i++ ) {
    free(A2[i+1]);
 }
 free(A2);

 /*
 Free indx
 */

 free(indx);

 /*
 Free col
 */

 free(col);

 /*
 Free B2
 */

 for ( i= 0 ; i< n ; i++ ) {
    free(B2[i+1]);
 }
 free(B2);

}
