#include "header.h"
#include "proto.h"

#define TOL 2.0e-4

int ncom=0;     /* defining declarations */
double *pcom=0,*xicom=0,(*nrfunc)(double []);

void math_linmin(
 double p[],
 double xi[],
 int n,
 double *fret,
 double (*func)(double [])
)
{
        int j;
        double xx,xmin,fx,fb,fa,bx,ax;

        ncom=n;
        pcom=math_dvector(1,n);
        xicom=math_dvector(1,n);
        nrfunc=func;
        for (j=1;j<=n;j++) {
                pcom[j]=p[j];
                xicom[j]=xi[j];
        }
        ax=0.0;
        xx=1.0;
        bx=2.0;
        math_mnbrak(&ax,&xx,&bx,&fa,&fx,&fb,math_f1dim);
        *fret=math_brent(ax,xx,bx,math_f1dim,TOL,&xmin);
        for (j=1;j<=n;j++) {
                xi[j] *= xmin;
                p[j] += xi[j];
        }
        math_free_dvector(xicom,1,n);
        math_free_dvector(pcom,1,n);
}

#undef TOL
