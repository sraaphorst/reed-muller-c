/* matrix.c
 *
 * $Author: vorpal $
 * $Date: 2002/11/14 19:11:00 $
 */

#include <stdlib.h>
#include "common.h"
#include "matrix.h"


int **matrix_2d(int n, int m)
{
  int **matrix;
  int i, j;

  if (!(matrix = (int**) calloc(n, sizeof(int*))))
    return FALSE;

  for (i=0; i < n; ++i)
    if (!(matrix[i] = (int*) calloc(m, sizeof(int)))) {
      /* could not allocate, so free all the old memory */
      for (j=0; j < i; ++j)
	free(matrix[j]);
      free(matrix);
      return FALSE;
    }

  return matrix;
}


int ***matrix_3d(int n, int m, int p)
{
  int ***matrix;
  int i, j;

  if (!(matrix = (int***) calloc(n, sizeof(int**))))
    return FALSE;

  /* now create 2D matrices, and store them appropriately */
  for (i=0; i < n; ++i)
    if (!(matrix[i] = matrix_2d(m, p))) {
      /* delete the memory */
      for (j=0; j < i; ++j)
	matrix_free_2d(matrix[j], m, p);
      free(matrix);
      return FALSE;
    }

  return matrix;
}


void matrix_free_2d(int **matrix, int n, int m)
{
  int i;

  for (i=0; i < n; ++i)
    free(matrix[i]);
  free(matrix);
}


void matrix_free_3d(int ***matrix, int n, int m, int p)
{
  int i;

  for (i=0; i < n; ++i)
    matrix_free_2d(matrix[i], m, p);
  free(matrix);
}


/*
 * $Log: matrix.c,v $
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

