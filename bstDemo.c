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

  printf("Employee list is empty. Begin by entering a name\n");
  
  char buf[100];
  /* making an empy tree */
  BSTnode *tp = bstAlloc();

  printf("Enter 'q' to quit entering names\n");;
while (!(strcmp(buf,"q")==0)){	/* build list */
    gets_n(buf, 100);
    if(strcmp(buf,"q")==0){
      break;
    }
    bstInsert(tp, buf);
    /* printf("Pointer name is %s\n", tp->name);*/
  }

  printf("Printing list of names in alphabetical order\n");
  bstPrint(tp);

  /*bstMakeEmpty(tp);


  bstFree(tp);*/

  return 0;
}

 
