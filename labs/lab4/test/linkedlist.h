/*
Mike Brandin
CPSC 1021
February 6th, 2020
*/

#ifndef MYLIST_H
#define MYLIST_H

   struct listNode {
        int data;
        struct listNode* prev;
        struct listNode* next;
   };

   typedef struct listNode Node;
   typedef Node* NodePtr;


   static int nodeCount = 0;

   bool isEmpty();
   NodePtr makeNewNode(int);

   void insertStrategic(const NodePtr);

   void insertAtFront(const NodePtr);
   void insertAtEnd(const NodePtr);

   void deleteFromFront( );
   void deleteFromEnd( );

   void printList();


#endif
