#include "header.h"
#include "proto.h"

void math_matrix_vector_product(
 double *A1,
 int nrow1,
 int ncol1,
 double *a2,
 int nrow2,
 double *b
)

{

 int i;
 int k;
 double val;

 if ( nrow2 != ncol1 ) {
    math_error_handler((char *)"math_matrix_matrix_product");
 }

 for ( i= 0 ; i< nrow1 ; i++ ) {
    val= 0;
    for ( k= 0 ; k< ncol1 ; k++ )
     val+= A1[i*ncol1+k]*a2[k];
    b[i]= val;
 }

}
