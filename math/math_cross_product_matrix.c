#include "header.h"
#include "proto.h"

void math_cross_product_matrix(
 double x[3],
 double A[3*3]
)

{

 A[0*3+0]=  0;
 A[0*3+1]= -x[2];
 A[0*3+2]= +x[1];

 A[1*3+0]= +x[2];
 A[1*3+1]=  0;
 A[1*3+2]= -x[0];

 A[2*3+0]= -x[1];
 A[2*3+1]= +x[0];
 A[2*3+2]=  0;

}
