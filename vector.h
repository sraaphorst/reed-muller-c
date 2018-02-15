/* vector.h
 *
 * Functions for working with vectors over a finite field of order
 * of a prime p.
 *
 * By Sebastian Raaphorst, 2002
 * ID#: 1256241
 *
 * $Author: vorpal $
 * $Date: 2002/12/09 04:06:59 $
 */

#ifndef VECTOR_H
#define VECTOR_H

int *vector_add(int, int, int*, int*, int*);
int *vector_subtract(int, int, int*, int*, int*);
int *vector_multiply(int, int, int*, int*, int*);
int *vector_not(int, int, int*, int*);
int *vector_copy(int, int*, int*);
int *vector_clear(int, int*);

int vector_dotproduct(int, int, int*, int*);

#endif

/*
 * $Log: vector.h,v $
 * Revision 1.2  2002/12/09 04:06:59  vorpal
 * Added changes to allow for decoding.
 * Still have to write rmdecode.c and test.
 *
 * Revision 1.1  2002/11/14 20:28:06  vorpal
 * Adding new files to project.
 *
 */
