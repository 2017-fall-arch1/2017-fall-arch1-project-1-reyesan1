# arch1-linked-list-demo

This directory contains:
* code that implements a binary tree of strings 
* a demo program that lets user enter a list of employees

The demo program reads lines from stdin.
Each line is inserted into a binary search tree.
After 'q' is read, the user is prompted to choose whether to print or remove an employee name. Then, they may choose 'e' to exit.

This demo contains the following files:
 bst.h: header file of bst structure & "public" interface functions
 bst.c: implementation of binary search tree
 bstDemo.c: a demonstration program that uses the binary tree
 

To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ make demo
~~~

To delete binaries:
~~~
$ make clean
~~~


