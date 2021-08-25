
#include<iostream>
using namespace std;

struct node {
	int value;
	node* next;
};

class linkedlist {

	node* head;
	node* tail;
public:
	linkedlist() {
	
		head = NULL;
	    tail = NULL;
	}
	void addNode(int v) {
	
		node* temp = new node;
		temp->value = v;
		temp->next = NULL;
	 if (head==NULL){
		 head = temp;
		 tail = temp;
	 }
	 else {
		 tail->next = temp;
		 tail = tail->next;
	 }
}//add

	/*void print() {
	//node* temp ;
	//temp = head;

	//while (head) {
			
			//cout << head->value<<endl;
			//head = head->next;

	//}

		node* tmp;
		tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->value << endl;
			tmp = tmp->next;
		}
		}//print*/
	node* getHead() {
		return head;}
	
	
	void front(int n)
	{
		node* tmp = new node;
		tmp->value = n;
		tmp->next = head;
		head = tmp;
	}

	void after(node *a,int value)
	{
		
		node* p = new node;
		p->value = value;
		p->next = a->next;
		a->next = p;
		a = p;
	}
	
     static void display(node* h) {
        if (h == NULL)
            cout << "head null";
        else{
            cout << h->value<<endl;
             display( h->next);
        }
     }

};


int main() {
	linkedlist list;
	
	//a->value = 8;
	list.addNode(1); 
	 list.addNode(2);
	///list.after(list.getHead()->next->next->next,9);
	 linkedlist::display(list.getHead());
	 

}

/*#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class linked_list
{
private:
    node* head, * tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead()
    {
        return head;
    }

    static void display(node* head)
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
    }

    static void concatenate(node* a, node* b)
    {
        if (a != NULL && b != NULL)
        {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next, b);
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }

    void front(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = head;
        head = tmp;
    }

    void after(node* a, int value)
    {
        node* p = new node;
        p->data = value;
        p->next = a->next;
        a->next = p;
    }

    void del(node* before_del)
    {
        node* temp;
        temp = before_del->next;
        before_del->next = temp->next;
        delete temp;
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.front(3);
    a.add_node(5);
    a.add_node(15);
    a.after(a.gethead()->next->next->next, 10);
    a.del(a.gethead()->next);
    linked_list::display(a.gethead());
    return 0;
}
*/


