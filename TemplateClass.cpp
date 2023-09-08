#include <iostream>

using namespace std;

#if 0

class intarray {
private:
	int* arr;
	int size = 0;
public:
	intarray(int* arr, int size) {
		this->arr = new int [size] {};
		for (size_t i = 0; i < size; i++){
			this->arr[i] = arr[i];
		}
	}

	int getfirst()const {
		return arr[0];
	}
	~intarray(){
		delete[] arr;
	}

};

template<typename t>
class templatearray {
	t* arr;
	int size = 0;
public:
	templatearray(t* arr, int size) {
		this->size = size;
		this->arr = new t[size] {};
		for (size_t i = 0; i < size; i++){
			this->arr[i] = arr[i];
		}
	}

	void show() {
		for (size_t i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}cout << endl;
	}

	t getfirst()const {
		return arr[0];
	}

	~templatearray(){
		delete[] arr;
	}
};


template<typename t>
class test {
	t first;
	t second;
public:
	test(t first, t second) {
		this->first = first;
		this->second = second;
	}

	void show()const {
		cout << "first : " << first << endl;
		cout << "second : " << second << endl;
	}
};

template<typename T1, typename  T2>
class Test2 {
	T1 first;
	T2 second;
public:
	Test2(T1 first, T2 second) {
		this->first = first;
		this->second =second; 
	}

	void show()const {
		cout << "first : " << first << endl;
		cout << "second : " << second << endl;
	}
};

#endif // 0

class User {
public : 
	char* name;
	int age;

	User() {
		
	}

	User(char* name, int age) {
		this->name = name;
		this->age = age;
	}
};

template <typename T>
class Test {
	T data;
public:
	Test(const T& data) {
		this->data = data;
	}

	void Show() const {
		cout << data << endl;
	}

};

template <>
class Test<User> {
	User data;
public:
	Test(const User& data) {
		this->data = data;
	}

	void Show() const {
		cout << data.name << endl;
		cout << data.age << endl;
	}

};


void main() {
#if 0
	templatearray<int>myarr(new int[3] {10, 20, 30}, 3); // ok
	templatearray<double>myarr2(new double[3] {10.1, 20.2, 30.56}, 3); // ok
	templatearray<char>myarr3(new char[3] {'a', 'b', 'c'}, 3); // ok
	myarr.show();
#endif // 0

#if 0
	test<float> obj(11.3f, 10.26f);
	obj.show();
#endif // 0
#if 0
	Test2<char, double> obj('j', 12.12);
	obj.show();
#endif // 0

	Test<int> obj(100);
	obj.Show();

	Test<User> obj2(User(new char[20] {"admin"}, 25));

	obj2.Show();

}