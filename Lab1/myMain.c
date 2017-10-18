#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"
#include <string.h>
#include <stdbool.h>


//reference tutorial by theNewBoston youtube tutorial
//reference https://cboard.cprogramming.com/c-programming/61723-problem-storing-data-binary-search-tree.html
void scanFile(bst *newBst,char *fileName){
 FILE *filePointer;
char buf[40];
  filePointer = fopen(fileName,"r");
  if(!filePointer){
    printf("(Error File employeesNames.txt does not exist)\n");//if file does not exist print this for the user
  }
  else{
    printf("(File employeesNames.txt was opened sucessfully)\n");
    while(fgets(buf,40,filePointer)!=NULL){
if(strcmp(buf,"\n")==0){

}else{

      insertNode(newBst,buf);
//printf("root is %s\n",newBst->theroot->str);
// printf("While %s\n",newBst->theroot->str);
}
    }
   
    
}
fclose(filePointer);
	
}

int main()
{                                                                             
  bst *newBst= allocCreateNewBST();
  char *cmnd = (char*)malloc(2);
  printf("FirstLine\n");
  //insertNode(newBst,"J");
   //insertNode(newBst,"T");
  //insertNode(newBst,"C");
  //insertNode(newBst,"E");
  //insertNode(newBst,"B");
  //insertNode(newBst,"A");
  //insertNode(newBst,"Z");
  //printTreeConsole(newBst->theroot);
  
  //printf("%s\n",newBst->theroot->leftNode->rightNode->str);
  printf("||||||||||||||||||||||||||||\n");
  printf("||Company Employess System||\n");
  printf("||||||||||||||||||||||||||||\n");
  //deleteName(newBst->theroot,"C");//Attempted to delete Node from bst
printf("Employees Names from list\n");
//scanFilewithoutinsertion(newBst,"employeesNames.txt");

scanFile(newBst,"employeesNames.txt");
  
  printf("\nTxt file list sorted in binary search tree\n");
  printTreeConsole(newBst->theroot);
  int i = 50;
  
  for(int s=0;s<i;s++){
    char *name=(char*)malloc(20);
    char answer[1];
    char *nameToDel=(char*)malloc(20);
    
  printf("\nAdd new Employee Name: ");
  scanf("%s",name);
  int compareQUIT1 = strcmp(name,"QUIT");
  if(compareQUIT1==0){
    s=50;
    break;
  }
  printf("Do you want to add a new Employee. \nType [Y] for yes [N] for No \n[DEL] to delete\n[LIST] to show list\n");
  scanf("%s",answer);
insertNode(newBst,strcat(name,"\n"));
  int compareStr = strcmp(answer, "Y");
  int compareDEL = strcmp(answer, "DEL");
  int compareLIST = strcmp(answer, "LIST");
  int compareQUIT2 = strcmp(answer,"QUIT");
  //if Answer is Y it will return a zero dont do anything continue loop
  if(compareStr==0){
   
  }
  else if (compareDEL==0){
    printf("Enter the name you want to delete:\n");
    scanf("%s",nameToDel);

    deleteName(newBst->theroot,nameToDel);

    printTreeConsole(newBst->theroot);
  }
  else if(compareQUIT2 ==0){
    s=49;
  }
  else if (compareLIST==0){
printTreeConsole(newBst->theroot);
  }
  else{
    s=49;
  }
  }
  printf("=====================================\n");
  printf("Employees Name List:\n\n");
addTextToFileOverwrite("employeesNames.txt","");
printTreeToFile(newBst->theroot);
  printf("\n====================================");
  return 0;
}
