#include "header.h"
#include "proto.h"

double math_matrix3x3_determinant(
 double A[3*3]
)

{

 double B[2*2];
 double detB_fac;
 int nrow;
 int ncol;
 double det;
 int i;
 int j;
 double detB;

 nrow= 3;
 ncol= 3;

 det= 0;

 j= 0;
 detB_fac=+1.0;
 for ( i= 0 ; i< nrow ; i++ ) {

    /*
    Remove row i and column j from A
    */

    math_matrix_remove_row_col(
     A,
     3,
     3,
     i,
     j,
     B
    );

    /*
    Compute the determinant of B
    */

    detB= math_matrix2x2_determinant(
     B
    );

    det+= detB_fac*A[i*ncol+j]*detB;
    detB_fac*= -1;
 }

 return det;

}
