#include "header.h"

void get_random_int(
 int min_int,
 int max_int,
 int *prand_int
)

/*
rand_int is a random integer between
min_int (inclusive) and
max_int (inclusive)
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
 1.0 (exclusive)
 */

 rand_dbl= (double)rand_int/((double)RAND_MAX+1.0);

 /*
 rand2_dbl is a random double between
 (double)min_int (inclusive) and
 (double)(max_int+1) (exclusive)
 */

 rand2_dbl= (double)min_int + rand_dbl*( (double)(max_int+1-min_int) );

 /*
 rand_int is a random integer between
 min_int (inclusive) and
 max_int (inclusive)
 */

 rand_int= (int)rand2_dbl;

 if ( !(rand_int >= min_int) ) {
    error_handler((char *)"get_random_int");
 }
 if ( !(rand_int <= max_int) ) {
    error_handler((char *)"get_random_int");
 }

 (*prand_int)= rand_int;

}
