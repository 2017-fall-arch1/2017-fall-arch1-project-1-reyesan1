#ifndef bstree_included		/* prevent multiple inclusion */
#define bstree_included
 

/* a binary search tree tnode */
typedef struct BSTnode_s {
  struct BSTnode_s *left;   /* points to left child */
  struct BSTnode_s *right;  /* points to the right child */
  char *name;               /* points to name in tree */ 
} BSTnode;

/* a tree of BSTnodes */
typedef struct {
  BSTnode *root;
} BSTree;

/* TODO: Implement DoCheck */
/*extern int bstDoCheck;		/* set true for paranoid consistency checking */

/* creates a new binary search tree */
BSTree *bstAlloc();

/* free memory associated with a tree, discarding all items it contains */
void bstFree(BSTree *tp);

/* append a copy of name to child */
void bstPut(BSTree *tp, char *name);

/* Delete all elements off of the tree */
void bstMakeEmpty(BSTree *tp);

/* print tree contents.  Prints default message if tree is NULL */
void bstPrint(BSTree *tp, char *name);

/* check tree consistency, always returns zero */
int llCheck(BSTree *tp);

/* add employee name */
void bstAdd(BSTnode *tp);

/* remove employee name */
void bstRemove(BSTnode *tp);


#endif	/* included */
