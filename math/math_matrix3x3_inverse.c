#include "header.h"
#include "proto.h"

void math_matrix3x3_inverse(
 double A[3*3],
 double B[3*3]
)

/*
Compute the inverse of a 3x3 matrix using
inv(A)= 1/det(A) * comatrix(A)t
Note the the transpose of the comatrix
is also known as the adjunct or adjugate
*/

{

 double A22[2*2];
 double fac;
 double comA[3*3];
 double comAt[3*3];
 int i;
 int j;
 double detA22;
 double detA;
 double C[3*3];

 /*
 Compute the determinant of A
 */

 detA= math_matrix3x3_determinant(
  A
 );

 /*
 Compute the comatrix of A
 */

 fac= 1.0;
 for ( i= 0 ; i< 3 ; i++ ) {
    for ( j= 0 ; j< 3 ; j++ ) {

       /*
       Remove row i and column j from A
       */

       math_matrix_remove_row_col(
        A,
        3,
        3,
        i,
        j,
        A22
       );

       /*
       Compute the determinant of A22
       */

       detA22= math_matrix2x2_determinant(
        A22
       );

       comA[i*3+j]= fac*detA22;
       fac*= -1.0;
    }
 }

 /*
 Compute the transpose of the comatrix of A
 */

 math_matrix_transpose(
  comA,
  3,
  3,
  comAt
 );

 /*
 Compute the inverse of A
 */

 for ( i= 0 ; i< 3 ; i++ ) {
    for ( j= 0 ; j< 3 ; j++ ) {
       B[i*3+j]= comAt[i*3+j]/detA;
    }
 }

 /*
 Check!
 */

 math_matrix_matrix_product(
  A,
  3,
  3,
  B,
  3,
  3,
  C
 );

}
