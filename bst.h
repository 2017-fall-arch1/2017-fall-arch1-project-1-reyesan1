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

extern int bstDoCheck;		/* set true for paranoid consistency checking */

/* creates a new binary search tree */
BSTree *bstAlloc();

/* free memory associated with a tree, discarding all items it contains */
void bstFree(BSTree *tp);

/* append a copy of str to end of list */
void llPut(LList *lp, char *s);

/* Delete all elements off of the list */
void llMakeEmpty(LList *lp);

/* print tree contents.  Prints default message if tree is NULL */
void bstPrint(BSTree *tp, char *word);

/* check llist consistency, always returns zero */
int llCheck(LList *lp);

/* add employee name */
void bstAdd(BSTnode *tp);

/* remove employee name */
void bstRemove(BSTnode *tp);



#endif	/* included */
