#include "header.h"
#include "proto.h"

void math_matrix_matrix_product(
 double *A1,
 int nrow1,
 int ncol1,
 double *A2,
 int nrow2,
 int ncol2,
 double *B
)

{

 int i;
 int j;
 int k;
 double val;

 if ( nrow2 != ncol1 ) {
    math_error_handler((char *)"math_matrix_matrix_product");
 }

 for ( i= 0 ; i< nrow1 ; i++ ) {
    for ( j= 0 ; j< ncol2 ; j++ ) {
       val= 0;
       for ( k= 0 ; k< ncol1 ; k++ )
        val+= A1[i*ncol1+k]*A2[k*ncol2+j];
       B[i*ncol2+j]= val;
    }
 }

}
