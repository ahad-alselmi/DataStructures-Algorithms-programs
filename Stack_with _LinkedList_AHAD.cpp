// Stack_with _LinkedList_AHAD.cpp 
#include <iostream>
using namespace std;

struct node {

	int data;
	node* next;
}*top=NULL;

 /*void create(node* p,int a[],int size) {//not important here because just i need to push
	node* last,* t = NULL;
	top = new node;
	top->data = a[0];
	top->next = NULL;
	last = top;
	for (int i = 1; i < size; i++) {
		t = new node;
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
		}
	 }*/

void push(int x) {
	node* t = new node;
	//check if it is full
	if (t == NULL)
		cout << "stack overflow";
	else {
		t->data = x;
		t->next = top;
		top = t;
}
}
	
int pop() {
	node* t;
	int x = -1;
	//check if the stack null because we need to delete a node 
	if (top == NULL)
		cout << "stack underflow";
	else{
	t = top;
	top = top->next;
	
     x= t->data;
	delete t;
    }
	
	return x;
}
void display() {
	node* p;
	p = top;
	while (p != NULL) {

		cout << p->data << endl;
		p = p->next;
	 }


}














int main()
{
	push(10);
	push(20);
	push(30);
	display();
	cout << "this is delete it  " << pop();
}


