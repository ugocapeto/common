#include "header.h"

void plot_convex_polygon(
 int *point_arr,
 int point_nbr,
 int **pxy_arr,
 int *pxy_nbr
)

/*
Polygon is defined by point_arr
The pixels that make up the polygon are returned in xy_arr
*/

{

 int point_ind_0;
 int point_ind_1;
 int x0;
 int y0;
 int x1;
 int y1;
 int *line_xy_arr;
 int line_xy_nbr;
 int line_xy_ind;
 int line_x;
 int line_y;
 int flag;
 int xy_ind;
 int x;
 int y;
 int *xy_arr;
 int xy_nbr;
 int min_y;
 int max_y;
 int *min_x_arr;
 int *max_x_arr;

 xy_arr= 0;
 xy_nbr= 0;

 /*
 Plot the bdry lines
 */

 for ( point_ind_0= 0 ; point_ind_0< point_nbr ; point_ind_0++ ) {
    point_ind_1= (point_ind_0+1)%point_nbr;
    x0= point_arr[2*point_ind_0+0];
    y0= point_arr[2*point_ind_0+1];
    x1= point_arr[2*point_ind_1+0];
    y1= point_arr[2*point_ind_1+1];

    plot_line(
     x0,
     y0,
     x1,
     y1,
     &line_xy_arr,
     &line_xy_nbr
    );

    for ( line_xy_ind= 0 ; line_xy_ind< line_xy_nbr ; line_xy_ind++ ) {
       line_x= line_xy_arr[2*line_xy_ind+0];
       line_y= line_xy_arr[2*line_xy_ind+1];

       /*
       Add to xy_arr unless already there
       */

       flag= 0;
       for ( xy_ind= 0 ; xy_ind< xy_nbr ; xy_ind++ ) {
          x= xy_arr[2*xy_ind+0];
          y= xy_arr[2*xy_ind+1];
          if ( line_x == x && line_y == y )
           flag= 1;
       } 

       if ( flag == 1 )
        continue;

       /*
       Add to xy_arr
       */

       if ( xy_nbr == 0 ) {
          xy_arr= (int *)calloc((xy_nbr+1),2*sizeof(int));
       }
       else {
          xy_arr= (int *)realloc(xy_arr,(xy_nbr+1)*2*sizeof(int));
       }
       xy_arr[2*xy_nbr+0]= line_x;
       xy_arr[2*xy_nbr+1]= line_y;
       xy_nbr++;
    }

    /*
    Free line_xy_arr
    */

    if ( line_xy_nbr > 0 )
     free(line_xy_arr);
 }

 /*
 Plot the interior
 */

 /*
 Get the min and max y
 */

 min_y= +INT_MAX;
 max_y= -INT_MAX;

 for ( xy_ind= 0 ; xy_ind< xy_nbr ; xy_ind++ ) {
    x= xy_arr[2*xy_ind+0];
    y= xy_arr[2*xy_ind+1];
    if ( y < min_y ) {
       min_y= y;
    }
    if ( y > max_y ) {
       max_y= y;
    }
 }

 /*
 For each y between min_y and max_y,
 get the min and max x
 */

 min_x_arr= (int *)calloc((max_y-min_y+1),sizeof(int));
 max_x_arr= (int *)calloc((max_y-min_y+1),sizeof(int));
 for ( y= min_y ; y<= max_y ; y++ ) {
    min_x_arr[y-min_y]= +INT_MAX;
    max_x_arr[y-min_y]= -INT_MAX;
 }

 for ( xy_ind= 0 ; xy_ind< xy_nbr ; xy_ind++ ) {
    x= xy_arr[2*xy_ind+0];
    y= xy_arr[2*xy_ind+1];
    if ( x < min_x_arr[y-min_y] ) {
       min_x_arr[y-min_y]= x;
    }
    if ( x > max_x_arr[y-min_y] ) {
       max_x_arr[y-min_y]= x;
    }
 }

 /*
 For each row,
 plot in between the min and max
 */

 for ( y= min_y ; y<= max_y ; y++ ) {
    for ( x= min_x_arr[y-min_y]+1 ;
          x< max_x_arr[y-min_y] ;
          x++ ) {

       /*
       Add to xy_arr
       */

       if ( xy_nbr == 0 ) {
          xy_arr= (int *)calloc((xy_nbr+1),2*sizeof(int));
       }
       else {
          xy_arr= (int *)realloc(xy_arr,(xy_nbr+1)*2*sizeof(int));
       }
       xy_arr[2*xy_nbr+0]= x;
       xy_arr[2*xy_nbr+1]= y;
       xy_nbr++;
    }
 }

 /*
 Free min_x_arr
 */

 if ( (max_y-min_y+1) > 0 )
  free(min_x_arr);

 /*
 Free max_x_arr
 */
 
 if ( (max_y-min_y+1) > 0 )
  free(max_x_arr);

 (*pxy_arr)= xy_arr;
 (*pxy_nbr)= xy_nbr;

}
