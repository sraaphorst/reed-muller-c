/* reedmuller.h
 *
 * Reed-Muller code implementation. Currently works only over |F_2.
 *
 * By Sebastian Raaphorst, 2002
 * ID#: 1256241
 *
 * $Author: vorpal $
 * $Date: 2002/12/09 15:07:04 $
 */

#ifndef REEDMULLER_H
#define REEDMULLER_H

#include "ksubset.h"

/* these must be at least 4 and 2 for init and decode to work properly! */
#ifndef NUMVECTORS
#define NUMVECTORS 4
#endif
#ifndef NUMSUBSETS
#define NUMSUBSETS 2
#endif

struct _reedmuller {
  int r;
  int m;
  int q;
  int n;
  int k;
  int **G;
  int **rows;
  set s;

  /* this isn't all that elegant, but allocating work vectors / subsets during
     the initialization process prevents us from having to create them
     dynamically during the call to the decoding function, which is
     not only inefficient but bad programming style */
  int *vector[NUMVECTORS];
  int *subset[NUMSUBSETS];
};

typedef struct _reedmuller *reedmuller;

reedmuller reedmuller_init(int, int);
void reedmuller_free(reedmuller);

int reedmuller_encode(reedmuller, int*, int*);

int reedmuller_decode(reedmuller, int*, int*);

#endif


/*
 * $Log: reedmuller.h,v $
 * Revision 1.3  2002/12/09 15:07:04  vorpal
 * Fixed decoding routine so that the received message was not
 * altered during computation (had to add a fourth work vector to
 * the reedmuller struct).
 *
 * Revision 1.2  2002/12/09 04:06:59  vorpal
 * Added changes to allow for decoding.
 * Still have to write rmdecode.c and test.
 *
 * Revision 1.1  2002/11/14 20:28:05  vorpal
 * Adding new files to project.
 *
 */
