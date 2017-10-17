#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"
#include <string.h>
#include <stdbool.h>

#define bufsize 1024
//reference tutorial by theNewBoston youtube tutorial
//reference https://cboard.cprogramming.com/c-programming/61723-problem-storing-data-binary-search-tree.html
void scanFile(bst *newBst,char *fileName){
  FILE *filePointer;
  char buf[bufsize];
  filePointer = fopen(fileName,"r");
  if(!filePointer){
    printf("(Error File employeesNames.txt does not exist)\n");//if file does not exist print this for the user
  }
  else{
    printf("(File employeesNames.txt was opened sucessfully)\n");
    while(fgets(buf,sizeof(buf),filePointer)!=NULL){
      buf[strlen(buf)-1] = '\0';
      printf("%s\n",buf);
    }
    
}
  fclose(filePointer);
	
}

int main()
{                                                                                  
  bst *newBst= allocCreateNewBST();
  char *cmnd = (char*)malloc(2);
  
  //printf("%s\n",newBst->theroot->leftNode->rightNode->str);
  printf("||||||||||||||||||||||||||||\n");
  printf("||Company Employess System||\n");
  printf("||||||||||||||||||||||||||||\n");
  //deleteName(newBst->theroot,"C");//Attempted to delete Node from bst
  scanFile(newBst,"employeesNames.txt");
  
  printf("\nTxt file list sorted in binary search tree\n");
  printTree(newBst->theroot);
  int i = 50;
  
  for(int s=0;s<i;s++){
    char *name=(char*)malloc(20);
    char answer[1];
    char *nameToDel=(char*)malloc(20);
    
  printf("Add new Employee Name:");
  scanf("%s",name);
  
  printf("Do you want to add a new Employee. Type [Y] for yes [N] for No and [DEL] to delete\n");
  scanf("%s",answer);
  insertNode(newBst,name);
  int compareStr = strcmp(answer, "Y");
  int compareDEL = strcmp(answer, "DEL");
  //if Answer is Y it will return a zero dont do anything continue loop
  if(compareStr==0){
   
  }
  else if (compareDEL==0){
    printf("Enter the name you want to delete:\n");
    scanf("%s",nameToDel);

    deleteName(newBst->theroot,nameToDel);

    printTree(newBst->theroot);
  }
  else{
    s=49;
  }
  }
  printf("=====================================\n");
  printf("Employees Name List:\n\n");
  printTree(newBst->theroot);
 
  printf("\n====================================");
  return 0;

}
