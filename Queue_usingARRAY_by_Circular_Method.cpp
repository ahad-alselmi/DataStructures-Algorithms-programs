// Queue_usingARRAY_by_Circular_Method.cpp 
//AHAD_ALSELMI

#include <iostream>
using namespace std;

struct queue {
    int size;
    int front;
    int rear;
    int* arr;
} *q=NULL;

void create(queue* q,int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->arr = new int[q->size];
}

void enqueue(queue* q, int x) {
    //check if it is full
    if ((q->rear + 1) % q->size == q->front)//the next of rear =0 =front
        cout << "The Queue is Full";
    else {//add an element by moving rear to the next position
        q->rear = (q->rear + 1) % q->size;
         q->arr[q->rear]=x ;
    }
}
void dequeue(queue* q ){
    int x = -1;
    //check if it is empty
    if ((q->rear ) == q->front)//the next of rear =0 =front
        cout << "The Queue is empty";
    else {//add an element by moving rear to the next position
        q->front = (q->front + 1)% q->size;
        x= q->arr[q->front] ;
    }
}
void display(queue q) {

     int i = q.front + 1;
     do {
         cout << q.arr[i]<<endl;
         i = (i + 1) % q.size;
     } while (i !=(q.rear + 1)% q.size);

     cout << endl;
}
int main()
{
    queue q;
   // int arr[] = { 5,6,7,8,9,10 };
    create(&q, 6);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    display(q);

}

