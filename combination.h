/* combination.h
 *
 * Uses dynamic programming to create an array to be used
 * to calculate combinations.
 *
 * By Sebastian Raaphorst, 2002
 * ID#: 1256241
 *
 * $Author: vorpal $
 * $Date: 2002/11/14 19:10:59 $
 */

#ifndef COMBINATION_H
#define COMBINATION_H

int **combination_init(int);
void combination_free(int, int**);

#endif

/*
 * $Log: combination.h,v $
 * Revision 1.1  2002/11/14 19:10:59  vorpal
 * Initial checkin.
 *
 */

