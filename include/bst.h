#define BST_SUCC 0
#define BST_FAIL 1

typedef struct bst_node
{
  void *element;
  struct bst_node *left;
  struct bst_node *right;
  struct bst_node *parent;
}bst_node;

typedef struct bst_meta
{
  unsigned int count;
  bst_node *root;
  int          (*cmpptr)  (const void *, const void *);
  int          (*disptr)  (const void *);
}bst_meta;

int BSTaddnode(bst_meta *bm, bst_node *parent, bst_node **node, void *data, unsigned int dsize);

int BSTinit(bst_meta **bm, void *cmpptr, void *disptr);
int BSTadd(bst_meta *bm, void *data, unsigned int datasize);
int BSTfind(bst_meta *bm, void *data);
int BSTdestroy(bst_meta **bm);
