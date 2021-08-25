#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
}*head;

   void create(int arr[], int size) {
	node* nextnode;  node*last = NULL;
	head = new node;
	head->data = arr[0];
	head->next = head;//beacuse it is circular if not circular will be =NULL
	last = head;

	for (int i = 1; i < size; i++) {
		nextnode = new node;
		nextnode->data= arr[i];
		nextnode->next = last->next;//should be null in normal linked list  
		last->next = nextnode;
		last = nextnode;
}
}
   void display(node * h) {
	   if (!h)
		   return;
	   do{
	   cout << h->data << endl;
	   h = h->next;
	   } while (h != head);
    }

   int Delete ( node* p,int index) {
	   p = head;
	   node* q = NULL;
	   int x= - 1;
	  // if(index<0 || index >length(head))
	   if (index == 1) {
		  // p = head;
		   while (p->next != head)
			   p = p->next;
		   if (p == head) {
			   delete head;
			   head = NULL;
		   }
		   else{
		   p->next = head->next;
		   delete head;
		   head = p->next;}
	   }
	   else if (index>1){
		  /* do{
		   q = p;
		   p = p->next;
		   } while (p->next != head && index-1);

		   q->next = p->next;
		   x = p->data;
		   delete p;
		   //head  =p->next;*/
		   for (int i = 1; i < index; i++) {//OR//   for (int i = 0; i < index-1; i++)
			   q = p;
			   p = p->next;
		   }
		   q->next = p->next;
		   x = p->data;
		   delete p;
return x;
	   }
	   }

   void insert(node* p, int index, int value) {
	   node* add_new;
	   if (index == 0) {
		   add_new = new node;
		   add_new->data = value;
		   add_new->next = head;
		   while (p->next != head)
			   p = p->next;
		   p->next = add_new;
		  head = add_new;}
	   else {
		   
		   add_new = new node;
		   add_new->data = value;
            //p = head;
		   for (int i = 0; i < index - 1; i++)
			   p = p->next;
		   add_new->next = p->next;
		   p->next = add_new;


	   }


	   
	   


   }
	   
   
   
   
   int main() {
	   int arr[] = { 1,2,3,4,5 };
	   int size = 5;
	   create(arr, size);
	  // display(head);
	  // Delete(head, 2);
	  // display(head);
	   insert(head, 0, 8);
	   display(head);

   
   }
	


