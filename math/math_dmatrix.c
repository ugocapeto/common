#include "header.h"
#include "proto.h"

#define NR_END 1

double **math_dmatrix(
 int nrl,
 int nrh,
 int ncl,
 int nch
)
/* allocate a double matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        int i,nrow=nrh-nrl+1,ncol=nch-ncl+1;
        double **m;
        /* allocate pointers to rows */
        m=(double **) malloc((size_t)((nrow+NR_END)*sizeof(double*)));
        m += NR_END;
        m -= nrl;
        /* allocate rows and set pointers to them */
        m[nrl]=(double *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(double)));
        m[nrl] += NR_END;
        m[nrl] -= ncl;
        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
        /* return pointer to array of pointers to rows */
        return m;
}

#undef NR_END
