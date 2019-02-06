#include "QueueA.cpp"
#include "PQueue.cpp"
#include "QueueException.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	PriorityQueue pQ;
	Queue q;
	Queue *qptr = &q;
	//The following test assigns random
	//integers between 0 and 99 to both
	//queues and then proceeds to dequeue
	//and display the front of each queue
	//to see if they, in fact, were
	//queued in the right order. It also
	//tests if the queue is empty or full.

	srand((unsigned)time(0));
	int iter = 0; //tracks how many times the pointer changes
	do{
    for(int i = 0; i < MAX_QUEUE; i++){
		  QueueItemType item = rand() % 100;
		  qptr->enqueue(item);
  	}
  		
  	try{
			QueueItemType qIT = 9;
			qptr->enqueue(qIT);
		}
		catch(QueueException &e){
			cout << e.what() << endl;
		}
		
  	for(int i = 0; i < MAX_QUEUE; i++){
  		cout << qptr->getFront() << "  ";
 	    qptr->dequeue();
  	}
  	if(qptr->isEmpty())
  		cout << "\nQueue is empty\n";
  	try{
			qptr->dequeue();
		}
  	catch(QueueException &e){
			cout << e.what() << endl;
		}
  	try{
			qptr->getFront();
		}
		catch(QueueException &e){
			cout << e.what() << endl;
		}
		
  	iter ++;
  	qptr = &pQ;
	}while(iter < 2);
}
