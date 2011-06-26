#define HEAPMAXLEN    10000

#define MINHEAP_SUCC  0
#define MINHEAP_FAIL  1
#define MINHEAP_BARGS 2
#define MINHEAP_FULL  3

typedef struct minheap
{
  unsigned int len;         /* current length             */
  unsigned int max_len;     /* max allowed lenght of heap */
  void *data[HEAPMAXLEN];   /* actual data                */
  int (*cmp)(void*, void*); /* compare function pointer   */
  int (*dis)(void*);        /* display function pointer   */
}minheap;

int minheap_init(minheap **heap, unsigned int max_len, void *cmp, void *dis);
int minheap_add(minheap *hp, void *data, unsigned int size);
int minheap_traverse(minheap *hp);
int minheap_rmroot(minheap *hp, void *ele, unsigned int esize);
