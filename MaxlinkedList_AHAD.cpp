#include<iostream>
using namespace std;


struct node
{
	int value;
	node* next;
}*head = NULL, *second = NULL,* third=NULL;



void push(int arr[], int size)
{
	int i;
	node* t, * last;
	head = new node;
	head->value = arr[0];
	head->next = NULL;
	last = head;
	
	for (i = 1; i < size; i++) {
		t = new node;
		t->value = arr[i];
		t->next = NULL;
		last->next = t;
		last = t;}


 	
	/*while(head!=NULL){
	cout << head->value<<endl;
	head = head->next;}*/
}
void push2(int arr[], int size)
{
	int i;
	node* t, * last;
	second = new node;
	second->value = arr[0];
	second->next = NULL;
	last = second;

	for (i = 1; i < size; i++) {
		t = new node;
		t->value = arr[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}

}


 void print(node* p) {
	 
	 while(p!=NULL){
	cout << p->value<<" ,";
	     p = p->next;}
}

int max(node* p) {
	int x = 0;
	if (p == 0)
		return INT_MIN;
	
		x = max(p->next);
		if (x > p->value)
			return x;
	

	else return p->value;
}

int sum(node *p){
	if (p == NULL) {
		return 0;
	}
	else
		return sum(p->next) + p->value;
}

int search(node *p,int key){
	while (p){
	if (key == p->value)
		return p->value;
	p = p->next;

}
	return NULL;
}

int improving_searching(node* p, int key) {
	node* q = NULL;
	q = p;//p gives its node to q OR q folllow p
	while (p != 0) {
		if (key == p->value){
			q->next = p->next;
		      p->next = head;
			    head = p;
	}
	
	p = p->next;//p countiue his road

}//while
	return key;
}

int count(node* p) {
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

void insert(node * p,int v,int index) {
	if(index <0 || index > count(p))
		return;
	node* t = new node;
	t->value = v;
	if (index == 0) {
	  t->next = head;
	  head = t;
}
	if (index > 0) {
		p = head;
		for(int i=0;i<index-1;i++)
		p=p->next;
		
		t->next = p->next;
		p->next = t;

		}

}

//function to insert node only in the last
node * InsertLast(int v) {//pass value
	node* tmp = new node;
	tmp->value = v;
	tmp->next = NULL;
	node* last=head;//represent the  end of the node 
	
	if (head == NULL) {//if linked list is empty

		head = tmp;
		return head;
	}
	
	while(last->next !=NULL){
		last = last->next;
	}
	if (last->next==NULL){
	last->next = tmp;
	last = tmp;}
	
}
//function to inseart node in sorted linked list
void InseartInSorted(node* p,int x) {
	node* q=NULL;
	node* tmp = new node;
	tmp->value = x;
	tmp->next = NULL;
	
	if (head == NULL) {
		//tmp->next = head;
		head = tmp;
	}
	
	else{
	while(p && p->value < x){ 
		q = p;
	    p = p->next;
		
    }
	if (p == head) {
		tmp->next = head;
		head = tmp;
	}
	else{
	tmp->next = q->next;
		q->next = tmp;}//else
	}

}

int  deleting(node* p, int index) {

	node* q = NULL;
	int x = -1;
	if (index<1 || index>count(p))
			return -1;
	if (index == 1) {
		q = head;
		head = head->next;
		x = q->value;
		delete q;
		return x;
	}
	else {
		
		p = head;
			for (int i = 0; i < index - 1; i++) {
				q = p;
				p = p->next;
		}
			if (p) {
				q->next = p->next;
				x = p->value;
				delete p;
				return x;
			}
		}

	}
void removeDublicate(node *p) {  
	node* q = p->next;//q=p;q=q->next;
	while(q != NULL){
	if (p->value != q->value) {
		p =q ;
		q = q->next;
	}
	else{
		p->next = q->next;
	    delete q;
	     q = p->next;}
	}//while
}
void ReverseByArray(node* p) {

	int* A;
	A = new int[count(p)];
	node* q = p; int i=0;
	while (q) {//move element from list to array
		A[i] =q->value ;
		q = q->next;
		i++;
}
	q = p;//لازم ديبق لان بدون هذا السطر الفنكشن لاتعمل
	i--;
	while (q) {//move fromr array to list again and reverse them
		q->value = A[i];
		q = q->next;
		i--;
	}
}

void ReverseByLinks() {

	node* p=head;
		node* q=NULL, * r=NULL;
	while (p!=NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	
	
	}
	head =q ;

}
void reverseByRecursive(node* q, node* p) {

	if (p!=NULL) {
		reverseByRecursive(p, p->next);
		p->next =q ;
	}
	else
	head = q;
 }

 void merging( node *p,node* s) {
 node* last = NULL;
 if(p->value < s->value ){//first node
	 third = last = p;
	 p = p->next; 
	last->next = NULL;
 }
 else {
	 third = last = s;
	 s = s->next;
	 last->next = NULL;
 }
 while (p && s) {//remaining nodes

	 if ((p->value < s->value)){
		 last->next = p;
	     last = p;
	      p = p->next;
		  last->next = NULL;
}
 else{
		 last->next = s;
		 last = s;
		 s = s->next;
		 last->next = NULL;
}
	 
 }//while
 if (p != NULL)//last node
	 last->next = p;
 else
	 last->next = s;
 }

 void concatonated(node* p, node* s) {
	 third = p;
	 while (p->next != NULL) {
		 p = p->next;
	 }
		 p->next = s;
 }

 int isLoop(node* h){ //205

	 node* p=NULL,* q = NULL;
	 p = q = h;//all equal first node
	 do {
		 p = p->next;
		 q = q->next;
		q!=NULL ? q=q->next :NULL ;
			 
		 /*if (q != NULL)
		 q = q->next;
		 else
			 q;*/
	 } while (p && q && p != q);
	 if (p == q)
		 return true;
	 else
		 return false;
	
 }

	int main() {
		int arr[] = {10,20,30,40};
		push(arr,4);
		//int arr2[] = { 5,15,25 };
		//push2(arr2, 3);
		//print(head);
		//cout<<	"THE MAX IS  ="<<max(head)<<endl;
		//cout << "the sum = " << sum(head) << endl;
		//cout << "the key you search ="<<search(head, 7)<<endl;
		//cout << "This search is improving search = " << improving_searching(head, 7) << endl;
		// insert(head, 44, 2);
		//InsertLast(5);
		//InsertLast(10);
		//InseartInSorted(head,9);
		 //print(head);
		// cout<<"The deleted item  "<<deleting(head,2)<<endl;
		//removeDublicate(head);
		//ReverseByArray(head);
		//ReverseByLinks();
		//reverseByRecursive(NULL, head);
		//merging(head,second); 
		//print(third);
		/*cout << "first" << "\n";
		print(head); cout << endl;
		cout << "second" << "\n";
		print(second); cout << endl;
		concatonated(head, second);
		cout << "concotnated ";
		print(third);*/
		node* t1, * t2;// to check if the linked list have loop or not
		t1 = head->next->next->next;
		t2 = head->next;
		t1->next = t2;//means t1->next will be NULL so make it equal t1
		cout<<isLoop(head);
		//print(head);
	
	
	}