#include <iostream>

using namespace std;

#pragma region Composition

class Time {
	int  hour;
	int minute;
public:
	Time() = default;

	Time(int minute, int hour) {
		SetTime(minute, hour);
	}

	int GetHour()const {
		return hour;
	}

	int GetMinute()const {
		return minute;
	}

	void SetTime(int m, int h) {
		minute = m;
		hour = h;
	}

	void ShowTime()const {
		if (GetHour() < 10) {
			cout << "0";
		}
		cout << GetHour() << ":";
		if (GetMinute() < 10) {
			cout << "0";
		}
		cout << GetMinute() << endl;
	}

	~Time(){
		cout << "Time object deleted" << endl;
	}

};

class Date {
	int day;
	int month;
	int year;
public:
	Date() = default;

	Date(int d, int m, int y) {
		SetDate(d, m, y);
	}

	int GetDay()const {
		return day;
	}

	int GetMonth()const {
		return month;
	}

	int GetYear()const {
		return year;
	}

	void SetDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	void ShowDate()const {
		if (GetDay() < 10) {
			cout << "0";
		}
		cout << GetDay() << " / ";
		if (GetMonth() < 10) {
			cout << "0";
		}

		cout << GetMonth() << " / ";

		cout << GetYear();
	}

	~Date(){
		cout << "Date object deleted" << endl;
	}

};


class Event {
	string name;
	Time time;
	Date date;
public:

	Event(int minute, int hour, int day, int month, int year, const string& name) {
		this->name = name;
		time.SetTime(minute, hour);
		date.SetDate(day, month, year);
	}

	void ShowEvent()const {
		cout << "Event : " << name << endl;
		date.ShowDate();
		cout << " at ";
		time.ShowTime();
		cout << endl;
	}

	~Event() {
		cout << "Event Object Deleted" << endl;
	}

};


#pragma endregion

#pragma region Aggregation

class Account {
public :
	string name;
	string account_no;

	~Account() {
		cout << "Account Deleted" << endl;
	}

};

class Customer {
	string name;
	string surname;
	Account* account = nullptr;
public:
	Customer(string n, string s) {
		this->name = n;
		this->surname = s;
	}

	void GenerateAccount() {
		account = new Account;
		account->name = "IBA";
		account->account_no = "23456787567";
	}

	~Customer(){
		if (account != nullptr) {
			delete account;
		}
	}

};

#pragma endregion

#pragma region Assosiation

class Doctor {};

class Patient {
	bool hasIllness;

public :
	void TakeDoctok(const Doctor& doctor) {

	}

};

#pragma endregion

#pragma region Dependecy

class Internet {
public :
	static bool HasConnection() {
		return true;
	}
};

class MSTeams {
public:
	MSTeams() {
		if (Internet::HasConnection()) {
			cout << "You connected successfully" << endl;
			cout << "Object Created" << endl;
		}
		else {
			cout << "Object didn't created" << endl;
			throw exception("error no internet");
		}
	}
};

#pragma endregion

#pragma region Inheritance

class Human {
public :
	Human() {
		cout << "Human constructor" << endl;
	}

	~Human(){
		cout << "Human destructor" << endl;
	}
};

class Student :Human {
public:
	Student() {
		cout << "Student constructor" << endl;
	}

	~Student() {
		cout << "Student destructor" << endl;
	}
};

#pragma endregion


#pragma region Inheritance(Public, Protected, Private)

class A {
private :
	int a;
protected:
	int b;
public:
	int c;

	void SetA(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	void ShowA() {
		cout << "A : " << a << " B : " << b << " C : " << c;
	}
};

class B :public A {
private :
	int d;
	void ShowB() {
		cout << a << endl; // private inaccessible
		cout << b << endl; // protected
		cout << c << endl; // public
	}
};

class C :protected A {
private:
	int d;
	void ShowB() {
		cout << a << endl; // private inaccessible
		cout << b << endl; // protected
		cout << c << endl; // protected
	}
};

class D :private A {
private:
	int d;
	void ShowB() {
		cout << a << endl; // private inaccessible
		cout << b << endl; // protected
		cout << c << endl; // protected
	}
};

#pragma endregion


void main(){	
#pragma region Composition
#if 0
	Event* event = new Event(5, 21, 8, 12, 2023, "Christmas");
	event->ShowEvent();
	delete event;
#endif // 0
#pragma endregion

#pragma region Aggregation
#if 0
	Customer customer("John", "Johnlu");
	//customer.GenerateAccount();
#endif // 0
#pragma endregion

#pragma region Dependecy
#if 0

	MSTeams teams;

#endif // true
#pragma endregion

}