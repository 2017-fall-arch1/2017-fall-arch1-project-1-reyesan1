/*#ifndef bstree_included		/* prevent multiple inclusion */
/*#define bstree_included
 

/* a binary search tree tnode */
typedef struct BSTnode {
  struct BSTnode *left;   /* points to left child */
  struct BSTnode *right;  /* points to the right child */
  char *name;               /* points to name in tree */
} BSTnode;

/* TODO: Implement DoCheck */
/*extern int bstDoCheck;		/* set true for paranoid consistency checking */

/* creates a new binary search tree */
BSTnode *bstAlloc();

/* free memory associated with a tree, discarding all items it contains */
void bstFree(BSTnode *tp);

/* adding a new node to the tree */
BSTnode *bstInsert(BSTnode *tp, char *name);
/* Delete all elements off of the tree */
void bstMakeEmpty(BSTnode *tp);

/* print tree contents.  Prints default message if tree is NULL */
void bstPrint(BSTnode *tp);

/* check tree consistency, always returns zero */
/*int llCheck(BSTnode *tp);

/* add employee name */
/*void bstAdd(BSTnode *tp);

/* remove employee name */
/*void bstRemove(BSTnode *tp);


#endif	/* included */
