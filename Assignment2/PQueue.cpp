/*
* Circular array-based implementation.
* The array has indexes to the front and back of the
* queue. A counter tracks the number of items currently
* in the queue.
*
* @author Taha Hakkani
* @credit Yanping Zhang (for template)
* @version Assignment 1
* @date January 22 2019
* @file QueueA.h
*/


#include "PQueue.h"  // header file
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue()
{
}  // end default constructor


void PriorityQueue::enqueue(QueueItemType& newItem) throw (QueueException)
{
	if(isFull())
		throw QueueException("PriorityQueue::enqueue says: 'Queue is full, try again later!'");
	else if(isEmpty()){
		back = (back + 1) % MAX_QUEUE;
		items[back] = newItem;
		count++;
	}
	//compares newItem with values already in the queue, starting from the back and working forward.
	else{
		int compareIndex = back; //indexes the item in the queue to be compared
		int countIndex = count; //indexes how many items have been compared (so that you
	  while (newItem > items[compareIndex] && countIndex > 0){
		  items[(compareIndex + 1) % MAX_QUEUE] = items[compareIndex];
		  compareIndex = (compareIndex - 1) % MAX_QUEUE;
		  countIndex--;
		}
	items[compareIndex + 1] = newItem;
	count++;
	back = (back + 1) % MAX_QUEUE;
	}

}  // end enqueue


// End of implementation file.
