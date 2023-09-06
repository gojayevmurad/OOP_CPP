#include <iostream>

using namespace std;

class Network {
	static char* ip;
public:
	static int port;
	int data = 0;
	void Connect() {
		cout << "Connected" << endl;
		cout << ip << endl;
	}

	static void MyStaticMethod() {
		cout << ip << endl;
	}
};

char* Network::ip = new char[20] {"192.168.1.1"};
int Network::port = 27001;

#include <assert.h>;

class Airplane {
	int myid;
	char* model;
public:
	static int ID;
	static int MAX;

	Airplane(const char* model) {
		assert(ID < MAX && "Our Garage is Full");
		SetModel(model);
		myid = ++ID;
	}

	static int GetCurrentID() {
		return ID;
	}

	int GetId() {
		return myid;
	}

	char* GetModel() {
		return model;
	}
	
	void SetModel(const char* model) {
		if (model != nullptr) {
			int l = strlen(model);
			this->model = new char[l + 1] {};
			strcpy_s(this->model, l + 1, model);
		}
	}

	void Show() {
		cout << "ID : " << myid << endl;
		cout << "Model : " << model << endl;
	}
	~Airplane(){
		delete[] model;
	}

};

int Airplane::ID = 0;
int Airplane::MAX = 4;

class User {
	char* username;
	char* password;

	char* GetPassword() {
		return password;
	}

public:

	User() = default;

	User(const char* username, const char* password) {
		SetUsername(username);
		SetPassword(password);
	}

	User(const User& other) {
		cout << "Copy Constructor" << endl;
		SetUsername(other.username);
		SetPassword(other.password);
	}

	User& operator=(const User& other) {
		cout << "Copy assigment" << endl;
		SetUsername(other.username);
		SetPassword(other.password);
		return *this;
	}

	bool operator == (const User& other) {
		if (strcmp(this->username, other.username)==0 && strcmp(this->password, other.password)==0) {
			return true;
		}
		return false;
	}

	char* GetUsername() {
		return username;
	}



	void SetUsername(const char* username) {
		assert(username != nullptr && "username should not be null");
		int l = strlen(username);
		this->username = new char[l + 1] {};
		strcpy_s(this->username, l + 1, username);
	}

	void SetPassword(const char* password) {
		assert(password != nullptr && "pasword should not be null");
		int l = strlen(password);
		this->password = new char[l + 1] {};
		strcpy_s(this->password, l + 1, password);
	}

	void Show() {
		cout << "Username : " << username << endl;
		cout << "Password :";
		for (size_t i = 0; i < strlen(password); i++) {
			cout << "* ";
		}cout << endl;
	}

	~User(){
		delete username;
		delete password;
	}

};

class System {
	User* users;
	int count = 0;

public:
	System(User* users, int count) {
		this->users = users;
		this->count = count;
	}
	void Show() {
		for (size_t i = 0; i < count; i++){
			this->users[i].Show();
		}
	}

	~System(){
		delete[] users;
	}

};

class Debtor {
	int id;
	char* name;
	char* surname;
	char* work_address;
	double salary;
	int phone_number;

	static int ID;

	void _setId() {
		id = ID;
		ID++;
	}

public:

	Debtor(const char* name, const char* surname, const char* work_address, const double& salary, const int& phone_number) {
		_setId();
		SetName(name);
		SetSurname(surname);
		SetWorkAddress(work_address);
		SetSalary(salary);
		SetPhoneNumber(phone_number);
	}

	void SetName(const char* name) {
		assert(name != nullptr && "Name should not be null");
		int l = strlen(name);
		this->name = new char[l + 1] {};
		strcpy_s(this->name, l + 1, name);
	}

	void SetSurname(const char* surname) {
		assert(surname != nullptr && "Surname should not be null");
		int l = strlen(surname);
		this->surname = new char[l + 1] {};
		strcpy_s(this->name, l + 1, surname);
	}

	void SetWorkAddress(const char* work_address) {
		assert(work_address != nullptr && "Work address should not be null");
		int l = strlen(work_address);
		this->work_address = new char[l + 1] {};
		strcpy_s(this->work_address, l + 1, work_address);
	}

	void SetSalary(const double& salary) {
		assert(salary > 0 && "Name should not be null");
		this->salary = salary;
	}

	void SetPhoneNumber(const int& phone_number) {
		this->phone_number = phone_number;
	}

	int GetId() {
		return this->id;
	}

	const char* GetName() {
		return this->name;
	}

	const char* GetSurname() {
		return this->surname;
	}

	const char* GetWorkAddress() {
		return this->work_address;
	}

	double GetSalary() {
		return this->salary;
	}

	int GetPhoneNumber() {
		return this->phone_number;
	}

	~Debtor(){
		delete name;
		delete surname;
		delete work_address;
	}
};

void main() {
#if 0
	cout << Network::port << endl;
	Network::MyStaticMethod();
#endif // 0

#if 0
	Airplane a("Boeng-747");
	Airplane b("Airbus 00");
	Airplane c("F 16");

	a.Show();
	b.Show();
	c.Show();
#endif // 0

#if 0


	// Shallow copy
	// Deep copy

	User u1("Eli123", "eli123");
	User u2("leyla123", "leyla123");

	User* users = new User[2]{ u1,u2 };

	System system (users, 2);
	system.Show();
#endif // 0

}