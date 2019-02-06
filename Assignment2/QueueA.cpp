/**
* @author Taha Hakkani
* @credit Yanping Zhang (for template)
* @version Assignment 1
* @date January 22 2019
* @file QueueA.h

* Circular array-based implementation.
* The array has indexes to the front and back of the
* queue. A counter tracks the number of items currently
* in the queue. */

#include "QueueA.h"  // header file
#include <iostream>
using namespace std;

Queue::Queue() : front(0), back(MAX_QUEUE-1), count(0)
{
}  // end default constructor

bool Queue::isEmpty() const
{
  if(count < 1)
    return true;
  return false;
}  // end isEmpty

bool Queue::isFull() const
{
	if(count < MAX_QUEUE)
		return false;
	return true;
} // end isFull

void Queue::enqueue(QueueItemType& newItem) throw (QueueException)
{
  if(isFull())
		throw QueueException("Queue::enqueue says: 'All full asshat! sucks to suck!'");
	back = (back + 1) % MAX_QUEUE;
	items[back] = newItem;
  count++;


}  // end enqueue

void Queue::dequeue() throw (QueueException)
{
	if(isEmpty())
		throw QueueException("Queue::dequeue() says: 'This queue is empty, dummy!'");
  front = (front + 1) % MAX_QUEUE;
	count --;
}  // end dequeue

//retreives the item at the front of the queue (in conjuction with returnFront(), handles exception in the case that the queue is empty
QueueItemType Queue::getFront() const throw (QueueException)
{
	if(isEmpty())
		throw QueueException("Queue::getFront() says: 'The queue is empty loser, try again!'");
	return items[front];
} // end getFront

// End of implementation file.

