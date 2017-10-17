#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "bst.h"		/* for list operations */


/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit)	
{
  char *p = s;			/* for indexing into s */
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
      p++;
    if (c == '\n')		/* erase \n */
      *p = 0;
  }
  return (p - s);		/* #chars read (not including terminator or \n*/
}

int main()
{
  char buf[100];
  BSTnode *tp = bstAlloc();	/* make empty list */

  bstPrint(tp, "List contents, prior to reading input:");

  while (gets_n(buf, 100))	/* build list */
    BSTnode(tp, buf);

  bstPrint(lp, "List contents, after building list:");

  bstMakeEmpty(tp);

  printf("After emptying the list...");
  bstPrint(tp, 0);		/* default message */

  bstFree(lp);

  return 0;
}
