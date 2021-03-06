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
    
  printf("===============================================\nType [QUIT] to quit\nType [LIST] to show list\nType [DEL] to delete name from list\nAdd new Employee Name:\n");
  scanf("%s",name);
  int compareQUIT1 = strcmp(name,"QUIT");
  if(compareQUIT1==0){
    s=50;
    break;
  }

  int compareDEL = strcmp(name, "DEL");
  int compareLIST = strcmp(name, "LIST");
  int compareQUIT2 = strcmp(name,"QUIT");
  //if Answer is Y it will return a zero dont do anything continue loop
  if (compareDEL==0){
    printf("\nEnter the name you want to delete:\n");
    scanf("%s",nameToDel);

     deleteName(newBst,nameToDel);
    printTreeConsole(newBst->theroot);
  }
  else if(compareQUIT2 ==0){
    s=50;
  }
  else if (compareLIST==0){
printTreeConsole(newBst->theroot);
  }
  else{
   insertNode(newBst,strcat(name,"\n"));
  }
  }
  printf("=====================================\n");
  printf("Employees Name List:\n\n");
addTextToFileOverwrite("employeesNames.txt","");
printTreeToFile(newBst->theroot);
  printf("\n==============END OF PROGRAM==================\n");
  return 0;
}
