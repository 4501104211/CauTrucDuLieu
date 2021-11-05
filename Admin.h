#pragma once
#include <iostream>
using namespace std;
class Admin {
	string Username;
	string Password;
public:
	Admin() {};
	Admin(string a, string b) {
		Username = a;
		Password = b;
	}
	friend istream& operator >> (istream& is, Admin& a) {
		is >> a.Username >> a.Password;
		return is;
	}
	friend ostream& operator << (ostream& os, Admin a) {
		os << a.Username << " " << a.Password;
		return os;
	}
	friend bool operator!=(Admin a, Admin b) {
		return (a.Username != b.Username && a.Password != b.Password);
	}
	friend bool operator==(Admin a, Admin b) {
		return (a.Username == b.Username && a.Password == b.Password);
	}
};