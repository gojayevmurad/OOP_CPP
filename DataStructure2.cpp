#include <iostream>

using namespace std;

//Double linked list

struct node {
	string data;
	node* prev;
	node* next;
};

/// <summary>
/// Double Linked List
/// </summary>
class DLL {
	node* front;
	node* end;
public :

	DLL() {
		front = NULL;
		end = NULL;
	}

	DLL(node* front, node* end) {
		this->front = front;
		this->end = end;
	}

	void ForwardTraverse();
	void BackwardTraverse();
	void AddFront(string);
	void AddEnd(string);
	void AddAfter(node*, string);
	void DeleteNode(node*);

	~DLL(){
		delete front;
		delete end;
	}

};

void DLL::ForwardTraverse() {
	node* temp = front;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}cout << endl;
}


void DLL::BackwardTraverse() {
	node* temp = end;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
	}cout << endl;
}

void DLL::AddFront(string data) {
	node* newNode = new node;
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = front;

	if (front==NULL){
		end = newNode;
	}
	else {
		front->prev = newNode;
	}

	front = newNode;
}

void DLL::DeleteNode(node* n) {
	if (n->prev == NULL) {
		front = n->next;
		front->prev = NULL;
	}
	else if (n->next == NULL) {
		end = n->prev;
		end->next == NULL;
	}
	else {
		n->next = n->prev;
		n->prev = n->next;
	}
	delete n;
	n == NULL;
}


void  main() {
	node* first = new node;
	node* second = new node;
	node* third = new node;

	first->data = "Apple";
	first->prev = NULL;
	first->next = second;

	second->data = "Tissot";
	second->prev = first;
	second->next = third;

	third->data = "Rolex";
	third->prev = second;
	third->next = NULL;

	DLL mylist(first, third);
	mylist.AddFront("Bulgari");
	mylist.ForwardTraverse();
	mylist.DeleteNode(first);
	mylist.BackwardTraverse();
}