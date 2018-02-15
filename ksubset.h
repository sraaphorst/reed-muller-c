/* ksubset.h
 *
 * Used to manipulate k-subsets of an n-set in lexicographical order.
 * Note that the sets considered are {1, 2, ..., n}.
 *
 * By Sebastian Raaphorst, 2002
 * ID#: 1256241
 *
 * Note: These algorithms were inspired by the book, "Combinatorial
 * Algorithms: Generation, Enumeration, and Search", by Donald L.
 * Kreher and Douglas R. Stinson.
 */

#ifndef KSUBSET_H
#define KSUBSET_H

struct _set {
  int n;
  int **nCr;
};
typedef struct _set *set;

set ksubset_init(int);
void ksubset_free(set);

int ksubset_lex_succ(set, int, int*, int*);
long ksubset_lex_rank(set, int, int*);
void ksubset_lex_unrank(set, int, long, int*);

#endif


/*
 * $Log: ksubset.h,v $
 * Revision 1.1  2002/11/14 19:11:00  vorpal
 * Initial checkin.
 *
 */
