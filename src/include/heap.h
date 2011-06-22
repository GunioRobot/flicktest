#define HEAPMAXLEN    100

#define MINHEAP_SUCC  0
#define MINHEAP_FAIL  1
#define MINHEAP_BARGS 2
#define MINHEAP_FULL  3

typedef struct minheap
{
  unsigned int len;
  unsigned int max_len;
  void *data[HEAPMAXLEN];
  int (*cmp)(void*, void*);
  int (*dis)(void*);
}minheap;
