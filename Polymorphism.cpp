#include <iostream>

using namespace std;

class Base {
protected: 
	int value;
public:
	Base(int v) {
		value = v;
	}

	int GetValue()const {
		return value;
	}

	virtual string GetName() {
		return "I am base";
	}

};

class Derivered :public Base {
public:
	Derivered(int value) 
		:Base(value) {
	}

	

	int GetDoubleValue()const {
		return value * 2;
	}

	string GetName() override {
		return "I am derivered";
	}



};


class Animal {
protected :
	string name;
	Animal(string name) {
		this->name = name;
	}

public:

	string GetName()const {
		return name;
	}

	virtual void Speak() {
		cout << "??????????????????????" << endl;
	}

};

class Cat :public Animal {
public :
	Cat(string name) :Animal(name) {}

	void Speak() {
		cout << "memeameameamea :))" << endl;
	}

};

class Dog :public Animal {
public :
	Dog(string name) :Animal(name) {}

	void Speak() {
		cout << "How how how how , i can bark like real dog :)" << endl;
	}

	void BarkBark() {
		cout << "i can just bark" << endl;
	}

};

class Elephant :public Animal {
public : 
	Elephant(string name) :Animal(name) {}

	void Speak() {
		cout << "Bruuuuuwww bruuuuuw, i'm elephant :) " << endl;
	}

};

void CallAnimal(Animal * animal) {
	animal->Speak();
}

class Tiger :public Cat {
public :
	Tiger(string name) :Cat(name) {}

	void Speak()final override {
		cout << "I'm tiger" << endl;
	}

};

class Liger :public Tiger {
public:
	Liger(string name) :Tiger(name) {}

	//void Speak() override { //error  final override
	//	cout << "I'm liger" << endl;
	//}

};

class Human {
protected:
	string name;
	int age;

	Human(string name, int age) :name(name), age(age) {

	}

public :
	virtual void Run() {
		cout << "My speed is not so good" << endl;
	}

	virtual ~Human(){
		cout << "Human destructor" << endl;
	}

};


class SimpleHuman :public Human {
public:
	SimpleHuman(string name, int age) :Human(name, age) {

	}


	~SimpleHuman(){
		cout << "Simple destructor" << endl;
	}

};

class UsainBolt : public Human {
public :
	UsainBolt(string name, int age) :Human(name, age) {

	}

	void Run() {
		cout << "My speed is  awesome " << endl;
	}

	~UsainBolt(){
		cout << "Destructor Usain Bolt" << endl;
	}

};



void main() {

	/*
		Base b(10);
		cout << b.GetName() << endl;

		Derivered d(11);
		cout << d.GetName() << endl;
	*/

	//Base* base = new Derivered(10);
	//cout << base->GetName() << endl;


	/*
		Base b(10);

		Derivered d(11);

		Base& obj = d;

		cout << obj.GetName() << endl;
	*/

	/*
		Cat cat("Tom");
		Dog dog("Dog:)");
		Elephant elephant("Fred");
		Tiger tiger("Fred");

		Animal* animals[4]{ &cat, &dog, &elephant, &tiger };

		for (size_t i = 0; i < 4; i++){
			animals[i]->Speak();
		}
	*/

	//Human* h1 = new SimpleHuman("Rafiq", 34);
	//h1->Run();

	Human* h2 = new UsainBolt("Usain", 34);
	h2->Run();

	delete h2;

}