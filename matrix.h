/* matrix.h
 *
 * Functions to create and destroy 2 and 3 dimensional matrices.
 *
 * $Author: vorpal $
 * $Date: 2002/11/14 19:11:00 $
 */

#ifndef MATRIX_H
#define MATRIX_H

/* Right now, we only make matrices with ints.
   This should be sufficient for our purposes. */

/* create an n * m matrix - return null on failure */
int **matrix_2d(int, int);

/* create an n * m * o matrix - return null on failure */
int ***matrix_3d(int, int, int);

void matrix_free_2d(int**, int, int);

void matrix_free_3d(int***, int, int, int);

#endif

/*
 * $Log: matrix.h,v $
 * Revision 1.1  2002/11/14 19:11:00  vorpal
 * Initial checkin.
 *
 * Revision 1.1  2002/10/29 18:48:56  vorpal
 * Readded encdec under a more organized directory structure.
 *
 * Revision 1.1  2002/10/09 04:59:57  vorpal
 * Added files to project.
 *
 * Revision 1.1.1.1  2002/04/30 05:24:11  vorpal
 * Initial checkin.
 *
 * Revision 1.1.1.1  2002/01/24 16:55:32  vorpal
 * Initial checkin for distributed version.
 *
 * Revision 1.1.1.1  2001/08/03 13:22:30  vorpal
 * Initial checkin.
 *
 */
