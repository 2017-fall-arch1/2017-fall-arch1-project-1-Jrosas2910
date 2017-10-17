//Javier Rosas
//Lab Project 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarySearchTree.h" //Still need to implement binarySearchTree.h


//Allocate memory for new Binary Search Tree and create a new binary Search Tree
bst * allocCreateNewBST(){
  bst * newbst = (bst *)malloc(sizeof(bst));
  newbst->theroot = 0;
  return newbst;
}
node *allocCreateNewNode(char *str){
  node *newNode = (node *)malloc(sizeof(node));
  newNode->leftNode = NULL;
  newNode->rightNode = NULL;
  newNode->parentNode = NULL;
  newNode->str = str;
  return newNode;
}
/*Insert a node. Create a new node. If binary search tree
root == null it means the binary tree is empty. So we place
the first node on root. If root is not null it means we have 
to compare strings and figure out where to place the new 
Node.
 */
node *cursorPrev =NULL; 
node *cursor =NULL;

void insertNode(bst * bstree, char *name){
  node *newNode = allocCreateNewNode(name);
   
  //if root is null place node in root
  if(bstree->theroot==NULL){
    bstree->theroot = newNode;
    cursor = bstree->theroot;
    cursorPrev = bstree->theroot;
    bstree->theroot->parentNode=NULL;
     
  }
  //if root is not null compare strings
    else{
      int cmpNum= strcmp(cursor->str,name);
      /*
	This means that the new node is less than the cursor
	This method will happen only when cursor is in the same position as
	the previous cursor. This means that we will only move the cursor 
	and keep the previous cursor in the binary search tree root.
       */
    
      if(cmpNum==1){
	//if left node of cursor is null place the new node
	if(cursor->leftNode==NULL){
	  cursor->leftNode=newNode;
	  
	  cursor->leftNode->parentNode=cursor;//set parent node to root which is cursorPrev
        //Just in case. Now that the new Node is placed update cursor to root for next word
	  cursor= bstree->theroot;
	  cursorPrev = bstree->theroot;
	  
	}
	/*if left node of cursor is not null then compare. 
	  Now cursor is the left node of current cursor*/
	else{
	  /*if cursor is the same as the current cursor that means
	    we only move the cursor and the parent is the root of the
	    binary search tree. If the cursor is different than the 
	    previous cursor that means we move both cursor and previous
	    cursor*/
	  if(cursor == cursorPrev){
	    cursor=cursor->leftNode;//Move only cursor to left Node
	  insertNode(bstree,name);/*recursion to check with the 
	      pointer/cursor on the left node of current cursor.*/
	  }
	  else if(cursor != cursorPrev){
	    cursorPrev= cursor;
	    cursor= cursor->leftNode;
	    insertNode(bstree,name);
	    }
	}
      }
      /*
	This means that the new Node is greater than the cursor
       */
      else if(cmpNum==-1){
	//if right node of cursor is null just place the new node
	if(cursor->rightNode==NULL){
	  cursor->rightNode =newNode;
	  
	  cursor->rightNode->parentNode = cursor;
       
	  cursor = bstree->theroot;
	  cursorPrev= bstree->theroot;
	  
	}
	/*if right node of cursor is not null then compare. 
	 Now cursor is the right node of current cursor*/
	else{
	  //means both cursors are in the root of binary search tree
	  if(cursor == cursorPrev){
	    cursor=cursor->rightNode;
	    insertNode(bstree,name);
	  }
	  else if(cursor != cursorPrev){
	    cursorPrev = cursor;
	    cursor = cursor->rightNode;
	  insertNode(bstree,name);
	}
	}
      }
    }
}
/*
For Printing a whole binary tree in postOrder
Print tree in postOrder logic from  
 "www.geeksforgeeks.org/tree-traversal-inorder-preorder-and-postorder/"
 */
  void printTree(node *node){
   
    if(node == NULL)
      return;
     printf("%s\n",node->str);
    addTextToFile("employeesNames.txt",node->str);
   
    printTree(node->leftNode);
    printTree(node->rightNode);
    
  }

void printTreeToTxt(char *filename,node *node){

  FILE *file;
  if(node==NULL)
    fclose(file);
    return;
  
  
   file= fopen(filename,"a");
  fprintf(file, "%s\n",node->str);
  printTreeToTxt(filename,node->leftNode);
  printTreeToTxt(filename,node->rightNode);
  
}
void addTextToFile(char *filename,char *text){
  FILE *file;
  file = fopen(filename,"a");
  fputs(strcat(text,"\n"),file);
  fclose(file);
  
  
}
/*
delete name from tree
there is only two ways to delete a node
if currentNode has one left child, current node has two childs, or current node has one right child.
 */
void deleteName(node *node,char *name){
  
  if(node == NULL)
      return;
    printf("%s\n",node->str);
    if(node->str==name)
      cursor=node;
    printTree(node->leftNode);
    printTree(node->rightNode);

    
    if(cursor!=NULL){
      //if node found has a left child
      if(cursor->rightNode==NULL&&cursor->leftNode!=NULL){
	cursor->parentNode->rightNode=cursor->rightNode;
      }
	//if node found has a right child

	//if node found has a right and left child
    }
}



