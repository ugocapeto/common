#include "header.h"
#include "proto.h"

#define NR_END 1

double *math_dvector(
 int nl,
 int nh
)
/* allocate a double vector with subscript range v[nl..nh] */
{
        double *v;
        v=(double *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(double)));
        return v-nl+NR_END;
}

#undef NR_END
