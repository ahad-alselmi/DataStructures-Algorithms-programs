// ArrayList-AHAD.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include<iostream>
using namespace std;
template < class T>
class arraylist {
    T  *internalarray;
    int size = 0;
    int capacity;
void Expandarray(){//minut:49 in 16 session 
if (capacity == size) {
            T  *temp = new T[capacity + 10];

            for (int i = 0; i < size; i++) {
                temp[i] = internalarray[i];
             }//for
            delete[] internalarray;
            internalarray = temp;
            capacity += 10;

        }//if
}
public:
    arraylist() {
         internalarray= new T[10];
         size = 0;
        capacity=10; }
    arraylist(int size) {
        internalarray = new T[size];
        this->size = 0;
        capacity =size;
    }
    ~arraylist() {
        if (internalarray)
            delete[] internalarray;
        internalarray = NULL;
    }
    void add(T item) {
        Expandarray();
        internalarray[size++] = item;
        
      }
   
    T& operator [](int index) {
        return internalarray[index];
    }

    int getsize() {
        return size;
    }           
    T Delete(int index) {
        if (index < 0 || index >=size)
             throw exception("invalid index");
        T item = internalarray[index];
        for (int i = index+1; i < size; i++) {
            internalarray[i - 1] = internalarray[i];
        }
        size--;
        return item;
        
    }

    void insert(int index, T item) {
        if (index <0 || index >size)//we put size because capacity depands on the size
            throw exception("invalid index");
        //if (capacity == size) in htis case we should expand the array
             Expandarray();
        
       
        for (int i = index + 1; i < capacity; i++) {
            internalarray[i + 1] = internalarray[i];
          }
        //size++;
         internalarray[index]=item ;
    } 
};
int main() {

    arraylist <int> list(10);
    for (int i = 0; i < 100; i++) {
        list.add(rand() % 100);
        
    }
    
    for (int i = 0; i < 100; i++) {
        cout << list[i]<<endl;
    }
    //cout <<"the size is "<< list.getsize()<<endl;
   // cout << list.Delete(3);
list.insert(0, 21);
 }
