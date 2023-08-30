#include <iostream>

using namespace std;

//struct Test {
//	int data1;
//	int data2;
//};

// access modifier
// public protected private

class Test {
	int data1;
public:
	int data2;
};

// variables - field  , member , attributes
// function  - method , member , attributes


//Accessor 
// setter or modificator
// getter or inspector

void CustomStrCopy(char*& destionation, const char* source) {

	int l = strlen(source);

	char* temp = new char[l] {};

	for (size_t i = 0; source[i] != '\0'; i++) {
		temp[i] = source[i];
	}
	temp[l] = '\0';
	delete[] destionation;
	destionation = temp;
	temp = nullptr;

}

class Data {
private:
	int data1;
	int data2;
public:
	void InitData(int d1, int d2) {
		data1 = d1;
		data2 = d2;
	};
	void Show() {
		cout << "Data 1 : " << data1 << endl;
		cout << "Data 2 : " << data2 << endl;
	}
};

class Product {
private:
	char name[30]{};
	double price=0;
	double discount=0;
public:


	Product(){
		strcpy_s(name, "");
		price = 0;
		discount = 0;
	}

	Product(const char* n, double p, double d) {
		SetName(n);
		SetPrice(p);
		SetDiscount(d);
	}

	char* GetName() {
		return name;
	}

	double GetPrice() {
		return price;
	}

	double GetDiscount() {
		return discount;
	}

	void SetName(const char* n) {
		if (n != nullptr) {
			int l = strlen(n);
			if (l >= 3) {
				strcpy_s(name, n);
			}
			else {
				cout << "At least 3 characters" << endl;
			}
		}
	}

	void SetPrice(double p) {
		if (p > 0) {
			price = p;
		}
		else {
			cout << "Price should be greater than 0" << endl;
		}
	}

	void SetDiscount(double d) {
		if (d > 0) {
			discount = d;
		}
		else {
			cout << "Discount should be greater than 0" << endl;
		}
	}

	void setData(const char* n, double p, double d) {
		strcpy_s(name, n);
		price = p;
		discount = d;
	}

	void Show() {
		cout << "Product Info" << endl;
		cout << "Name : " << name << endl;
		cout << "Price :" << price << endl;
		cout << "Discount : " << discount << endl;
	}
};

class Box {
	double length;
	double height;
	double breadth;
public:
	Box() {
		length = 0;
		breadth = 0;
		height = 0;
	};

	Box(double l, double b, double h) {
		length = l;
		breadth = b;
		height = h;
	};

	double GetVolume() {
		return length * breadth * height;
	}
};

class Point {
private:
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}

	Point(int x, int y) {
		x = x;
		y = y;
	}
	void SetX(int x) {
		x = x;
	}
	void SetY(int y) {
		y = y;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
};

class Counter {
private:
	int min;
	int max;
	int currentNum;
public:

	Counter() {
		int min = 0;
		int max = 100;
		currentNum = min;
	}
	Counter(int minValue, int maxValue) {
		if (minValue < maxValue) {
			min = minValue;
			SetMax(max);
			currentNum = minValue;
		}
	}

	void SetMin(int minValue) {
		if (minValue < max) {
			min = minValue;
		}
		else {
			cout << "Max should greater than mim" << endl;
		}
	}

	void SetMax(int maxValue) {
		if (maxValue > min) {
			max = maxValue;
		}
		else {
			cout << "Max should greater than mim" << endl;
		}
	}

	int incremenet() {
		if (currentNum == max) {
			currentNum = min;
		}
		else {
			currentNum += 1;
		}
		return currentNum;
	}

};

class Student {
private:
	char* name;
	char* surname;
	char* speciality;
	char* city;
	int age;
	int group_no;
public:
	Student() {
		CustomStrCopy(name, "");
		CustomStrCopy(surname, "");
		CustomStrCopy(speciality, "");
		CustomStrCopy(city, "");
		age = 0;
		group_no = 0;
	}

	Student(const char* na, const char* su, const char* sp, const char* ci, int ag, int gr) {
		CustomStrCopy(name,na);
		CustomStrCopy(surname,  su);
		CustomStrCopy(speciality,  sp);
		CustomStrCopy(city,  ci);
		SetAge(ag);
		SetGroupNo(gr);
	}

	void SetName(const char* n) {
		CustomStrCopy(*&name, n);
	}
	void SetSurname(const char* s) {
		CustomStrCopy(*&surname, s);
	}
	void SetSpeciality(const char* s) {
		CustomStrCopy(*&speciality, s);
	}
	void SetCity(const char* c) {
		CustomStrCopy(*&city, c);
	}
	void SetAge(int a) {
		if (age < 0) {
			cout << "Age should greater than 0" << endl;
		}
		else {
			age = a;
		}
	}
	void SetGroupNo(int g) {
		group_no = g;
	}

	const char* GetName() {
		return name;
	}
	const char* GetSurname() {
		return surname;
	}
	const char* GetSpeciality() {
		return speciality;
	}
	const char* GetCity() {
		return city;
	}
	int GetAge() {
		return age;
	}
	int GetGroupNo() {
		return group_no;
	}
	
	void ShowInfo() {
		cout << "Student Info" << endl;
		cout << "Student name : " << name << endl;
		cout << "Student age : " << age << endl;
		cout << "Student surname : " << surname << endl;
		cout << "Student speciality : " << speciality << endl;
		cout << "Student city : " << city << endl;
		cout << "Student group_no : " << group_no << endl;
	}


};

void main() {

#if 0
	Data obj; // obyekt ve ya instance
	obj.InitData(12, 15);
	obj.Show();

	cout << endl;

	Data obj2;
	obj2.InitData(10, 20);
	obj2.Show();
#endif // 0

#if 0
	Product p();
	p.setData("Samsung Galaxy S21", 1820, 3);
	p.Show();
#endif // 0
#if 0
	Product iphonePrd("Iphone 12 Pro", 2200, 5);
	iphonePrd.Show();
#endif // 0

#if 0
	Product p("Asus", 100, 10);
	p.SetPrice(-110);
	p.Show();
	//cout << p.GetPrice() << endl;	
#endif // 0

#if 0
	Box box(10, 20, 30);
	cout << box.GetVolume() << endl;
#endif // 0
	//Student s("Murad", "Gojayev", "Front end", "Baku", 21, 213);
	Student s;

	cout << s.GetName() << endl;
	s.ShowInfo();

}
