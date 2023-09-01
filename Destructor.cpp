#include <iostream>

using namespace std;

class Operation {
	int number1;
	int number2;
public:
	Operation() {};
	Operation(int n1, int n2) {
		number1 = n1;
		number2 = n2;
	}
	inline int GetSum() {
		return number1 + number2;
	}
};

class Car {
	char* model;
	char* vendor;
	int year = 0;
public:
	Car() {
		SetModel("no model");
		SetVendor("no vendor");
		SetYear(0);
	};
	Car(const char* model, const char* vendor, const int& year) {
		SetModel(model);
		SetVendor(vendor);
		SetYear(year);
	}

	char* GetModel() {
		return model;
	}

	char* GetVendor() {
		return vendor;
	}

	int GetYear() {
		return year;
	}

	void SetModel(const char* m) {
		if (m != nullptr) {
			int l = strlen(m);
			model = new char[l + 1] {};
			strcpy_s(model, l + 1, m);
		}
	}

	void SetVendor(const char* v) {
		if (v != nullptr) {
			int l = strlen(v);
			vendor = new char[l + 1] {};
			strcpy_s(vendor, l + 1, v);
		}
	}

	void SetYear(const int& y) {
		if (y > 0) {
			year = y;
		}
		else {
			cout << "Year should be greater than 0" << endl;
		}
	}

	void Show() {
		cout << "Car Info" << endl;
		cout << "Model : " << model << endl;
		cout << "Vendor :" << vendor << endl;
		cout << "Year :" << year << endl;
	}

	~Car(){ // Destructor
		delete[] model;
		delete[] vendor;
		cout << "Object deleted" << endl;
	}
};

class Point {
	int x;
	int y;
public:

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Show() {
		cout << "X : " << x << endl;
		cout << "Y : " << y << endl;
	}


};

class Car2 {
	char* model;
	char* vendor;
	int year = 0;
public:
	Car2() {
		SetModel("no model");
		SetVendor("no vendor");
		SetYear(0);
	};
	Car2(const char* model, const char* vendor, const int& year) {
		SetModel(model);
		SetVendor(vendor);
		SetYear(year);
	}

	char* GetModel() {
		return model;
	}

	char* GetVendor() {
		return vendor;
	}

	int GetYear() {
		return year;
	}

	void SetModel(const char* m) {
		if (m != nullptr) {
			int l = strlen(m);
			model = new char[l + 1] {};
			strcpy_s(model, l + 1, m);
		}
	}

	void SetVendor(const char* v) {
		if (v != nullptr) {
			int l = strlen(v);
			vendor = new char[l + 1] {};
			strcpy_s(vendor, l + 1, v);
		}
	}

	void SetYear(const int& y) {
		if (y > 0) {
			year = y;
		}
		else {
			cout << "Year should be greater than 0" << endl;
		}
	}

	void Show() {
		cout << "Car Info" << endl;
		cout << "Model : " << model << endl;
		cout << "Vendor :" << vendor << endl;
		cout << "Year :" << year << endl;
	}

	~Car2() { // Destructor
		delete[] model;
		delete[] vendor;
		cout << "Object deleted" << endl;
	}
};

class Gallery {
private :
	char* name;
	Car2** cars;
	int car_count;
public:
	Gallery(const char* name) {
		SetName(name);
	}

	~Gallery(){
		delete[] name;
		for (size_t i = 0; i < car_count; i++){
			delete cars[i];
		}
		delete[] cars;
	}

	void AddCar(Car2 *car) {
		auto temp = new Car2 * [this->car_count+1] {};

		for (size_t i = 0; i < car_count; i++){
			temp[i] = cars[i];
		}

		temp[car_count] = new Car2(*car);
		++car_count;
		cars = temp;
		temp = nullptr;
	}

	void SetName(const char* name) {
		if (name != nullptr) {
			int l = strlen(name);
			this->name = new char[l + 1] {};
			strcpy_s(this->name, l + 1, name);
		}
	}

	char* GetName() {

	}

	void Show() {
		for (size_t i = 0; i < car_count; i++){
			cars[i]->Show();
		}
	}
};

int product_id = 0;

class Product {

	int id;
	char* name;
	char* description;
	double price;
	double discount;

public:

	Product( const char* name, const char* description, double price, double discount) {
		SetId();
		SetName(name);
		SetDescription(description);
		SetPrice(price);
		SetDiscount(discount);
	}

	~Product(){
		delete name;
		delete description;
	}

	void SetId() {
		this->id = product_id;
		++product_id;
	}
	void SetName(const char* name) {
		if (name != nullptr) {
			int l = strlen(name);
			this->name = new char[l + 1] {};
			strcpy_s(this->name, l + 1, name);
		}
	}
	void SetDescription(const char* description) {
		if (description != nullptr) {
			int l = strlen(description);
			this->description = new char[l + 1] {};
			strcpy_s(this->description, l + 1, description);
		}
	}
	void SetPrice(double price) {
		if (price > 0) {
			this->price = price;
		}
	}
	void SetDiscount(double discount) {
		if (discount >= 0) {
			this->discount = discount;
		}
	}

	int GetId() {
		return this->id;
	}
	const char* GetName() {
		return this->name;
	}
	const char* GetDescription() {
		return this->description;
	}
	double GetPrice() {
		return this->price;
	}
	double GetDiscount() {
		return this->discount;
	}

	double GetPriceWithDiscount() {
		return price - (price / 100 * discount);
	}

	void Show() {
		cout << "====Product=======Info====" << endl;
		cout << "Id : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Description : " << description << endl;
		cout << "Price : " << price << endl;
		cout << "Discount : " << discount << endl;
		cout << "==========================" << endl;
	}
};

class Stock {

	char* address;
	Product ** products;
	int products_count = 0;

public:
	Stock(const char* address) {
		SetAddress(address);
	}
	~Stock(){
		delete address;
		for (size_t i = 0; i < products_count; i++){
			delete products[i];
		}
		delete[] products;
	}

	void SetAddress(const char* address) {
		if (address != nullptr) {
			int l = strlen(address);
			this->address = new char[l + 1] {};
			strcpy_s(this->address, l + 1, address);
		}
	}

	void ShowStock() {
		cout << this->address << endl;
		for (size_t i = 0; i < products_count; i++){
			products[i]->Show();
		}
	};

	Product* GetProductById(int id) {
		for (size_t i = 0; i < products_count; i++){
			if (products[i]->GetId() == id) {
				return products[i];
			}
		}
	};

	void AddProduct(const Product* product) {
		if (product != nullptr) {
			auto temp = new Product * [products_count + 1] {};
			
			for (size_t i = 0; i < products_count; i++){
				temp[i] = products[i];
			}
			temp[products_count] = new Product(*product);

			++products_count;
			this->products = temp;
		}
	};

	void DeleteProductById(int id) {
		for (size_t i = 0; i < products_count; i++){
			if (products[i]->GetId() == id) {

				auto temp = new Product * [products_count - 1] {};

				for (size_t i = 0, k=0; i < products_count; i++, k++){
					if (products[i]->GetId() != id) {
						temp[k] = products[i];
					}
					else {
						k -= 1;
					}
				}
				--products_count;
				products = temp;
				temp = nullptr;
			}
		}
	};
};

void main() {

#if 0
	Operation op(100, 200);
	cout << op.GetSum() << endl; // inline func
#endif // 0
#if 0
	Car car("GL 500", "Mercedess", 2016);
	car.Show();
#endif // 0
#if 0
	Point p(10, 20);
	p.Show();
#endif // 0
#if 0


	Car2** cars = new Car2 * [2] {
		new Car2("GL 500", "Mercedes", 2016),
		new Car2("Esclade", "Cadillac", 2019),
	};

	for (size_t i = 0; i < 2; i++){
		cars[i]->Show();
	}
#endif // 0
#if 0
	Car2* c1 = new Car2("GL 500", "Mercedess", 2016);
	Car2* c2 = new Car2("ES 300", "Lexus", 2023);

	Gallery gallery("Best Cars");
	gallery.AddCar(c1);
	gallery.AddCar(c2);
	gallery.Show();
#endif // 0

	/*
		Task 

		class Product{}
		id , name , description price discount
		ShowProduct(), GetPriceWithDiscount()

		class Stock{}
		char * address;
		Product**products / :: array
		ShowStock();
		Product * GetProduct(int id);
		void AddProduct(const Product * product)
		void Update(const Product * product);
		void DeleteProductById(int id)
		
	*/
	
	Stock stock("best stock:)");

	Product* p1 = new Product("Iphone 13 Pro", "Blue", 1999.99, 10);
	Product* p2 = new Product("Iphone 14 Pro", "Gray", 2999.90, 3);
	Product* p3 = new Product("Samsung Galaxy S21", "Black", 2399, 4);

	stock.AddProduct(p1);
	stock.AddProduct(p2);
	stock.AddProduct(p3);
	stock.GetProductById(1)->Show();
	cout << "Price with discount : " << p1->GetPriceWithDiscount() << endl;
}