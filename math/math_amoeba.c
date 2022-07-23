#include "header.h"
#include "proto.h"
/*
#include <math.h>
*/

#define NMAX 5000
#define ALPHA 1.0
#define BETA 0.5
#define GAMMA 2.0

#define GET_PSUM for (j=1;j<=ndim;j++) { for (i=1,sum=0.0;i<=mpts;i++)\
						sum += p[i][j]; psum[j]=sum;}

void math_amoeba(
 double **p,
 double y[],
 int ndim,
 double ftol,
 double (*funk)(double []),
 int *nfunk
)
{
	int i,j,ilo,ihi,inhi,mpts=ndim+1;
	double ytry,ysave,sum,rtol,*psum,*vector();

	psum=math_dvector(1,ndim);
	*nfunk=0;
	GET_PSUM
	for (;;) {
		ilo=1;
		ihi = y[1]>y[2] ? (inhi=2,1) : (inhi=1,2);
		for (i=1;i<=mpts;i++) {
			if (y[i] < y[ilo]) ilo=i;
			if (y[i] > y[ihi]) {
				inhi=ihi;
				ihi=i;
			} else if (y[i] > y[inhi])
				if (i != ihi) inhi=i;
		}
		rtol=2.0*fabs(y[ihi]-y[ilo])/(fabs(y[ihi])+fabs(y[ilo]));
		if (rtol < ftol) break;
		if (*nfunk >= NMAX) math_nrerror((char *)"Too many iterations in AMOEBA");
		ytry=math_amotry(p,y,psum,ndim,funk,ihi,nfunk,-ALPHA);
		if (ytry <= y[ilo])
			ytry=math_amotry(p,y,psum,ndim,funk,ihi,nfunk,GAMMA);
		else if (ytry >= y[inhi]) {
			ysave=y[ihi];
			ytry=math_amotry(p,y,psum,ndim,funk,ihi,nfunk,BETA);
			if (ytry >= ysave) {
				for (i=1;i<=mpts;i++) {
					if (i != ilo) {
						for (j=1;j<=ndim;j++) {
							psum[j]=0.5*(p[i][j]+p[ilo][j]);
							p[i][j]=psum[j];
						}
						y[i]=(*funk)(psum);
					}
				}
				*nfunk += ndim;
				GET_PSUM
			}
		}
	}
	math_free_dvector(psum,1,ndim);
}

#undef ALPHA
#undef BETA
#undef GAMMA
#undef NMAX
