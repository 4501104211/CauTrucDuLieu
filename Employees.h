#pragma once
#include <iostream>

using namespace std;

class Employees
{
	string _tk, _mk;

public:
	Employees(string TK = "", string MK = "111111") {
		_tk = TK;
		_mk = MK;
	};

	string getTK() {
		return _tk;
	}

	string getMK() {
		return _mk;
	}

	void doimaPIN(string p) {
		_mk = p;
	}

	friend bool operator* (Employees a, Employees b) {
		return (a.getTK() == b.getTK() && a.getMK() == b.getMK());
	}

	friend bool operator == (Employees a, Employees b) {
		return (a.getTK() == b.getTK());
	}

	friend bool operator != (Employees a, Employees b) {
		return (a.getTK() != b.getTK());
	}

	void operator *= (Employees a) {
		_mk = a.getMK();
	}

	friend ostream& operator<< (ostream& os, Employees a) {
		os << a._tk << " " << a._mk;
		return os;
	}
};

