#include "header.h"
#include "proto.h"

void math_matrix_remove_row_col(
 double *A,
 int nrow,
 int ncol,
 int inp_i,
 int inp_j,
 double *B
)

/*
Remove row inp_i and column inp_j from A
*/

{

 int i;
 int j;
 double val;
 int iB;
 int jB;

 iB= 0;
 for ( i= 0 ; i< nrow ; i++ ) {
    if ( i == inp_i )
     continue;
    jB= 0;
    for ( j= 0 ; j< ncol ; j++ ) {
       if ( j == inp_j )
        continue;
       val= A[i*ncol+j];
       B[iB*(ncol-1)+jB]= val;
       jB++;
    }
    iB++;
 }

}
