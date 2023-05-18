#include <iostream>
using namespace std;

class Person {
	friend class Student;
protected:
	string name;
	int age;
public:
	Person();
	Person(string f, double s);
	Person(Person& T);
	virtual ~Person();
	void set_name(string n);
	void set_age(int a);
	Person& operator=(const Person& t);
	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, Person& p);

};
