/* rmencode.c
 *
 * Command-line Reed-Muller encoding utility.
 *
 * By Sebastian Raaphorst, 2002
 * ID#: 1256241
 *
 * $Author: vorpal $
 * $Date: 2002/12/09 04:06:59 $
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reedmuller.h"
#include "common.h"

static reedmuller rm = 0;
static int *message = 0;
static int *codeword = 0;


static int read_vector_from_string(char *str, int elems, int *vector)
{
  int i;

  for (i=0; i < elems; ++i) {
    if (!(*str))
      return FALSE;
    vector[i] = str[i] - '0';
  }

  return TRUE;
}


static void cleanup()
{
  reedmuller_free(rm);
  free(message);
  free(codeword);
}


int main(int argc, char *argv[])
{
  int i, j;
  int r, m;

  if (argc < 4) {
    fprintf(stderr, "usage: %s r m message1 [message2 [message3 [...]]]\n",
	    argv[0]);
    exit(EXIT_FAILURE);
  }

  /* try to create the reed-muller code and the vectors */
  r = atoi(argv[1]);
  m = atoi(argv[2]);
  if ((!(rm = reedmuller_init(r, m)))
      || (!(message = (int*) calloc(rm->k, sizeof(int))))
      || (!(codeword = (int*) calloc(rm->n, sizeof(int))))) {
    fprintf(stderr, "out of memory\n");
    cleanup();
    exit(EXIT_FAILURE);
  }

#ifdef OUTPUTINPUT
  printf("Code parameters for R(%d,%d): n=%d, k=%d\n",
	 rm->r, rm->m, rm->n, rm->k);
  printf("The generator matrix is:\n");
  for (i=0; i < rm->k; ++i) {
    printf("\t");
    for (j=0; j < rm->n; ++j)
      printf("%d ", rm->G[j][i]);
    printf("\n");
  }
  printf("\n");
#endif

  for (i=3; i < argc; ++i) {
    /* make sure that the message is of the appropriate length */
    if (strlen(argv[i]) != rm->k) {
      fprintf(stderr, "message %s has invalid length %d (needs %d)\n",
	      argv[i], strlen(argv[i]), rm->k);
      continue;
    }

    /* read in the message */
    read_vector_from_string(argv[i], rm->k, message);
#ifdef OUTPUTINPUT
    for (j=0; j < rm->k; ++j)
      printf("%d", message[j]);
    printf(" -> ");
#endif

    /* encode it */
    reedmuller_encode(rm, message, codeword);
    for (j=0; j < rm->n; ++j)
      printf("%d", codeword[j]);
    printf("\n");
  }

  cleanup();
  exit(EXIT_SUCCESS);
}


/*
 * $Log: rmencode.c,v $
 * Revision 1.3  2002/12/09 04:06:59  vorpal
 * Added changes to allow for decoding.
 * Still have to write rmdecode.c and test.
 *
 * Revision 1.2  2002/11/14 21:05:41  vorpal
 * Tidied up vector reading, and recompiled without debugging defines.
 *
 * Revision 1.1  2002/11/14 21:02:34  vorpal
 * Fixed bugs in reedmuller.c and added command-line encoding app.
 *
 */

