/* combination.c
 *
 * By Sebastian Raaphorst, 2002
 * ID#: 1256241
 *
 * $Author: vorpal $
 * $Date: 2002/11/14 19:10:59 $
 */

#include "matrix.h"
#include "common.h"
#include "combination.h"


int **combination_init(int n)
{
  int i, j;
  int **nCr;

  /* try to create the combination array */
  if (!(nCr = matrix_2d(n+1, n+1)))
    return FALSE;

  /* initialize all the entries */
  for (i=0; i <= n; ++i)
    for (j=0; j <= i; ++j)
      nCr[i][j] = (i == 0 ? 1 :
		   (j == 0 ? nCr[i-1][0]
		    : nCr[i-1][j-1] + nCr[i-1][j]));

  return nCr;
}


void combination_free(int n, int **nCr)
{
  matrix_free_2d(nCr, n+1, n+1);
}


/*
 * $Log: combination.c,v $
 * Revision 1.1  2002/11/14 19:10:59  vorpal
 * Initial checkin.
 *
 */
