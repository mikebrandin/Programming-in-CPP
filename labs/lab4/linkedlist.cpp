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

NodePtr head = NULL;
NodePtr tail = NULL;

bool isEmpty(){
   return (head == NULL);
}

NodePtr makeNewNode(int number){
   NodePtr newNode = (NodePtr) malloc(sizeof(Node));
   if(newNode != NULL){
      newNode->data = number;
      newNode->next = NULL;
   }
   return newNode;
}

void insertAtFront(const NodePtr newPtr){
    if (isEmpty()){
     head = newPtr;
	   tail = newPtr;
   }
   else{ // not empty
     newPtr->next = head;
     head = newPtr;
   }

}

void insertAtEnd(const NodePtr newPtr){//initially empty
  NodePtr temp = head;
  if (isEmpty()){
   head = newPtr;
   tail = newPtr;
  }
  else{ // not empty

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newPtr;
  }
}

void insertStrategic(const NodePtr newPtr){//initially empty
  NodePtr temp = head;
  if (isEmpty()){
    //insertAtFront(temp);

   head = newPtr;
   tail = newPtr;
   newPtr->next = NULL;
  }
  else if (newPtr->data < temp->data){
    insertAtFront(newPtr);
  }
  else{ // not empty

    while(temp->next != NULL && temp->next->data < newPtr->data){
          temp = temp->next;
    }
    newPtr->next = temp->next;
    temp->next = newPtr;
  }
}

void deleteFromFront( ){//initially empty
  NodePtr temp = head;

  if (head == NULL){
  return;
  }
  else{
  head = head->next;
  }
  delete(temp);

}

void deleteFromEnd( ){//initially empty
  NodePtr temp = head;
  NodePtr prev = head;

  if (head == NULL){
  return;
  }
  else{
  while(temp->next != NULL){
    prev= temp;
    temp = temp->next;
  }
  prev->next = NULL;
  temp = tail;
  }
}

void printList( ){
   if (isEmpty()){
     cout << "List is empty" << endl;
   }
   else {
     NodePtr temp = head;
     while (temp != NULL){
       cout << " The data is: " << temp->data << endl;
       temp = temp->next;
     }
   }
}
