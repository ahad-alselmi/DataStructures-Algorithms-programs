#include<iostream>
#include<vector>
using namespace std;
struct Edge;
struct Node {
	Node(int ID, int cost) { id = ID; Totalcost = cost; }
	int id;
	int Totalcost;
	vector<Edge *> edges;
};
struct Edge {
	Edge(Node* to, Node* from, int Cost) {
		To = to; 
		From = from; 
		cost = Cost; }
	Node* To;
	Node* From;
	int cost;	  
};

void solvegraph(vector<Node*> AllNode,Node * start){

	for (int i = 0; i < AllNode.size(); i++) {
		Node* n = AllNode[i];
		for (int j = 0; j < n->edges.size(); j++) {
			Edge* e = n->edges[j];
			Node* to;
			if (e->To == n)
				to = e->From;
			else
				to = e->To;
			int total = n->Totalcost + e->cost;
			if (to->Totalcost > total)
				to->Totalcost = total;




}

	}
}
int main() {
	Node n0(0,0);
	Node n1(1, INT_MAX);
	Node n2(2, INT_MAX);
	Node n3(3, INT_MAX);
	Node n4(4, INT_MAX);
	Node n5(5, INT_MAX);
	/*my way to range edges
	Edge e1(&n0, &n1, 10);
	Edge e2(&n0, &n5, 1);
	Edge e3(&n1, &n2, 5);
	Edge e4(&n1, &n3, 9);
	Edge e5(&n1, &n5,2);
	Edge e6(&n2, &n3, 10);
	Edge e7(&n3, &n4, 15);
	Edge e8(&n4, &n5, 9);
	Edge e9(&n5, &n3, 16);*/

	Edge e1(&n0, &n1, 10);
	Edge e2(&n0, &n5, 1);
	Edge e3(&n1, &n5, 2);
	Edge e4(&n1, &n2, 5);
	Edge e5(&n1, &n3, 9);
	Edge e6(&n5, &n3, 16);
	Edge e7(&n5, &n4, 9);
	Edge e8(&n2, &n3, 10);
	Edge e9(&n3, &n4, 15);

	n0.edges.push_back(&e1);
	n0.edges.push_back(&e2);

	n1.edges.push_back(&e1);
	n1.edges.push_back(&e3);
	n1.edges.push_back(&e4);
	n1.edges.push_back(&e5);

	n2.edges.push_back(&e4);
	n2.edges.push_back(&e8);

	n3.edges.push_back(&e5);
	n3.edges.push_back(&e6);
	n3.edges.push_back(&e8);
	n3.edges.push_back(&e9);

	n4.edges.push_back(&e7);
	n4.edges.push_back(&e9);

	n5.edges.push_back(&e2);
	n5.edges.push_back(&e3);
	n5.edges.push_back(&e6);
	n5.edges.push_back(&e7);

	vector<Node*> AllNode;
	AllNode.push_back(&n0);
	AllNode.push_back(&n1);
	AllNode.push_back(&n2);
	AllNode.push_back(&n3);
	AllNode.push_back(&n4);
	AllNode.push_back(&n5);

	solvegraph(AllNode, &n1);
	cout << n3.Totalcost<<endl;
}