#include "header.h"
#include "proto.h"

double math_vector_vector_product(
 double *a1,
 int n1,
 double *a2,
 int n2
)

{

 int i;
 double val;

 if ( n2 != n1 ) {
    math_error_handler((char *)"math_matrix_matrix_product");
 }

 val= 0;
 for ( i= 0 ; i< n1 ; i++ ) {
    val+= a1[i]*a2[i];
 }

 return val;

}
