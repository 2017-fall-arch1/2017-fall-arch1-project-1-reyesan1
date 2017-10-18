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
  printf("You are entering employee names: \n");
  printf("Enter 'q' to quit entering names\n");

  char buf[100];
  /* making root of tree */
  gets_n(buf,100);
  BSTnode *tp = bstAlloc(buf);
  
  /* building the list */
while (!(strcmp(buf,"q")==0)){	
    gets_n(buf, 100);
    if(strcmp(buf,"q")==0){
      break;
    }
    bstInsert(tp, buf);
  
  }

 printf("Enter 'p' to print list of 'r' to remove a name\n");

 gets_n(buf, 100);

 if(strcmp(buf,"p")==0){
  printf("Printing list of names in alphabetical order\n");
  bstPrint(tp);
 }

 else if(strcmp(buf, "r")==0){
   printf("Enter a name you would like to remove\n");
   gets_n(buf, 100);
   BSTnode *rmv = search(tp, buf);
   bstRemove(tp, rmv);
   printf("List after removal\n");
   bstPrint(tp);
 }
  /*bstMakeEmpty(tp);


  bstFree(tp);*/

  return 0;
}

 
