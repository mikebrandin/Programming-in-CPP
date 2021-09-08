/*
Mike Brandin
CPSC 1021
February 6th, 2020
*/

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "linkedlist.h"

using namespace std;

int main (){

    NodePtr newNode = NULL;
    int num;

    FILE *fptr;

    // make sure file exists, give message and exit otherwise
    if ((fptr = fopen("input.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    cout << "After InsertStrategic: " << endl;

    // while we still have items to read
    while( fscanf(fptr,"%d", &num) != EOF){
        newNode = makeNewNode(num);
        insertStrategic(newNode);
    }
    printList();


    fclose(fptr);  // close the file


  // after you implemented your functions in .cpp file
	// - use the code below for testing your linked list.
	// Demonstrate that ALL functions are working correctly.

//TODO:
	// After that add code for reading data from input file.
	// Every time you read an integer, create a node and insert it
	// in the ascending order into the list.

	// At the end print the entire list to show that your code
	// functions correctly.


    for (int i = 0; i < 5; i++){
        newNode = makeNewNode (i);
        insertAtFront(newNode);
    }
    cout << "Original: " << endl;
    printList();

    cout << "After DeleteFromFront: " << endl;
    deleteFromFront();
    printList();

    NodePtr seven = makeNewNode(7);
    insertAtEnd(seven);
    cout <<"Inserting seven at END" << endl;
    printList();

    NodePtr eight = makeNewNode(8);
    insertAtEnd(eight);
    cout <<"Inserting eight at END" << endl;
    printList();

    cout << "After deleting eight: " << endl;
    deleteFromEnd();
    printList();

    cout << "After deleting seven:" << endl;
    deleteFromEnd();
    printList();



  return 0;
}
