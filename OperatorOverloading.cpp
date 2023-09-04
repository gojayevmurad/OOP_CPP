#include <iostream>

using namespace std;

class Student {
	int age;
	double score;
public: 
	Student(int age, double score) {
		this->age = age;
		this->score = score;
	}
};

class INT {
	int num = 0;
public:
	INT() :num(0) {}

	explicit INT(int num) {
		SetNum(num);
	}

	int GetNum()const {
		return this->num;
	}

	void SetNum(const int& num) {
		this->num = num;
	}

#pragma region Operator Overloading

	// prefix increment
	INT& operator ++ () {
		this->num++;
		return *this;
	}

	 // postfix increment
	INT operator ++(int) {
		INT temp = *this;
		this->num++;
		return temp;
	}

	// prefix decrement
	INT& operator -- () {
		this->num--;
		return *this;
	}

	// postfix decrement
	INT operator --(int) {
		INT temp = *this;
		this->num--;
		return temp;
	}

	INT& operator += (const INT& other) {
		this->num += other.num;
		return *this;
	}

	bool operator > (const INT& other) {
		return this->num > other.num;
	}

	bool operator < (const INT& other) {
		return this->num < other.num;
	}

	bool operator == (const INT& other) {
		return this->num == other.num;
	}

	INT& operator * (const INT& other) {
		this->num *= other.num;
		return *this;
	}

#pragma endregion


};

#include <assert.h>

class Vector {
	int* data;
	size_t size = 0;
	void SetSize(const size_t& size) {
		this->size = size;
	}
public:
	Vector() :data(nullptr), size(0) {}

	Vector(int* data, const size_t& size) {
		SetSize(size);
		SetData(data);
	}

	const int* GetData()const {
		return data;
	}

	int GetSize()const {
		return size;
	}

	void SetData(int* data) {
		this->data = new int[size] {};
		for (size_t i = 0; i < size; i++){
			this->data[i] = data[i];
		}
	}

	void Print()const {
		for (size_t i = 0; i < size; i++) {
			cout << data[i] << " ";
		}cout << endl;
	}

	void PushBack(const int newElement) {
		auto temp = new int[size + 1] {};

		for (size_t i = 0; i < size; i++){
			temp[i] = data[i];
		}
		temp[size] = newElement;

		if (data != nullptr) {
			delete[] data;
		}
		data = temp;
		temp = nullptr;
		++size;
	}

	int& operator[](int index) {
		assert(index >= 0 && index < size && "Index was out of range");
		return data[index];
	}

	int& operator()(int index) {
		assert(index >= 0 && index < size && "Index was out of range");
		return data[index];
	}

	bool operator == (const Vector& other) {
		return this->size == other.size;
	}

	void operator()() {
		Print();
	}

	~Vector(){
		delete[] data;
	}

};

void main() {

	/*
		Student s1(23, 98);
		Student s1(25, 88);

		if (s1 > s2) {
		 // error
		}
	*/

	/*
		INT num1(300);
		INT num2(200);

		num1* num2;
		cout << num1.GetNum() << endl;

		if (num1 == num2) {
			cout << "equal" << endl;
		}
		else {
			cout << "not equal" << endl;
		}

		cout << (num1 > num2) << endl;
	*/

	/*
		Vector v(new int [5] {1, 2, 3, 4, 5}, 5);
		v.Print();
		v.PushBack(155);
		v.Print();
		v();
		cout << v(2) << endl;
	*/
	Vector v(new int [5] {1, 2, 3, 4, 5}, 5);
	v();
	Vector v2(new int [7] {1, 2, 3, 4, 5, 66, 77}, 7);
	v2();

	if (v == v2) {
		cout << "Equal counts item exist in vectors" << endl;
	}
	else {
		cout << "different vectors" << endl;
	}
}