/**
* @author Taha Hakkani
* @credit Yanping Zhang (for template)
* @version Assignment 1
* @date January 22 2019
* @file QueueA.h
*/
#include "QueueException.h"
#ifndef QUEUEA_H
#define QUEUEA_H
//const int MAX_QUEUE = maximum-size-of-queue;
//typedef desired-type-of-queue-item QueueItemType;
const int MAX_QUEUE = 15;
typedef int QueueItemType;

/** @class Queue
 * ADT queue - Array-based implementation. */
class Queue
{
public:
// constructors and destructor:
   /** Default constructor. */
   Queue();
   // copy constructor and destructor are
   // supplied by the compiler

// Queue operations:
   bool isEmpty() const;
   bool isFull() const;
   virtual void enqueue(QueueItemType& newItem) throw (QueueException);
   void dequeue() throw (QueueException);
   QueueItemType getFront() const throw (QueueException);

protected:
   QueueItemType items[MAX_QUEUE];
   int           front;
   int           back;
   int           count;
}; // end Queue
#endif
// End of header file	.
