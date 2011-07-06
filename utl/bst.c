#include "../include/bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BSTinit(bst_meta **bm, void *cmpptr, void *disptr)
{
  bst_meta *temp = NULL;

  if (bm == NULL)
    return BST_FAIL;

  temp = (bst_meta*)malloc(sizeof(bst_meta));
  if (temp == NULL)
  {
    return BST_FAIL;
  }

  temp->count  = 0;
  temp->root   = NULL;
  temp->cmpptr = cmpptr;
  temp->disptr = disptr;
  *bm          = temp;

  return BST_SUCC;
}

int BSTdeletenode(bst_node **node)
{
  if (node == NULL || *node == NULL)
    return BST_SUCC;

  BSTdeletenode(&((*node)->left));
  BSTdeletenode(&((*node)->right));

  free((*node)->element);
  free(*node);
  *node = NULL;
  return BST_SUCC;
}
int BSTdestroy(bst_meta **bm)
{
  if (bm == NULL)
    return BST_SUCC;

  BSTdeletenode(&((*bm)->root));
  free(*bm);
  *bm = NULL;
  return BST_SUCC;
}

int BSTaddnode(bst_meta *bm, bst_node *parent, bst_node **node, void *data, 
                     unsigned int dsize)
{
  bst_node *temp = NULL;
  int i = 0;

  if (node == NULL)
    return BST_FAIL;

  if (*node == NULL)
  {
    temp = (bst_node*)malloc(sizeof(bst_node));
    if (temp == NULL)
    {
      return  BST_FAIL;
    }
    temp->element = malloc(dsize);
    if (temp->element == NULL)
    {
      return  BST_FAIL;
    }

    memcpy(temp->element, data, dsize);
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = parent;
    *node = temp;
    return BST_SUCC;
  }

  i = (*bm->cmpptr)(data, (*node)->element);
  if (i >= 0)
    return BSTaddnode(bm, (*node)->element, &((*node)->right), data, dsize);
  else
    return BSTaddnode(bm, (*node)->element, &((*node)->left), data, dsize);
}

int BSTadd(bst_meta *bm, void *data, unsigned int dsize)
{
  if (bm == NULL)
    return BST_FAIL;

  BSTaddnode(bm, NULL, &(bm->root), data, dsize);
  bm->count++;
  return BST_SUCC;
}
