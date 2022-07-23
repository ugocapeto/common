#include "header.h"
#include "proto.h"
extern int ncom;        /* defined in LINMIN */
extern double *pcom,*xicom,(*nrfunc)(double *);

double math_f1dim(
 double x
)
{
        int j;
        double f,*xt;

        xt=math_dvector(1,ncom);
        for (j=1;j<=ncom;j++) xt[j]=pcom[j]+x*xicom[j];
        f=(*nrfunc)(xt);
        math_free_dvector(xt,1,ncom);
        return f;
}
