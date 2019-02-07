#include "QueueA.cpp"
#include "PQueue.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool operator>(const Queue&, const Queue&);

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
	
	//testing to see if the queues are greater than or less than each other
	
	Queue q1, q2;
	QueueItemType a = 6;
	q1.enqueue(a);
	q2.enqueue(a);
	q2.enqueue(a);
	
	if(q1 < q2)
		cout << "q1 has fewer items than q2.\n";
	else if (q1 > q2)
		cout << "q1 has more items than q2.\n";
	else
		cout << "They have an equal amount of items\n";
		
	display(q1);
	display(q2);
	cout << endl << q1;
  cout << q2;
}

bool operator>(const Queue& q, const Queue& r)
{
	return q.getCount() > r.getCount();
}

void operator<<(ostream &os, const Queue& q)
{
	for(int i = 0; i < q.count; i++)
		os << q.items[(q.front + i) % MAX_QUEUE] << endl;
}
void display(const Queue &q)
{
	for(int i = 0; i < q.count; i++)
		cout << q.items[(q.front + i) % MAX_QUEUE] << endl;
}
