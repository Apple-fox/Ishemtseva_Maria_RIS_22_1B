#pragma once
#include "Print.h"
class Magazin:
	public Print
{
protected:
	int count;
public:
	Magazin();
	Magazin(int);
	Magazin(const Magazin&);
	~Magazin();
	void set_count(int);
	int get_count();
	void Show();
	void Input();
	Magazin& operator=(const Magazin&);
};

