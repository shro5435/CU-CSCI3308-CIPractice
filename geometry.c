/* Shania Roy 

 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * This file contains a simple geomtery functions.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

#include "geometry.h"

#define FUZZY_EQ 0.01

#define DEBUG(file, line, func, msg) fprintf(stderr, "DEBUG - %s_%d_%s: %s", file, line, func, msg);

double coord_2d_dist(const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return NAN;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return NAN;
    }

    /* Maths */
    return sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));

}

bool coord_2d_eq(const coord_2d_t* a, const coord_2d_t* b){

    /* Equal if dist <= FUZZY_EQ */
    if(coord_2d_dist(a, b) <= FUZZY_EQ){
        return true;
    }
    else{
        return false;
    }

}

void coord_2d_midpoint(coord_2d_t* mid, const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!mid){
        DEBUG(__FILE__, __LINE__, __func__, "'mid' must not be NULL");
        return;
    }
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return;
    }

    /* Maths */
    mid->x = ((a->x + b->x) / 2.0 );
    mid->y = ((a->y + b->y) / 2.0 );

}

double coord_2d_area_triangle(const coord_2d_t* a, const coord_2d_t* b, const coord_2d_t* c) {

    /* Input Checks */ 
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return NAN;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return NAN;
    }
    if(!c){
        DEBUG(__FILE__, __LINE__, __func__, "'c' must not be NULL");
        return NAN;
    }

    /* Maths 
    Area = |(Ax(By-Cy) + Bx(Cy-Ay) + Cx(Ay-By))/2| is the algorithm we'll use from http://www.mathopenref.com/coordtrianglearea.html
    We will be using a double because the area can be such
    We CANNOT use abs() because it only works on integers
    We will use the fabs() function takes a single argument (in double ) and returns the absolute value of that number (also in double ).*/

    double Ax = a->x;
    double Ay = a->y; 
    double Bx = b->x;  
    double By = b->y; 
    double Cx = c->x;
    double Cy = c->y; 

    double A = Ax * (By-Cy); 
    double B = Bx * (Cy-Ay); 
    double C = Cx * (Ay-By);

    double sum = A + B + C; 
    
    double divide = sum/2.0;

    double area = fabs(divide);

    return area; 
         
} 