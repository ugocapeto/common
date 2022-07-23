#include "header.h"
#include "proto.h"

double F(
 double input
)

{

 if (input>0.008856)
  return (pow(input, 0.333333333));
 else
  return (7.787*input+0.137931034);

}
