#include "header.h"
#include "proto.h"

double math_matrix2x2_determinant(
 double A[2*2]
)

{

 int ncol;
 double det;

 ncol= 2;

 det= A[0*ncol+0]*A[1*ncol+1]-
      A[1*ncol+0]*A[0*ncol+1];

 return det;

}
