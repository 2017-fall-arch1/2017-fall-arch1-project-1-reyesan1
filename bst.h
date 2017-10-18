/*#ifndef bstree_included		/* prevent multiple inclusion */
/*#define bstree_included
 

/* a binary search tree tnode */
typedef struct BSTnode {
  // Points to left child
  struct BSTnode *left;

  // Points to right child
  struct BSTnode *right;

  // Points to name in tree
  char *name;
  
} BSTnode;


/* creates a new binary search tree */
BSTnode *bstAlloc();

/* free memory associated with a tree, discarding all items it contains */
void bstFree(BSTnode *tp);

/* adding a new node to the tree */
BSTnode *bstInsert(BSTnode *tp, char *name);

/* Delete all elements off of the tree */
void bstMakeEmpty(BSTnode *tp);

/* print tree contents */
void bstPrint(BSTnode *tp);

/* search method to find pointer to node to delete */
BSTnode *search(BSTnode *bst, char *name);

/* Method to find minimum node in a branch */
BSTnode *min(BSTnode *tp);

/* remove employee name */
BSTnode *bstRemove(BSTnode *tp, char *n);


/*#endif	/* included */
