#include "header.h"
#include "proto.h"

void math_singular_value_decomposition(
 int m,
 int n,
 double *A,
 double *U,
 double *w,
 double *V
)

{

 double **A2;
 int i;
 int j;
 double *w2;
 double **V2;
 double *temp2;
 double *temp3;
 int k;
 double temp1;

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
 Sort the SVD by decreasing order of singular values
 */

 temp2= (double *)calloc(m+1,sizeof(double));
 temp3= (double *)calloc(n+1,sizeof(double));

 for ( j= 1 ; j<= n ; j++ ) {
    for ( k= j+1 ; k<= n ; k++ ) {
       if ( w2[k] <= w2[j] )
        continue;

       /*
       Swap column j and k
       */

       temp1= w2[j];
       for ( i= 1 ; i<= m ; i++ )
        temp2[i]= A2[i][j];
       for ( i= 1 ; i<= n ; i++ )
        temp3[i]= V2[i][j];

       w2[j]= w2[k];
       for ( i= 1 ; i<= m ; i++ )
        A2[i][j]= A2[i][k];
       for ( i= 1 ; i<= n ; i++ )
        V2[i][j]= V2[i][k];

       w2[k]= temp1;
       for ( i= 1 ; i<= m ; i++ )
        A2[i][k]= temp2[i];
       for ( i= 1 ; i<= n ; i++ )
        V2[i][k]= temp3[i];
    }
 }

 free(temp2);
 free(temp3);

 /*
 Copy A2 into U
 U is indexed from 0 to m-1 for the rows and 0 to n-1 for the columns
 A2 is indexed from 1 to m for the rows and 1 to n for the columns
 */

 for ( i= 0 ; i< m ; i++ ) {
    for ( j= 0 ; j< n ; j++ ) {
       U[i*n+j]= A2[i+1][j+1];
    }
 }

 /*
 Copy w2 into w
 w is indexed from 0 to n-1
 w2 is indexed from 1 to n
 */

 for ( i= 0 ; i< n ; i++ ) {
    w[i]= w2[i+1];
 }

 /*
 Copy V2 into V
 V is indexed from 0 to n-1
 V2 is indexed from 1 to n
 */

 for ( i= 0 ; i< n ; i++ ) {
    for ( j= 0 ; j< n ; j++ ) {
       V[i*n+j]= V2[i+1][j+1];
    }
 }

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

}
