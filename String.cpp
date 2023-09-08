#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class User {
	string fullname;
	string username;
	string password;
public: 
	User() :fullname(""), username(""), password("") {}

	User(const string& fullname, const string& username, const string& password) {
		SetFullname(fullname);
		SetUsername(username);
		SetPassword(password);
	}

	string GetUsername()const {
		return fullname;
	}

	string GetPassword()const {
		return password;
	}

	string Fullname() const {
		return fullname;
	}

	void SetFullname(const string& fullname) {
		if (!fullname.empty()) {
			this->fullname = fullname;
		}
	}

	void SetUsername(const string& username) {
		if (!username.empty()) {
			this->username = username;
		}
	}

	void SetPassword(const string& password) {
		if (!password.empty()) {
			this->password = password;
		}
	}

	void Show()const {
		cout << "User Info" << endl;
		cout << "Full name: " << fullname << endl;
		cout << "User name: " << username << endl;
		string pass(password.size() * 2, '*');
		cout << "Password: " << pass;
	}

};

class Database {
	User** users;
	int count = 0;
public:
	bool SignIn(const string& username, const string& password) {}
	bool SignUp(const User& newUser);
	User* GetUserByUsername(const string& username);
	void ShowAllUsers()const;

	~Database(){

	}
};

void main() {
#if 0
	string text = "";
	cout << text << endl;
	cout << text.size() << endl;
	cout << text.length() << endl;
	cout << text.capacity() << endl;
	cout << text.max_size() << endl;
#endif // 0

#if 0
	string text(50, '*');
	cout << text << endl;
	cout << text.length() << endl;
	cout << text.capacity() << endl;
	text.reserve(1000);
	cout << text.capacity() << endl;
	text.shrink_to_fit();
	cout << "After shring" << endl;
	cout << text.capacity() << endl;
#endif // 0

#if 0
	string text = "Hello world";
	text += " Hello world";
	text += " Hello world";
	text += " Hello world";
	text += " Hello world";
	text += " Hello world";
	cout << text << endl;
	cout << text.size() << endl;
	cout << text.capacity() << endl;
	text.resize(35);
	cout << text << endl;
	cout << text.size() << endl;
	cout << text.capacity() << endl;
#endif // 0
#if 0
	string text = "Happy Programmers Day";
	cout << text << endl;
	text.clear();
		
	if (text.empty()) {
		cout << "No Characters" << endl;
	}
	else {
		cout << text << endl;
	}
#endif // 0
#if 0
	string message = "Hi All";
	cout << message << endl;
	message += " bye bye";
	cout << message << endl;
	message.append(" thanks");
	cout << message << endl;
#endif // 0

#if 0
	string text = "Happy Programmers Day";
#if 0
	cout << text << endl;
	text[0] = 'A';
	cout << text << endl;
	cout << text[7] << endl;
	cout << text.at(7) << endl;
#endif // 0

	/*
		for (size_t i = 0; i < text.length(); i++) {
			cout << text[i] << " ";
		}cout << endl;
	*/
	text.front() = 'A';
	text.back() = 'B';

	cout << text.front() << endl;
	cout << text.back() << endl;
	cout << text << endl;

	cout << text.substr(7, 14) << endl;
#endif // 0

	/*string text = "Some Text";

	text.insert(5, "Salam");
	cout << text << endl;*/

	//string text = "Sa?la?m ne?ces?en";
	//text = text.replace(0, text.length(), "?");
	//cout << text << endl;
		
	//string message = "Salam";
	//message.push_back('z');
	//cout << message << endl;
	//message.pop_back();
	//cout << message << endl;

	//string message = "Happy Programmers Day";
	///*message.erase(3, 8);
	//cout << message << endl;*/

	//int index = message.find('p');
	//cout << index << endl;
	//index = message.rfind('p');
	//cout << index << endl;

#if 0
	cout << "Enter text : " << endl;
	string text = "";
	getline(cin, text);
	cout << text << endl;
#endif // 0

	User* user = new User("John Johnlu", "john123", "johnjohn1100");
	user->Show();


 }