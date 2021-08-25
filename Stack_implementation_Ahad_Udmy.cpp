#include <iostream>
using namespace std;
//Implementaion of Stack with array
/*struct stack {
	int size;
	int top;
	int* s;
};
  void create(stack * st){//call by refrence use -> operator
 
	 cout << "Enter the size:  ";
	 cin >>st->size;
	 st->top = -1;
	 st->s = new int[st->size];
       }
 void display(stack st) {//call by value use . operator
	for (int i = st.top; i >= 0; i--)
		 //cout << st.s[st.top--];
		 cout << st.s[i]<<'\n';
	 
 
  }
  void push(stack* st, int x) {
	  //x = -1;
	 if (st->top == st->size-1)// if the top of stack = the size of stack//??
		 cout << "OverFlow" << endl;
	 else
	 {
		 st->top++;
		st->s[st->top]  =x ;//??
		 
	 }
}
	int pop(stack * st) {
		 int x=-1;
		 if (st->top == -1)
			 cout << "over flow";
		 else {
			
			 x = st->s[st->top]; //frist take the value 
			 st->top--;//then decrement
		 }
		 return x;
	}


 
  int main() {
	  stack st;
	  create(&st);//sent refrence
	  push(&st,10);
	  push(&st,8);
	  push(&st,7);

	  display(st);
	  cout << "this delete " << pop(&st);//last go out first
 }*/
struct stack {
	int size;
	int top;
 	int* s;};
void create(stack* st) {
	cout << "Enter size ";
	cin >> st->size;
	st->top = -1;
	st->s = new int[st->size];
}
void display(stack st) {//for calling by value use . operator
	for (int i = st.top; i >= 0; i--)
		cout << st.s[i]<<'\n';

}

void push(stack* st, int x) {//for calling by refrence use -> operator

	//check if stack is full
	if (st->top == st->size - 1)
		cout << "over flow";
	else {
		st->top++;
		st->s[st->top] = x;
	}
}

int pop(stack *st) {
	int x = -1;
	//check if stack is empty if it is empty so we get under flow
	if (st->top == - 1)
		cout << " underflow";
	else {
		x=st->s[st->top] ;
		st->top--;
	}
	return x;

}
void stacktop(stack st) {
	if (st.top = st.size - 1)
		cout << "This is top of stack: " << st.top;
	
}
int peek(stack st, int pos) {//search for an element
	int x = -1;
	if (st.top - pos + 1 < 0 )
		cout << "the position not correct"<<endl;
	else 
	x=st.s[st.top-pos+1];
	
	return x;

}

int isFull(stack st) {
	return st.top ==st.size-1;//if it is true it will return 1 if it is false it will return 0
 }
int isEmpty(stack st) {
	if (st.top == -1)
		return 1;//mean it is empty
	else
		return 0;

 }

int main() {
	stack st;
	create(&st);
	push(&st, 10);
	push(&st, 20);
	push(&st, 30);//position 2=top//first go out of stack

	/*display(st);
	cout << "This Element is Delete from stak: " << pop(&st) << endl;
	display(st);
	stacktop(st); cout << endl;*/

	cout << "This is the element you search" << peek(st,1) << endl;
	cout<<isFull(st);



}



  
  
 

		 

 




