#include <iostream>
#include <assert.h>

using namespace std;

//initializer list
class Test {
	const int data;
	int age = 0;
	char* name;

public :

	Test() : data(0), name(nullptr) {
		//data = 0; // error
		name = new char[20] {"no name"};
	};

	Test(int data):data(data) {
		//this->data = data; //error
	}

	void Show() const {
		cout << "Data : " << data << endl;
		cout << "Age : " << GetAge() << endl;
	}

	void SetAge(int age) {
		this->age = age;
	}

	int GetAge() const {
		return age;
	}
};

class Computer {
	char* model;
	char* vendor;
	double cpu_power;
	int core;
public:
	Computer() :model(nullptr), vendor(nullptr), cpu_power(0), core(0) {};

	Computer(const char* model, const char* vendor, const double& cpu_power, const int& core) {
		SetModel(model);
		SetVendor(vendor);
		SetCpuPower(cpu_power);
		SetCore(core);
	};

	// Copy constructor
	Computer(const Computer& other) {
		cout << "Copy constructor" << endl;
		SetModel(other.model);
		SetVendor(other.vendor);
		SetCpuPower(other.cpu_power);
		SetCore(other.core);
	}

	// Copy assigment
	Computer operator = (const Computer& other) {
		cout << "Copy assigment" << endl;
		SetModel(other.model);
		SetVendor(other.vendor);
		SetCpuPower(other.cpu_power);
		SetCore(other.core);
		return *this;
	}

#pragma region Setters

	void SetModel(const char* model) {
		assert(model != nullptr && "Model should not be null");
		int l = strlen(model);
		this->model = new char[l + 1] {};
		strcpy_s(this->model, l + 1, model);
	}

	void SetVendor(const char* vendor) {
		assert(vendor != nullptr && "Vendor should not be null");
		int l = strlen(vendor);
		this->vendor = new char[l + 1] {};
		strcpy_s(this->vendor, l + 1, vendor);
	}

	void SetCpuPower(const double& cpu_power) {
		assert(cpu_power > 0 && "Cpu Power should be greater than 0");
		this->cpu_power = cpu_power;
	}

	void SetCore(const int& core) {
		assert(core > 0 && "Core should be greater than 0");
		this->core = core;
	}

#pragma endregion

#pragma region Getters

	int GetCore()const {
		return core;
	}

	double GetCpuPower()const {
		return cpu_power;
	}

	const char* GetModel()const {
		return model;
	}

	const char* GetVendor()const {
		return vendor;
	}

#pragma endregion

	void Show() const {
		cout << "Model : " << GetModel() << endl;
		cout << "Vendor : " << GetVendor() << endl;
		cout << "Cpu Power :" << GetCpuPower()<<"GHz" << endl;
		cout << "Core : " << GetCore() << endl;
	}

	~Computer() {
		delete[] model;
		delete[] vendor;
	}

};

Computer Foo(Computer obj) {
	auto result = obj;
	return obj;
}


void main() {

	Computer comp("Rog Stric", "Asus", 4.5, 8);
	//comp.Show();
	//auto obj = comp;
	Foo(comp);
}