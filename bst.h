/*#ifndef bstree_included		/* prevent multiple inclusion */
/*#define bstree_included
 

/* a binary search tree tnode */
typedef struct BSTnode {
  struct BSTnode *left;   /* points to left child */
  struct BSTnode *right;  /* points to the right child */
  char *name;               /* points to name in tree */
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

BSTnode *min(BSTnode *tp);

/* remove employee name */
BSTnode *bstRemove(BSTnode *tp, char *n);


/*#endif	/* included */
