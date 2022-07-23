#include "header.h"
#include "proto.h"

#define NR_END 1
#define FREE_ARG char*

void math_free_dvector(
 double *v,
 int nl,
 int nh
)
/* free a double vector allocated with dvector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}

#undef NR_END
#undef FREE_ARG
