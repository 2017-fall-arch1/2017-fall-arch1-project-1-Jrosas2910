//Javier Rosas
//Lab Project 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarySearchTree.h" //Still need to implement binarySearchTree.h


//Allocate memory for new Binary Search Tree and create a new binary Search Tree
bst * allocCreateNewBst(){
  bst * newbst = (bst *)malloc(sizeof(bst));
  newbst->theroot = 0;
  return newbst;
}
node *allocCreateNewNode(char *str){
  node *newNode = (node *)malloc(sizeof(node));
  newNode->leftNode = NULL;
  newNode->rightNode = NULL;
  newNode->str = str;
  return newNode;
}
/*Insert a node. Create a new node. If binary search tree
root == null it means the binary tree is empty. So we place
the firts node on root. If root is not null it means we have 
to compare strings and figure out where to place the new 
Node.
 */
void insertNode(bst * bstree, char *name){
  node *tempNode = allocCreateNewNode(name);
  
  //if root is null place node in root
  if(bstree->theroot==NULL){
    bstree->theroot = tempNode;
    printf("this is the root %s\n",name);
   
  }
  //if root is not null compare strings
  else{
    
  }
  

}
