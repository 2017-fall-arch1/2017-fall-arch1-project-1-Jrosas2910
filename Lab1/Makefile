all: myMain


myMain: binarySearchTree.o myMain.o
	cc -o $@ $^

binarySearchTree.o: binarySearchTree.c binarySearchTree.h
	cc -c $(CFLAGS) binarySearchTree.c

myMain.o: myMain.c binarySearchTree.h
	cc -c $(CFLAGS) myMain.c

clean:
	rm -f *.o myMain '#myMain.c#' Makefile~ *.c~ *.md~ *.h~ *.txt~ '#employeesNames.txt#' 

main: myMain
	./myMain

