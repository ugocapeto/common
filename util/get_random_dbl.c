#include "header.h"

void get_random_dbl(
 double min_dbl,
 double max_dbl,
 double *prand_dbl
)

/*
rand_dbl is a random double between
min_dbl (inclusive) and
max_dbl (inclusive)
*/

{

 int rand_int;
 double rand_dbl;
 double rand2_dbl;

 /*
 Generate a random integer between
 0 (inclusive) and
 RAND_MAX (inclusive)
 */

 rand_int= rand();

 /*
 rand_dbl is a random double between
 0.0 (inclusive) and
 1.0 (inclusive)
 */

 rand_dbl= (double)rand_int/((double)RAND_MAX);

 /*
 rand2_dbl is a random double between
 min_dbl (inclusive) and
 max_dbl (inclusive)
 */

 rand2_dbl= min_dbl + rand_dbl*( max_dbl-min_dbl );

 rand_dbl= rand2_dbl;

 if ( !(rand_dbl >= min_dbl) ) {
    error_handler((char *)"get_random_dbl");
 }
 if ( !(rand_dbl <= max_dbl) ) {
    error_handler((char *)"get_random_dbl");
 }

 (*prand_dbl)= rand_dbl;

}
