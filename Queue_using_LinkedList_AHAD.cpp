// Queue_using_LinkedList_AHAD.cpp 
//AHAD_ALSELMI
#include<iostream>
using namespace std;

struct node {
	int value;
	node* next;
}*front=NULL ,*rear=NULL;

void enqueue(int x) {
	//check if queue is full
	node*p = new node;
	if (p == NULL)
		cout << "Queue is Full";
	else {//Making first node
		p->value = x;
		p->next = NULL;
		//make front and rear point on first node
		if (front == NULL)
			front = rear = p;
	
	// Making the remaining nodes
	else {
			rear->next = p;
			rear = p;
}
}
}

void dequeue() {//deleting nodes
	int x = -1;
	node* p;// temprory pointer  pointing to deleting node 
	//check if queue is empty
	if (front == NULL)
		cout << "Queue is Empty";
	else {
		p = front;
		front = front->next;
		x = p->value;
		delete p;
	}
     } 
void Display() {
	
		node* p=front;
		while (p != NULL) {
			cout << p->value << endl;
			p = p->next;
		}
	}


int main()
{
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	Display();
	dequeue();
	cout << "After deleting "<<endl;
     Display();

}

