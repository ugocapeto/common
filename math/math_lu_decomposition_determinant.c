#include "header.h"
#include "proto.h"

double math_lu_decomposition_determinant(
 int n,
 double *A
)

/*
Compute det(A)
*/

{

 double **A2;
 double d;
 int i;
 int j;
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
 Compute the determinant
 */

 for(j=1;j<=n;j++) d *= A2[j][j];

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

 return d;

}
