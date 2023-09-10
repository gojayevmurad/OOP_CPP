#include <iostream>
#include <Windows.h>

using namespace std;

#pragma region Scope Resolution


class SMS {
public : 
	int id;
	string text;
	string number;

	SMS() {
		cout << "SMS default constructor" << endl;
		id = 1;
		text = "Hello Guys";
		number = "+994707070707";
	}

	void Show() {
		cout << "===================SMS===================" << endl;
		cout << id << endl;
		cout << text << endl;
		cout << number << endl;
	}

};

class Email {
public :
	int id;
	string text;
	string email;
	string toEmail;
	Email() {
		cout << "Email default constructor" << endl;
		id = 1;
		text = "Hello, i wrote from Email";
		email = "john.johnlu@gmail.com";
		toEmail = "john.johnsuz@gmail.com";
	}

	void Show() {
		cout << "==================EMAIL======================" << endl;
		cout << id << endl;
		cout << text << endl;
		cout << toEmail << endl;
	}
};

class MessageService : public Email, public SMS {
	string companyName;
public:
	MessageService() {
		companyName = "Babat Shirket:)";
	}

	void Show() {
		cout << "SMS text : " << SMS::text << endl;
		cout << "Email text : " << Email::text << endl;
	}

};
#pragma endregion

class ElectronicDevice {
public:
	string data = "";
	ElectronicDevice() {
		cout << "Default constructor for Electronic Device" << endl;
	}
};

class Printer :virtual public ElectronicDevice {
public:
	Printer() {
		data = "Printer";
	}
};

class Scanner :virtual public ElectronicDevice {
public:
	Scanner() {
		data = "Scanner";
	}
};

class Copier :public Scanner, public Printer {
public:
	Copier() {
		cout << Scanner::data << endl;
		cout << Printer::data << endl;
	}
};

// static(earlybinding ) polymorphism

int add(int n1, int n2) {
	return n1 + n2;
}

int add(int n1, int n2,  int n3) {
	return n1 + n2 + n3;
}

// dynamic(late binding ) polymorphism

int Sum(int n1, int n2) {
	return n1 + n2;
}



////////////////////////////////////////////

void A() {
	cout << "A" << endl;
}

void B() {
	cout << "B" << endl;
}

void C() {
	cout << "C" << endl;
}


void CallFunction() {
	A();
	B();
}





void main() {

	/*
		int(*ptr)(int, int) = Sum;
		cout << ptr(10, 20);
	*/

	/*
		void(*ptr)() = nullptr;

		ptr = A;
		ptr();
		Sleep(2000);
		ptr = B;
		ptr();
		Sleep(2000);
		ptr();
	*/


	void(*ptr[3])() = {A,B,C};

	for (size_t i = 0; i < 3; i++){
		auto func = ptr[i];
		//func();
	}

	auto array = new void* [3] {A, B, C};

	for (size_t i = 0; i < 3; i++){
		auto func = (void(*)())array[i];
		func();
	}

}