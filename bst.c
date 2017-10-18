#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include <string.h>             /* for strcmp */
#include "bst.h"		

/* create a new binary search tree */
BSTnode *bstAlloc(char* name)
{
  BSTnode *tp = (BSTnode *)malloc(sizeof(BSTnode));
  tp->name = malloc(strlen(name)+1);
  strcpy(tp->name,name);
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
}
  
/* adding a new node to the tree*/
BSTnode *bstInsert(BSTnode *tp, char *n)
{
  int tmp;
  /* case if new node */
  if(tp == NULL){
    tp =bstAlloc(n);
    return tp;
  }
  
  /* case if less than, go to left*/
  tmp = strcmp(n,tp->name);
  if(tmp < 0){
    tp->left = bstInsert(tp->left, n);
    return tp;
  }
  /* case if greater than or equal, go to right */
  else{
    tp->right = bstInsert(tp->right, n);
    return tp;
  }
  
}

/* print list membership in alphabetical order */
void bstPrint(BSTnode *tp)
{
  if(tp == NULL){
    return;
  }
  bstPrint(tp->left);
  printf("%s\n",tp->name);
  bstPrint(tp->right);
} 
