/* common.h
 *
 * Functions that are common to different source files.
 *
 * $Author: vorpal $
 * $Date: 2002/11/14 19:11:00 $
 */

#ifndef COMMON_H
#define COMMON_H

#ifdef DEBUG
#include <stdio.h>
#endif

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

/* we define the size of a long in bits here, to
   speed up computations */
/* REMEMBER to change this as appropriate */
#ifndef LONG_SIZE
#define LONG_SIZE 32
#endif

/* define this to reduce calculation time */
#ifndef LONG_MOD
#define LONG_MOD LONG_SIZE - 1
#endif

/* ASCII to number conversion */
#ifndef ASCIITONUM
#define ASCIITONUM 0x30
#endif

/* some quick macros, just to access certain bits
   in long ints */
#define gbit(x,pos) ((x & (((long)1) << (LONG_MOD - pos))) ? 1 : 0)
#define sbit(x,pos,val) (x = (val ? (x | (((long)1) << (LONG_MOD - pos))) : (x & (~(((long)1) << (LONG_MOD - pos))))));
#endif

/*
 * $Log: common.h,v $
 * Revision 1.1  2002/11/14 19:11:00  vorpal
 * Initial checkin.
 *
 * Revision 1.1  2002/10/29 18:48:55  vorpal
 * Readded encdec under a more organized directory structure.
 *
 * Revision 1.1  2002/10/09 04:59:56  vorpal
 * Added files to project.
 *
 * Revision 1.1.1.1  2002/04/30 05:24:11  vorpal
 * Initial checkin.
 *
 * Revision 1.1.1.1  2002/01/24 16:55:32  vorpal
 * Initial checkin for distributed version.
 *
 * Revision 1.2  2001/08/14 12:53:12  vorpal
 * Implemented canonicity checking command line arg.
 *
 * Revision 1.1.1.1  2001/08/03 13:22:30  vorpal
 * Initial checkin.
 *
 */
