#include <iostream>
#include "Object.h"
using namespace std;

class New_Person: public Object
{
public:
	New_Person();
	New_Person(string f, double s);
	New_Person(New_Person& T);
	virtual ~New_Person();
	void Show();
	void set_name(string n);
	void set_age(int a);
	New_Person& operator=(const New_Person& t);
	friend istream& operator>>(istream& in, New_Person& p);
	friend ostream& operator<<(ostream& out, New_Person& p);
protected:
	string name;
	int age;
};
