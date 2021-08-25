#include<iostream>
using namespace std;
struct node {
	int value;
	node* next;

}* head;


void create(int A[], int size) {
	node* last=NULL, * t;;
	head = new node;
	head->value = A[0];
	head->next = NULL;;
	last = head;
	for (int i = 1; i < size; i++) {
		t = new node;
		t->value = A[i];
		t->next = NULL;
		last->next = t;
		last = t;

	 }
}




 void middel(node* q) {
	 node* p = NULL;
	 p=q= head;
	  while (q) {
		
		q = q->next;
		if (q)
			q = q->next;
		if(q)
		p = p->next;
	}
   cout << p->value;
}

 int main() {
	 int A[] = { 8,6,3,9,10,4,2,8,5,6 };
	 int size = 10;
	 create(A, size);
	 middel(head);

 
 }
