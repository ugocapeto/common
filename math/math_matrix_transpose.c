#include "header.h"
#include "proto.h"

void math_matrix_transpose(
 double *A,
 int nrow,
 int ncol,
 double *B
)

{

 int i;
 int j;
 double val;

 for ( i= 0 ; i< nrow ; i++ ) {
    for ( j= 0 ; j< ncol ; j++ ) {
       val= A[i*ncol+j];
       B[j*nrow+i]= val;
    }
 }

}
