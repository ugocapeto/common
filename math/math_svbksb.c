#include "header.h"
#include "proto.h"

void math_svbksb(
 double **u,
 double w[],
 double **v,
 int m,
 int n,
 double b[],
 double x[]
)

{
	int jj,j,i;
	double s,*tmp;

        tmp=(double *)calloc(n+1,sizeof(double));
	for (j=1;j<=n;j++) {
		s=0.0;
		if (w[j]) {
			for (i=1;i<=m;i++) s += u[i][j]*b[i];
			s /= w[j];
		}
		tmp[j]=s;
	}
	for (j=1;j<=n;j++) {
		s=0.0;
		for (jj=1;jj<=n;jj++) s += v[j][jj]*tmp[jj];
		x[j]=s;
	}
	free(tmp);
}
