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

// MAIN METHOD //
int main()
{

  // Printing program info
  printf("-----You are entering employee names: \n");
  printf("-----Enter 'q' to quit entering names\n");

  char buf[100];

  /* making root of tree with first entry */
  gets_n(buf,100);
  BSTnode *tp = bstAlloc(buf);
  
  /* building the list */
  while (!(strcmp(buf,"q")==0)){	
    gets_n(buf, 100);

    // If user enters q, quit
    if(strcmp(buf,"q")==0){
      break;
    }

    // Inserting into tree
    bstInsert(tp, buf);
  
  }


  // Asking the user if they want to add, remove, or print to their list.'e' to exit
  while(!(strcmp(buf,"e")==0)){

    printf("-----Enter 'p' to print list, 'r' to remove a name, 'a' to add, or 'e' to exit\n");

    gets_n(buf, 100);

    //If user enters 'e', exit
    if(strcmp(buf, "e")==0) break;

    //If user wants to print
    if(strcmp(buf,"p")==0){
      printf("-----Printing list of names in alphabetical order:\n");
      // Calling print method
      bstPrint(tp);
    }

    //If user wants to remove
    else if(strcmp(buf, "r")==0){
      printf("-----Enter a name you would like to remove\n");
      gets_n(buf, 100);
      // Calling remove method
      tp = bstRemove(tp, buf);
      // Printing list after removal
      printf("List after removal\n");
      bstPrint(tp);
     }
    //If user wants to add a name
    else if(strcmp(buf, "a")==0){
      printf("-----Enter a name you would like to add\n");
      gets_n(buf, 100);
      // Calling insert method
      bstInsert(tp, buf);
    }
  }

  return 0;
}

 
