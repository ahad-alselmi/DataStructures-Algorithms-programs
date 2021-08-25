#include<iostream>
using namespace std;

struct node {
	node* prev;
	int data;
	node* next;
}*head;

  void create(int A[], int size) {
	node* last, *t;// t is next node
	head = new node;
	head->data = A[0];
	head->prev = head;//because it is first node so should pointing on it is self because it is circular
	head->next = head;
	last =head ;
	
	for (int i = 1; i < size; i++) {
		t = new node;
		t->data = A[i];
		t->next = last->next;//coz it is circular in normal will point on null but next here for 
		//make chain of nodes where each node contain address of the next node
		last->prev = t;//coz it is circular
		last->next = t; // coz it is doubly
		t->prev = last;//coz it is doubly
		last = t;}
}


  void display(node* p) {

	  do {
		  cout << p->data<<",";
		  p = p->next;
	  } while (p!= head);
	  cout << endl;
	 }

  int count(node* p) {
	  int count = 0;
	  do {
		  p = p->next;
		  count++;
	  } while (p != head);
	  //cout << "the length of List  ";
		  return count;
  
  }

  void insert(node* p, int index, int value) {
	  node* t;
	  if (index<0 || index > count(head))
		  return;

	  if (index == 0) {
		  t = new node;
		 // t->data = value;
		  if (head == NULL) {
			  head = t;
			  head->next = head;
			  head->prev = head;
		  }
		 /* else {
				 // while (head->prev->next != head)
				 // head = head->next;
			      t->data = value;
				  t->next = head;
				  t->prev = head->prev->next;
				  head->prev->next = t; 
				  head->prev = t;
				  head = t;
			}	*/
		  else {//in certain  postion
			  p = head;
			  while(p->next != head)
			  p = p->next;
			  t->data = value;
			  t->next = head;
			  p->next = t;
			  t->prev = p->next;
			  head->prev = t;
			  head = t;

		  
		  
		  
		  }
		}	 
	  else {//in certain position
		  t = new node;
		  t->data = value;
		  p = head;
		  for (int i = 0; i < index - 1; i++)
			  p = p->next;
		 t->next =p->next;
		 t->prev = p;
		 p->next = t;
	   p->next->prev = t;
      }
  }

  void  Delete(node* p, int index) {
	  node* q=NULL;
	  int x=0;
	  if (index == 0) {
		  p = head;
		  while (p->next != head){//move to last node
			  p = p->next;
	          }//while
	  p->next = head->prev;//last node next point to first node previous
		  delete head;//delete first node after moving and after conect last with first
		  head = p->next; //give new value to head
	  }//if
	  else {
		  p = head;
		  for (int i = 0; i < index -1; i++){//why does not work with index -2
			  p = p->next;}//go to position
		  q = p->next;//q= the node we want to delete
		  p->next = q->next;//connect p with the node after delete node
		  q->next->prev = p->next;//to make it double connect two nodes then delete
		  delete q;
		  //make it to work with one pointer
	  }
	  }
  
  


	  
		  
	  
 
		   
 int main() {
	int A[] = {1,2,3,4};
	create(A,4);
	//display(head);
	//cout<<count(head);
	//insert(head, 0, 8);
	Delete(head,2);
	display(head);

}

