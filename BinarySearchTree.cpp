#include <iostream>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

//Binary Search Tree
class BST {
private :
	void insert(node*, int);
	bool search(int, node*);
	void inOrder(node*);
	void preOrder(node*);
	void postOrder(node*);
public:
	node* root;

	BST() {
		root = NULL;
	}

	int Max();
	int Min();
	void Insert(int);
	bool Search(int);
	void InOrder();
	void PreOrder();
	void PostOrder();

};

void BST::Insert(int data) {
	if (root == NULL) {
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		insert(root, data);
	}
}

void BST::insert(node* n, int data) {
	if (data < n->data) {
		if (n->left == NULL) {
			n->left = new node;
			n->left->data = data;
			n->left->right = NULL;
			n->left->left = NULL;
		}
		else {
			insert(n->left, data);
		}
	}
	else if (data >= n->data) {
		if (n->right == NULL) {
			n->right = new node;
			n->right->data = data;
			n->right->right = NULL;
			n->right->left = NULL;
		}
		else {
			insert(n->right, data);
		}
	}
}

void BST::InOrder() {
	if (root == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		inOrder(root);
	}
}

void BST::inOrder(node* n) {
	if (n != NULL) {
		inOrder(n->left);
		cout << n->data << " ";
		inOrder(n->right);
	}
}

bool BST::Search(int data) {
	if (root == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		return search(data, root);
	}
}

int myCount = 0;

bool BST::search(int data, node* n) {
	myCount++;



	bool answer = false;

	if (n == NULL) {
		return false;
	}

	cout << n->data << endl;


	if (data == n->data) {
		return true;
	}
	else if (data < n->data) {
		answer = search(data, n->left);
	}
	else {
		answer = search(data, n->right);
	}

	return answer;
}

void main() {
	BST bst;
	bst.Insert(24);
	bst.Insert(15);
	bst.Insert(13);
	bst.Insert(21);
	bst.Insert(35);
	bst.Insert(30);
	bst.Insert(55);

	for (size_t i = 0; i < 1000; i++){
		int number = 0;
		bst.Insert(number);
	}

	//bst.InOrder();

	cout << boolalpha << bst.Search(501) << endl;
	cout << "We found at " << myCount << " times" << endl;
}