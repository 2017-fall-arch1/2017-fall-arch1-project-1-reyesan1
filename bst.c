#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include <string.h>             /* for strcmp */
#include "bst.h"		
/* TODO Implement DoCheck */
/* int llDoCheck = 1;		/* set true for paranoid consistency checking */

/* #define doCheck(_lp) (llDoCheck && llCheck(_lp)) */

/* create a new binary search tree */
BSTnode *bstAlloc()
{
  BSTnode *tp = (BSTnode *)malloc(sizeof(BSTnode));
  tp->left = tp->right = NULL;
  return tp;
}

/* recycle a tree, discarding all items it contains */
void bstFree(BSTnode *tp)
{
  bstMakeEmpty(tp);
  free(tp);
}

/* Delete all elements off of the tree */
void bstMakeEmpty(BSTnode *tp)
{
  BSTnode *curr = tp, *left, *right;
  if(curr == NULL){
    return;
  }
  else{
       bstMakeEmpty(curr->left);
       bstMakeEmpty(curr->right);
       free(curr->name);
       free(curr);
  }
  tp->left = tp->right = NULL;
  	/* tree is empty */
  /* doCheck(lp); */
}
  
/* adding a new node to the tree*/
BSTnode *bstInsert(BSTnode *tp, char *n)
{
  /* case if new node */
  if(tp == NULL){
    tp = bstAlloc();
    tp->name = n;
    tp->left = tp->right = NULL;
  }
  /* case if less than, go to left*/
  else if((strcmp(n, tp->name)) < 0){
    tp->left = bstInsert(tp->left, n);
  }
  /* case if greater than or equal, go to right */
  else{
    tp->right = bstInsert(tp->right, n);
  }
}

/* print list membership.  Prints default mesage if message is NULL */
void bstPrint(BSTnode *tp)
{
  if(tp == NULL){
    printf("End of list\n");
    return;
  }

  printf(tp->name,"\n");
  bstPrint(tp->left);
  bstPrint(tp->right);
} 
