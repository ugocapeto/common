#include "header.h"
#include "proto.h"
/*
#include <math.h>
*/

double math_amotry(
 double **p,
 double *y,
 double *psum,
 int ndim,
 double (*funk)(double []),
 int ihi,
 int *nfunk,
 double fac
)
{
	int j;
	double fac1,fac2,ytry,*ptry;

	ptry=math_dvector(1,ndim);
	fac1=(1.0-fac)/ndim;
	fac2=fac1-fac;
	for (j=1;j<=ndim;j++) ptry[j]=psum[j]*fac1-p[ihi][j]*fac2;
	ytry=(*funk)(ptry);
	++(*nfunk);
	if (ytry < y[ihi]) {
		y[ihi]=ytry;
		for (j=1;j<=ndim;j++) {
			psum[j] += ptry[j]-p[ihi][j];
			p[ihi][j]=ptry[j];
		}
	}
	math_free_dvector(ptry,1,ndim);
	return ytry;
}
