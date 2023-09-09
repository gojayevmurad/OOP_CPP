#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};


class LinkedList {
	Node* head;
public:
	LinkedList(Node* head) {
		this->head = head;
	}

	void PushFirst(int data) {
		Node* node = new Node;
		node->data = data;
		node->next = head;
		head = node;
	}

	void PushLast(int data) {
		Node* node = new Node;
		node->data = data;

		Node* currentNode = head;

		while (currentNode->next != NULL){
			currentNode = currentNode->next;
		}

		node->next = NULL;
		currentNode->next = node;
	}

	void PrintList() {
		Node* n = head;
		while (n!=NULL){
			cout << n->data << endl;
			n = n->next;
		}
	}

	void InserAfter(Node* node, int newData) {
		if (node == NULL) {
			cout << "Empty" << endl;
			return;
		}

		Node* newNode = new Node;
		newNode->data = newData;

		newNode->next = node->next;
		node->next = newNode;

	}

	void DeleteFirst() {
		head = head->next;
	}

	void DeleteLast() {

		Node* current = head->next;
		int index;
		for (size_t i = 0; current->next != NULL ; i++){
			current = current->next;
			index = i - 1;
		}
		
		current = head->next;
		for (size_t i = 0; i <= index; i++){
			current = current->next;
		}
		current->next = NULL;
	}

	void deleteAfter(Node* node) {
		Node* temp = node->next;
		node->next = node->next->next;
		delete temp;
	}

	void InsetByIndex(const  int& index, const int& data) {

		Node* newNode = new Node;
		newNode->data = data;

		Node* current = head;

		for (size_t i = 0; i < index; i++){
			current = current->next;
		}

		Node* currentNext = current->next;

		newNode->next = current;
		current->next = currentNext;

	}

	void DeleteByIndex(const int& index) {
		Node* current = head;




		for (size_t i = 1; i < index; i++){
			current = current->next;
		}

		cout << current->data << " asdf" << endl;

		current->next = current->next->next;
	}

};



void main() {

	Node* head = new Node;
	Node* second = new Node;
	Node* third = new Node;

	head->data = 100;
	head->next = second;

	second->data = 200;
	second->next = third;

	third->data = 300;
	third->next = NULL;




	LinkedList ll(head);

	ll.PushFirst(-100);
	ll.PushLast(-100);
	ll.InserAfter(second, 111);
	ll.DeleteFirst();
	ll.DeleteLast();
	ll.deleteAfter(second);
	//ll.InsetByIndex(1, 101);
	ll.DeleteByIndex(1);
	ll.PrintList();

	// DeleteByIndex(4)
}