#include <iostream>
#include <assert.h>

using namespace std;

// Friend Method

class Rectangle {
	int length;
	int breadth;
public:
	Rectangle(int length, int breadth) :length(length), breadth(breadth) {};

	friend void CalculateArea(Rectangle r);

};

void CalculateArea(Rectangle r) { // Friend Method
	cout << r.length * r.breadth << endl;
}

class Car {
	int year;
	char* model;
	char* vendor;
public:

	Car(const char* model, const char* vendor, const int& year) {
		SetYear(year);
		SetModel(model);
		SetVendor(vendor);
	}

	int GetYear()const {
		return year;
	}

	const char* GetModel()const {
		return model;
	}

	const char* GetVendor()const {
		return vendor;
	}

	void SetYear(const int& year) {
		this->year = year;
	}

	void SetModel(const char* model) {
		int l = strlen(model);
		this->model = new char[l + 1] {};
		strcpy_s(this->model, l + 1, model);
	}

	void SetVendor(const char* vendor) {
		int l = strlen(vendor);
		this->vendor = new char[l + 1] {};
		strcpy_s(this->vendor, l + 1, vendor);
	}

	void operator ()() {
		if (model == nullptr || vendor == nullptr) return;

		cout << "Car Info" << endl;
		cout << "Model : " << model << endl;
		cout << "Vendor :" << vendor << endl;
		cout << "Year : " << year << endl;
	}

	operator bool() {
		if (year >= 2015) return true;
		return false;
	}

	operator int() {
		return year;
	}

	operator char* () {
		return vendor;
	}

	~Car(){
		delete[] vendor;
		delete[] model;
	}



};

class A {
	int* data;
public:
	A() = default;
	static int count;

	A(int* data) :data(data) {
		++count;
		cout << "Object Created" << endl;
	}

	void Show()const {
		cout << "Data : " << *data << endl;
	}

	void* operator new(size_t size) {
		assert(size >= 8 && "Size should be 64 bit or greater");
		cout << "New Operator Overloaded" << endl;
		return malloc(size);
	}

	void* operator new[](size_t size) {
		cout << "New[] Operator Overloaded" << endl;
		int sizeObject = sizeof(A);
		int count = size / sizeObject;
		assert(count < 5 && "You can create maximum 5 object");
		return malloc(size);
	}

	void operator delete(void * addressOfData){
		cout << "Delete Operator Overloaded" << endl;
		free(addressOfData);
	}

	void operator delete[](void* addressOfData) {
		cout << "Delete[] Operator Overloaded" << endl;
		free(addressOfData);
	}
};

int A::count = 0;

class Player {
	char* firstName;
	char* lastName;
	double score;
	int age;
public:

	Player() :firstName(NULL), lastName(NULL), score(NULL), age(NULL) {}

	Player(const char* firstName, const char* lastName, const double& score, const int& age) {
		SetFirstName(firstName);
		SetLastName(lastName);
		SetScore(score);
		SetAge(age);
	}

	const char* GetFirstName()const {
		return firstName;
	}

	const char* GetLastName()const {
		return lastName;
	}

	double GetScore()const {
		return score;
	}

	int GetAge()const {
		return age;
	}

	void SetFirstName(const char* firstName) {
		int l = strlen(firstName);
		this->firstName = new char[l + 1] {};
		strcpy_s(this->firstName, l + 1, firstName);
	}

	void SetLastName(const char* lastName) {
		int l = strlen(lastName);
		this->lastName = new char[l + 1] {};
		strcpy_s(this->lastName, l + 1, lastName);
	}

	void SetScore(const double &score) {
		this->score = score;
	}

	void SetAge(const int& age) {
		this->age = age;
	}

	friend ostream& operator <<(ostream& out, const Player& player);
	friend istream& operator >> (istream& in, const Player& player);

	~Player() {
		delete[] firstName;
		delete[] lastName;
	}
};

ostream& operator <<(ostream& out, const Player& player) {
	out << "Player Info " << endl;
	out << "Firstname : " << player.firstName << endl;
	out << "Lastname : " << player.lastName << endl;
	out << "Score :" << player.score << endl;
	out << "Age : " << player.age << endl;
	return out;
}

istream& operator >> (istream& in, Player& player) {
	cout << "Enter firstname : " << endl;
	char* buffer = new char[100] {};
	cin.getline(buffer, 100);
	player.SetFirstName(buffer);
	delete[]buffer;

	buffer = new char[100] {};
	cout << "Enter lastname :" << endl;
	cin.getline(buffer, 100);
	player.SetLastName(buffer);
	delete[]buffer;
	
	cout << "Enter score : " << endl;
	double score = 0;
	cin >> score;
	player.SetScore(score);

	cout << "Enter age : " << endl;
	int age = 0;
	cin >> age;
	player.SetAge(age);

	return in;
}


void main() {

#if 0
		Car c("la ferrari", "ferrari", 2020);
		c();

		if (c) {
			cout << "New car " << endl;
		}
		else {
			cout << "Old car" << endl;
		}

		auto data = (char*)c;
		cout << data << endl;
#endif // 0


#if 0
	A* obj = new A(new int(100));
	obj->Show();
	delete obj;
#endif // 0

#if 0
	A* objects = new A[4]{};
	delete[] objects;
#endif // 0


	Player p;
	cin >> p;
	system("cls");
	cout << p << endl;
}