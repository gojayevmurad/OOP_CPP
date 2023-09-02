#include <iostream>
#include <assert.h>

using namespace std;

class Student {
	char* name = new char[10] {"no name"};
	char* surname = new char[20] {"no surname"};
	int age = 0;
public:

	Student() = default;

	Student(const char* name) {
		SetName(name);
		cout << "1 param1" << endl;
	}

	Student(const char* name, const char* surname)
		:Student(name)
	{
		SetSurname(surname);
		cout << "2 param" << endl;

	}

	Student(const char* name, const char* surname, const int& age)
		:Student(name, surname) // Constructor Delegate
	{
		SetAge(age);
		cout << "3 param" << endl;
	}

	Student(const Student& other)
		:Student(other.name, other.surname, other.age) {}

	void SetName(const char* name) {
		if (name != nullptr) {
			int l = strlen(name);
			this->name = new char[l + 1] {};
			strcpy_s(this->name, l + 1, name);
		}
	}

	void SetSurname(const char* surname) {	
		if (surname != nullptr) {
			int l = strlen(surname);
			this->surname = new char[l + 1] {};
			strcpy_s(this->surname, l + 1, surname);
		}
	}

	void SetAge(const int& age) {
		if (age > 0) {
			this->age = age;
		}
	}

	const char* GetName()const {
		return name;
	}

	const char* GetSurname()const {
		return surname;
	}

	int GetAge()const {
		return age;
	}

	void Show()const {
		cout << "Stud Info" << endl;
		cout << "Name : " << GetName() << endl;
		cout << "Surname :" << GetSurname() << endl;
		cout << "Age :" << GetAge() << endl;
	}

	~Student(){
		delete[]name;
		delete[]surname;
	}
};

class MyString {
	char* text;
	size_t length = 0;

	void SetLength(int len) {
		this->length = len;
	}

	bool IsReverse(bool reverse, char& a, char& b) {
		if (reverse) return a < b;
		return a >= b;
	}

	void Swap(char& a, char& b) {
		char temp = a;
		a = b;
		b = temp;
	}

public:

	MyString() :text(NULL), length(NULL) {}

	MyString(const char* text) {
		SetText(text);
	}

	MyString(const MyString& other) {
		SetText(other.text);
	}

	MyString& operator = (const MyString& other) {
		SetText(other.text);
		return *this;
	}

	void SetText(const char* text) {
		assert(text != nullptr && "Text should be different than null");
		int l = strlen(text);
		this->text = new char[l + 1] {};
		strcpy_s(this->text, l + 1, text);
		SetLength(l);
	}

	size_t GetLength() const {
		return length;
	}

	const char* GetText() const {
		return (text != nullptr ? text : "");
	}

	int Find(const char& letter) {
		int flag = -1;

		for (size_t i = 0; i < GetLength()-1; i++){
			if (text[i] == letter) {
				flag = i;
				break;
			}
		}

		return flag;
	}

	void Append(const char* newText) {
		int newLen = strlen(newText);
		if (newText != nullptr && newLen > 0) {
			size_t new_length = GetLength() + newLen + 1;
			char* new_data = new char[new_length + 1] {};

			strcat_s(new_data, GetLength() + 1, text);
			strcat_s(new_data, new_length, newText);

			delete[]this->text;
			this->text = new_data;
			SetLength(strlen(new_data));

			new_data = nullptr;
		}
		else {
			cout << "Text is null or empty" << endl;
		}
	}



	void Sort(bool reverse = false) {
		for (size_t i = 0; i < GetLength()-1; i++){
			bool swapped = false;
			for (size_t k = 0; k < GetLength() - i - 1; k++) {
				if (IsReverse(reverse, text[k], text[k + 1])) {
					swapped = true;
					Swap(text[k], text[k + 1]);
				}
			}
			if (!swapped) {
				break;
			}
		}
	}

	char First() const {
		return text[0];
	}
	char Last() const {
		return text[GetLength()-1];
	}

	void Clear() {
		delete[]text;
		text = nullptr;
		SetLength(0);
	}

	~MyString(){
		delete[]text;
	}
};

class IntArray {

	int* arr;
	size_t size = 0;

	void SetSize(const int& size) {
		this->size = size;
	}

public:

	IntArray(const int* arr, const int & size) {
		SetArray(arr, size);
	}

	IntArray(const IntArray& other) {
		SetArray(other.arr, other.size);
	}

	IntArray& operator = (const IntArray& other) {
		SetArray(other.arr, other.size);
	}
	



	void SetArray(const int* arr, const int& size) {
		if (arr != nullptr) {
			this->arr = new int[size] {};
			for (size_t i = 0; i < size; i++) {
				this->arr[i] = arr[i];
			}
			SetSize(size);
		}
	}

	void PushFront(const int& newNum) {
		int newSize = GetSize() + 1;

		auto temp = new int[newSize] {};

		temp[0] = newNum;
		for (size_t i = 0; i < newSize; i++) {
			temp[i + 1] = this->arr[i];
		}

		SetArray(temp, newSize);
	}

	void PushBack(const int& newNum) {
		int newSize = GetSize() + 1;

		auto temp = new int[newSize] {};

		for (size_t i = 0; i < newSize; i++){ 
			temp[i] = this->arr[i];
		}
		temp[newSize-1] = newNum;

		SetArray(temp, newSize);
	}

	void DeleteByIndex(const int& index) {
		int newSize = GetSize() - 1;

		auto temp = new int[newSize] {};

		for (size_t i = 0, k = 0; i < newSize + 1; i++, k++) {
			if (i != index) {
				temp[k] = this->arr[i];
			}
			else {
				--k;
			}
		}

		SetArray(temp, newSize);
	}

	void InsertByIndex(const int& index, const int& newNum) {
		int newSize = GetSize() + 1;

		auto temp = new int[newSize] {};

		for (size_t i = 0, k = 0; i < newSize; i++, k++) {
			if (i != index) {
				temp[i] = this->arr[k];
			}
			else {
				temp[i] = newNum;
				--k;
			}
		}

		SetArray(temp, newSize);
	}

	void Clear() {
		delete[] arr;
		arr = nullptr;
		SetSize(0);
	}

	void Print()const {
		if (arr != nullptr) {
			for (size_t i = 0; i < size; i++) {
				cout << arr[i] << " ";
			}cout << endl;
		}
		else {
			cout << "Array is empty" << endl;
		}
	}


	int GetSize() {
		return this->size;
	}

	~IntArray(){
		delete[]arr;
	}

};

void main() {
#if 0
	MyString text = "apple";

	cout << text.GetText() << endl;
	text.Append(" samsung");
	cout << text.GetText() << endl;
	text.Append(" xiaomi");
	cout << text.GetText() << endl;

	cout << text.Find(*"e");
#endif // 0


}