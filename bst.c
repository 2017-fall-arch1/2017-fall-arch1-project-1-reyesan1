#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include <string.h>             /* for strcmp */
#include "bst.h"		

/* creating a new binary search tree */
BSTnode *bstAlloc(char* name)
{
  BSTnode *tp = (BSTnode *)malloc(sizeof(BSTnode));
  tp->name = malloc(sizeof(name)+1);
  strcpy(tp->name, name);
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
  printf("-%s\n",tp->name);
  bstPrint(tp->right);
} 

/* Method to search a tree and return node */
BSTnode *search(BSTnode *bst, char *name){
  // Current node to not lose pointer
  BSTnode *curr = bst;
  // Temporary variable for comparison
  int tmp;
  // Traversing the tree
  while(!(curr==NULL)){
    tmp = strcmp(curr->name, name);
    // Going left
    if(tmp > 0){
      curr = curr->left;
      continue;
    }
    // Goin right
    else if(tmp < 0){
      curr = curr->right;
      continue;
    }
    // Found the node
    else if(tmp == 0){
      printf("Deleting %s\n", curr->name);
      return curr;
    }
    // Node not found
    else{
      printf("Name not found\n");
    }
  }
}

/* Finding node with minimum value */
BSTnode *min(BSTnode *tp){
  // Current node to not lose pointer
  BSTnode *curr = tp;
  // Traversing all the way left
  while(!(curr->left==NULL)){
    curr = curr->left;
  }
  // Returning pointer to minimum node
  return curr;
}


/* removing a name from a tree, passing in  */
BSTnode *bstRemove(BSTnode *tp, char *n){
  /* Case if node to remove is null */
  if(tp == NULL){
    return tp;
  }
  // Comparing strings
  int tmp = strcmp(tp->name, n);
  // Going left
  if(tmp > 0){
    tp->left = bstRemove(tp->left, n);
  }
  // Going right
  else if(tmp < 0){
    tp->right = bstRemove(tp->right, n);
  }
  // Node found, 3 different cases
  else{
  /* case if node to remove has no children */
  if(tp->right==NULL && tp->left==NULL){
    free(tp);
    tp = NULL;
  }

  /* case if node to remove has no left child */
  else if(tp->left ==NULL){
    BSTnode *tmp = tp;
    tp = tp->right;
    free(tmp);
  }

  /* case if node to remove has no right child */
  else if(tp->right == NULL){
    BSTnode *tmp = tp;
    tp = tp->left;
    free(tmp);
  }

  /* case if node to remove has 2 children */
  else{
    BSTnode *tmp = min(tp->right);
    // Swap names, and remove tmp node
    tp->name = tmp->name;
    tp->right = bstRemove(tp->right, tmp->name);
  }

  }
  // Return root pointer
  return tp;
}
