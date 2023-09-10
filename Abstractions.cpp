#include <iostream>

using namespace std;

#pragma region Abstraction

class Figure {
protected:
	double area;
public:
	virtual void WhatIsMyShape() = 0; // pure virtual
	virtual void CalculateArea() = 0; // pure virtual

	double GetArea() {
		return area;
	}

};

class Rectangle : public Figure {
	double length;
	double width;
public:
	Rectangle(double length, double width) {
		this->length = length;
		this->width = width;
	}

	virtual void WhatIsMyShape()override {
		cout << "My shape is rectangular" << endl;
	}

	virtual void CalculateArea()override {
		area = width * length;
	}

	void Unknown() {
		cout << "Unkown method" << endl;
	}

};

class Circle :public Figure {
	double radius;
	const double pi = 3.141516;
public:
	Circle(double radius) :radius(radius) {};

	// Inherited via Figure
	void WhatIsMyShape() override{
		cout << "My shape is circular" << endl;
	}
	void CalculateArea() override{
		area = pi * radius * radius;
	}
};

class Square :public Rectangle {
	double side;
public:
	Square(double side) :Rectangle(side, side) {

	}

	virtual void WhatIsMyShape() override {
		cout << "My shape si square" << endl;
	}


};

#pragma endregion

#pragma region Example 2

class Animal {
protected:
	string name;
public:
	Animal(const string& name) :name(name) {}

	virtual void Speak() = 0 {
		cout << "i cry like all animal" << endl;
	}

};

class Dragon :public Animal {
public : 
	Dragon(const string& name) :Animal(name) {}
	


	// Inherited via Animal
	void Speak() override{
		Animal::Speak();
	}

};

class Tiger :public Animal {
public :
	Tiger(const string& name) :Animal(name) {}



};


#pragma endregion


#pragma region Example 3
class AbstractDatabase {
public :

	virtual string GetById(int id) = 0;
	virtual void DeleteById(int id) = 0;
	virtual void Add(int id, string data) = 0;
	virtual void Update(int id, string data) = 0;

};

class MsSql :public AbstractDatabase {
	// Inherited via AbstractDatabase
	string GetById(int id) override{
		cout << "Get from MsSql db" << endl;

		return string();
	}
	void DeleteById(int id) override{
		cout << "Delete from MsSql db" << endl;
	}
	void Add(int id, string data) override{
		cout << "Add to MsSql db" << endl;
	}
	void Update(int id, string data) override{
		cout << "Update in MsSql db" << endl;
	}
};

class Oracle :public AbstractDatabase {
	// Inherited via AbstractDatabase
	string GetById(int id) override {
		cout << "Get from ORACLE db" << endl;

		return string();
	}
	void DeleteById(int id) override {
		cout << "Delete from ORACLE db" << endl;
	}
	void Add(int id, string data) override {
		cout << "Add to	 ORACLE db" << endl;
	}
	void Update(int id, string data) override {
		cout << "Update in ORACLE db" << endl;
	}
};

class Website {
	string url;
	AbstractDatabase* database;
public: 
	Website(AbstractDatabase * database){
		this->database = database;
	}

	void Run() {
		database->Add(10, "Hello");
		database->Update(1, "Yes");
		database->GetById(1);
		database->DeleteById(2);
	}

};

#pragma endregion


#pragma region Example 4

class Musician {
protected : 
	string name;
public:
	void Perform() {
		cout << "Musician perform" << endl;
	}
	virtual ~Musician() = 0 {

	}
};



#pragma endregion


void main() {

#if 0
	Rectangle rect(10, 20);
	rect.CalculateArea();
	rect.WhatIsMyShape();

	Circle circle(15);
	circle.WhatIsMyShape();
	circle.CalculateArea();
	cout << "Area : " << circle.GetArea() << endl;
#endif // 0

#if 0
	Figure** figures = new Figure * [3] {
		new Rectangle(10, 20),
			new Square(15),
			new Circle(12)
	};

	for (size_t i = 0; i < 3; i++){
		auto rect = dynamic_cast<Rectangle*>(figures[i]);
		if (rect != nullptr) {
			rect->Unknown();
		}
		figures[i]->WhatIsMyShape();
	}
#endif // 0

#if 0
	Website mysite(new Oracle());
	mysite.Run();
#endif // 0

	Musician m;


}