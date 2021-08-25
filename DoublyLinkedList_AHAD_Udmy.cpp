#include<iostream>
using namespace std;
struct node {
	node* prev;
	int data;
	node* next;
}* first;

void create(int A[], int n) {

	node* t, * last;
	first = new node;
	first->prev = NULL;
	first->data = A[0];
	first->next = NULL;
	last = first;
	for (int i = 1; i < n; i++) {
		t = new node;
		t->data = A[i];
		t->next = last->next;//help for insert new node after last node????
		t->prev = last;
		last->next = t;
		last = t;
}
}	

void display(node* p) {

	while (p) {
		cout << p->data << endl;
		p = p->next;
	}
 }
  int length(node *p){
	  int count = 0;
	  while (p) {
		  p = p->next;
           count++;
	  }
		  
	  return count;
  }
  void insert(node* p, int index,int x) {
	  node* q =new node;
	  if (index <0 || index >length(first))
		  return;
	  if (index == 0) {
		 //p = first;
		//  q = new node;
		  q->data = x;
		  q->prev = NULL;q->next = first;//why should I use first instead of p while they are same
		  // because  it is the first node so we should use first
		  first->prev = q;
		  
		  first = q;
	  }
	  /*else {
		  for (int i = 0; i < index - 1; i++)
			  p = p->next;
		  q->data = x;
		  q->next =p->next ;
		  p->next = q;
		  if (p->next)//if still there is next node
			  p->next->prev = q;
		  q->prev = p;


	  }*/
   }
  //this is my solution my delete algorithm
  void Delete(node* p, int index) {
	  int x = -1;
	  if (index <0 || index >length(first))
		  return;
	  if (index == 1) {
		  p = first;
		  first = first->next;
		  delete p;
		  if (first)//we need this condition to make sure there is next node because if there is not next node 
			  // we do not need previous 
			  first->prev = NULL;
	  }
	  else {
		  node* q;
		  for (int i = 0; i < index -2; i++) {
			  q = p;
			  p = p->next;
		  }

		  q = p->next;
		  p->next = q->next;//for last index it will connect p with q->next which is NULL 
		 
		  if (q->next) {//in last index will not enter this conndition because NULL does not have previous
			  q->next->prev = q->prev; 
		  }
		  
		 // q->data = x;
		  delete q;
	  }//else

  }
  void reverse(node* p) {//my algorithm
	  p = first;
	  while (p) {
		  p = p->next;
	  }
	  while (p) {
		  p->next = first->prev;
		  p->prev = NULL;
		  first = first->next;
		  first->next = NULL;
	  }
}
	  
	  
  void reverse1(node* p) {
	  p = first;
	  while (p) {
		  node* temp = p->next;
		  p->next = p->prev;
		  p->prev = temp;
		  p = p->prev;
		  if (p != NULL && p->next == NULL) {
		  first = p;
	  }
	  }
	  

}
  
  
  

  int main() {
	  int A[] = { 1,2,3,4,5 };
	  create(A, 5);
	  //display(first);
	  //cout << "length is : " << length(first)<<endl;
	  insert(first, 0, 8);
	 // display(first);
	  //Delete(first, 5);
	 // reverse(first);
	  //reverse1(first);
	  display(first);
  }