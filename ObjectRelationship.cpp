#include <iostream>

using namespace std;
// Nested or Embedded

class LinkedList {
public:

	void AddData(int data) {
		Node node;
		node.data = 100;
	}

private:



	class Node {
		public: 
		int data;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;

};


class Product {
	string name;

public:

	struct ProductType {
		enum Types{
			FANCY, AWESOME , USERFULL	
		};
	};

	struct ProductBoxType {
		enum Types{
			BOX, BAG, CRATE
		};
	};

	Product(string name, ProductType::Types type, ProductBoxType::Types boxType) {
	}

};

class Dictionary {

private:

	struct Word{
		string key;
		string value;
	};

	Word** words;
	int count = 0;


public:

	string& operator [] (string key) {
		for (size_t i = 0; i < count; i++){
			if (words[i]->key == key) {
				return words[i]->value;
			}
		}
		Word* newWord = new Word;
		newWord->key = key;
		Add(newWord);
		return newWord->value;
	}

	void Add(Word* word) {
		auto newwords = new Word * [count + 1] {};
		for (size_t i = 0; i < count; i++){
			newwords[i] = words[i];
		}
		newwords[count] = word;
		++count;
		words = newwords;
		newwords = nullptr;
	}

};

void main() {

	Product p("Apple", Product::ProductType::AWESOME, Product::ProductBoxType::BOX);

	Dictionary d;

	d["Apple"] = "Alma";
	d["Mango"] = "Manqo";
	d["Crate"] = "Sandiq";
	d["PineApple"] = "Ananas";
	d["Orange"] = "Portagal";

	cout << d["Apple"] << endl;
	cout << d["Mango"] << endl;
	cout << d["Crate"] << endl;
	cout << d["PineApple"] << endl;
	cout << d["Orange"] << endl;

}