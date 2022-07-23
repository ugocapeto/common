#include "header.h"
#include "proto.h"
/*
#include <math.h>
*/

#define ITMAX 200
static double sqrarg;
#define SQR(a) (sqrarg=(a),sqrarg*sqrarg)

void math_powell(
 double p[],
 double **xi,
 int n,
 double ftol,
 int *iter,
 double *fret,
 double (*func)(double [])
)
{
	int i,ibig,j;
	double t,fptt,fp,del;
	double *pt,*ptt,*xit;

	pt=math_dvector(1,n);
	ptt=math_dvector(1,n);
	xit=math_dvector(1,n);
	*fret=(*func)(p);
	for (j=1;j<=n;j++) pt[j]=p[j];
	for (*iter=1;;(*iter)++) {
		fp=(*fret);
		ibig=0;
		del=0.0;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) xit[j]=xi[j][i];
			fptt=(*fret);
			math_linmin(p,xit,n,fret,func);
			if (fabs(fptt-(*fret)) > del) {
				del=fabs(fptt-(*fret));
				ibig=i;
			}
		}
		if (2.0*fabs(fp-(*fret)) <= ftol*(fabs(fp)+fabs(*fret))) {
			math_free_dvector(xit,1,n);
			math_free_dvector(ptt,1,n);
			math_free_dvector(pt,1,n);
			return;
		}
		if (*iter == ITMAX) math_nrerror((char *)"Too many iterations in routine POWELL");
		for (j=1;j<=n;j++) {
			ptt[j]=2.0*p[j]-pt[j];
			xit[j]=p[j]-pt[j];
			pt[j]=p[j];
		}
		fptt=(*func)(ptt);
		if (fptt < fp) {
			t=2.0*(fp-2.0*(*fret)+fptt)*SQR(fp-(*fret)-del)-del*SQR(fp-fptt);
			if (t < 0.0) {
				math_linmin(p,xit,n,fret,func);
				for (j=1;j<=n;j++) xi[j][ibig]=xit[j];
			}
		}
	}
}

#undef ITMAX
#undef SQR
