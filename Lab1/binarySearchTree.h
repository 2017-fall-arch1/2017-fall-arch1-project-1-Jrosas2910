#ifndef binarySearchTree_included
#define binarySearchTree_included

//items in a node leftnode and right node
typedef struct nodes{
  struct nodes *leftNode;
  struct nodes *rightNode;
  char *str;
}node;

typedef struct{
  node * theroot;

}bst;

bst *allocCreateNewBST();
node *allocCreateNewNode(char *str);
void insertNode(bst* theBst, char *str);
void printTree(bst* theBst);
#endif
