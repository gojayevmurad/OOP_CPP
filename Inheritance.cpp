#include <iostream>

using namespace std;

class Human {
	string name;
	string surname;
	int age;

public:

	Human() = default;

	Human(const string& name, const string& surname, const int& age) {
		SetName(name);
		SetSurname(surname);
		SetAge(age);
	}

	string GetName()const {
		return name;
	}

	string GetSurname()const {
		return surname;
	}

	int GetAge()const {
		return age;
	}

	void SetName(const string& name) {
		this->name = name;
	}

	void SetSurname(const string& surname) {
		this->surname = surname;
	}

	void SetAge(const int& age) {
		this->age = age;
	}

	void Show()const {
		cout << "Name : " << GetName() << endl;
		cout << "Surname : " << GetSurname() << endl;
		cout << "Age : " << GetAge() << endl;
	}

};

class Teacher:Human {
	double salary;
public:
	Teacher() = default;
	Teacher(const string& name, const string& surname, const int& age, const double& salary)
		:Human(name, surname, age)
	{
		SetSalary(salary);
	}

	double GetSalary()const {
		return salary;
	}

	void SetSalary(const double& salary) {
		this->salary = salary;
	}

	void Show()const {
		cout << "Name : " << GetName() << endl;
		cout << "Surname : " << GetSurname() << endl;
		cout << "Age : " << GetAge() << endl;
		cout << "Salary : " << GetSalary() << endl;
	}

};

class Director :Teacher {
	string degree;

public:
	Director() = default;
	Director(const string& name, const string& surname, const int& age, const double salary, const string& degree) 
		:Teacher(name, surname, age, salary)
	{
		SetDegree(degree);
	}

	string GetDegree()const{
		return degree;
	}

	void SetDegree(const string& degree) {
		this->degree = degree;
	}

	void Show()const {
		Teacher::Show();
		cout << "Degree : " << degree << endl;
	}

};

class Student:Human {
	double score;
public:
	Student() = default;
	Student(const string& name, const string& surname, const int& age, const double& score) 
		:Human(name, surname, age)
	{
		SetScore(score);
	}

	double GetScore()const {
		return score;
	}

	void SetScore(const double& score) {
		this->score = score;
	}

	void Show()const {
		Human::Show();
		cout << "Score : " << GetScore() << endl;
	}

};



void main() {

	Teacher teacher("Elvin", "Camalzade", 24, 1000000);
	teacher.Show();

	Student student("John", "Johnsuz", 32, 99);
	student.Show();

	Director director("Aleksey", "Sleptsov", 40, 3000000, "CEO");
	director.Show();

}