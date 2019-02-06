/**
* @author Taha Hakkani
* @credit Yanping Zhang (for template)
* @version Assignment 1
* @date January 22 2019
* @file QueueA.h
*/

#include "QueueA.h"
#include "QueueException.h"
#ifndef PRIORITYQUEUEA_H
#define PRIORITYQUEUEA_H


/** @class Queue
 * ADT queue - Array-based implementation. */
class PriorityQueue: public Queue
{
public:

   /** Default constructor. */
   PriorityQueue();

   void enqueue(QueueItemType& newItem) throw (QueueException);


}; // end Queue
#endif
// End of header file.
