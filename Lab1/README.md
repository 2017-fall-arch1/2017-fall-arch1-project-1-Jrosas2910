#Project 1: Managament System#

This demo program allows
*Reads a .txt file with unsorted names and returns a the names in a preorder
*Adds names from .txt file to a binary tree. Once names are in binary tree new names can be entered.
*code implements a binary search tree of strings.
*insert employee names to a txt file.
*displays in preorder format all the names.

The program has a user interface to insert new employee names into a text file. After every employee is entered into the system. The system displays the employees in preorder format. When the user is done entering new names the sorted list of employee names get added to a txt file.

This demo constains the following files :binarySearchTree.h : header file & "public interface functions. binarySearchTree.c implementation of binary search tree. myMain.c a demostration of a program that uses the binary search tree.


To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ make main
~~~

To delete binaries:
~~~
$ make clean
~~~