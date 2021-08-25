// Double_Ended_Queue_usingArray_AHAD.cpp 
//Written_ by_AHAD ALSELMI
#include <iostream>
using namespace std;
 class dequeue {
    int size;
    int front;
    int rear;
    int* arr;
    dequeue() { size = 10; front = rear = 0; arr = new int[size]; }
    dequeue( int size) { this->size = size; front = rear = 0; arr = new int[this->size]; }
    void InsertByRear( int x);
    void DeleteByRear() ;
    void insertByFront(int x);
    void DeleteByRear();

   int IsFull(){
   
   
   }
    int IsEmpty(){}
 };
//dequeue:: int IsFull() {
//}




int main()
{
    
}

