//Javier Rosas
//Lab Project 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarySearchTree.h" 


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


node *cursorPrev=NULL;
node *cursor=NULL;
void insertNode(bst * bstree, char *name){
  
  node *newNode;
  int len;
  char *nameCopy;
  //algorithm by Dr. Eric Freudenthal demo
    for(len=0;name[len];len++);//compute length
  nameCopy = (char *)malloc(len+1);
  for(len = 0; name[len];len++)
    nameCopy[len] = name[len];
    nameCopy[len]=0;
  
          newNode = allocCreateNewNode(name);
	  newNode->str=nameCopy;
	  newNode->rightNode=NULL;
	  newNode->leftNode=NULL;
	  newNode->parentNode=NULL;
	  //printf("Printing%s",newNode->str);
  
  //if root is null place node in root
  if(bstree->theroot==NULL){
    //     printf("root is null");
    bstree->theroot = newNode;
    cursor=bstree->theroot;
    cursorPrev = bstree->theroot;
    bstree->theroot->parentNode=NULL;
  }
  //if root is not null compare strings
    else{
      int cmpNum= strcmp(cursor->str,name);
      // printf("gone here %d",cmpNum);
      // printf(" names %s ",cursor->str);
      // printf(" InputFileName %s",name);
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
	  //   printf("gone here 1");
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
	  // printf("gone here 2");
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
	  //printf("gone here 3");  
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
	  // printf("gone here 4");
	}
      }
    }
}
/*
For Printing a whole binary tree in postOrder
Print tree in postOrder logic from  
 "www.geeksforgeeks.org/tree-traversal-inorder-preorder-and-postorder/"
 */
//print only the tree to the console not the file
void printTreeConsole(node *node){
if(node == NULL)
      return;
     printf("%s",node->str);
   
    printTreeConsole(node->leftNode);
    printTreeConsole(node->rightNode);
}
//print the sorted tree to file
void printTreeToFile(node *node){
  if(node==NULL)
    return;
  printf("%s",node->str);
  addTextToFile("employeesNames.txt",node->str);  
    printTreeToFile(node->leftNode);
    printTreeToFile(node->rightNode);
    /*   file= fopen(filename,"a");
  fprintf(file, "%s",node->str);
  printTreeToTxt(filename,node->leftNode);
  printTreeToTxt(filename,node->rightNode);*/
  
}
//overwrite text from file
void addTextToFileOverwrite(char *filename, char *text){
FILE *file;
  file = fopen(filename,"w");
  fputs(text,file);
  fclose(file);
}
//Add single char to file
void addTextToFile(char *filename,char *text){
  FILE *file;
  file = fopen(filename,"a");
  fputs(text,file);
  fclose(file);
  
  
}
/*delete char
some chars have a new line. And when comparing two
strings that are the same it returns they are not equal
because of the new line. This method will remove the new line */
void deleteNewLinefromChar(char *name){
  
 
  // printf("Print is %s",name[0]);
  int booleanFlag=0;
  for(int i = 0;i<strlen(name);i++){
    if(name[i]=='\n'){
      printf("FOUNDSS");
      booleanFlag=1;
    }
  }
  if(booleanFlag==0){
    char *copy= (char*)malloc(strlen(name)-1);
    for(int i = 0;i<(strlen(name)-1);i++){
      copy[i]=name[i];
      
  }
    name = copy;
    
  }
  
    
}
/*
delete name from tree
there is only three ways to delete a node
if currentNode has one left child, current node has two childs, or current node has one right child.
 */
void deleteName(bst *bst,char *name){
  //scan the file for deletion
  node *pointer=bst->theroot;
  node *secPointer = bst->theroot;

   deleteNewLinefromChar(pointer->str);
   //Delete last garbage line from pointer->str and copy everything
   char *copy=(char *)malloc(strlen(pointer->str)-1);
 for(int i = 0;i<(strlen(pointer->str));i++){
   if(i==(strlen(pointer->str))){
   }else{
      copy[i]=pointer->str[i-1];
   }
  }
 //assign the new copy to pointer->str
 pointer->str=copy;
  int pointerLength= strlen(pointer->str);
  int nameLength = strlen(name);
  int cmpStrings = strcmp(pointer->str,name);
  //first check if root is the name we are looking for
  // printf("CompareNumber %d\n",cmpStrings);
  if(cmpStrings==0||pointer->str==name){
    //check if root contains a right node
    if(pointer->rightNode!=NULL){
      secPointer = pointer->rightNode;//change second pointer to right of root
      pointer = pointer->leftNode;
      free(pointer->parentNode);//free allocated memory of node to be deleted
      
      //We want to reach a leaf to move the right side of the root node
      while(pointer->rightNode!=NULL){
	pointer = pointer->rightNode;//MovePointerRight until reach an end
       
      }
      //we have reached a leaf
      if(pointer->rightNode==NULL){
	pointer->rightNode= secPointer;
	pointer=bst->theroot;
      }
    }
    else{
      //if root right node == Null then just delete root and make the left Node a root of the tree
      //printf("passing thru else");
      pointer=pointer->leftNode;//Check this one
      free(pointer->parentNode);//free allocated memory of node to be deleted
      pointer=bst->theroot;//move pointers back to the root
      secPointer=bst->theroot;
    }
  }
  //This means that employee was not found on the root. We have to search the whole tree
  else{
    //node *enode=FindNode(pointer,name);
    /*
    if(enode==NULL){
      printf("\nEmployee was not found\n");
    }
    //Employee was found begin removal process
    else{
      pointer=enode;
      secPointer=enode;


      printf("EMPLOYEE WAS FOUND");
      
    
  
      }*/
  }
}




