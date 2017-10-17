#ifndef binarySearchTree_included
#define binarySearchTree_included

//items in a node leftnode and right node
typedef struct nodes{
  struct nodes *leftNode;
  struct nodes *rightNode;
  struct nodes *parentNode;
  char *str;
}node;

typedef struct bst{
  node * theroot;

}bst;

 bst *allocCreateNewBST();
node *allocCreateNewNode(char *str);
void insertNode(bst* theBst, char *str);
void printTree(node *node);
void deleteName(node *node,char *name);
void iterate(node *node);
void printTreeToTxt(char *file,node *node);
void addTextToFile(char *file,char *text);
#endif
