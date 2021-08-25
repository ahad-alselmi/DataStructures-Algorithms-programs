// Implementaion_queueByArray_AHAD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Queue {
	int size;
	int rear;
	int front;
	int* q;
public:
	Queue() { size = 10; rear = -1; front = -1; q = new int[size]; }

	Queue(int size) { this->size =size; rear = -1; front = -1; q = new int[this->size]; }

	void enqueue(int x) {
		if (rear == size - 1)//check if the queue is full
			cout << "The queue is Full";

		else {

			rear++;
			q[rear] = x;
		}
	}

	void Dequeue() {
		 int x = -1;
		if (front == rear)
			cout << "The queue is Empty";
		else {
			x = q[front+1];//Delete first element in the dequeue 
			front++;
		
		}
		
	}
	void Display() {
		for (int i = front + 1; i <= rear; i++)
			cout << q[i]<<endl;
	 }

};


int main()
{
	Queue qu;
	qu.enqueue(10);
	qu.enqueue(20);
	qu.enqueue(30);
	qu.enqueue(40);
	qu.Display();
	qu.Dequeue();
	qu.Dequeue();
	qu.Display();
	


	
}

