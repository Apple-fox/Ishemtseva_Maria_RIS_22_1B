#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person 
{
protected:	
	friend class Person;
	string obj;
	int score;
public:
	
	Student();
	Student(string name, double age, string ob, int sco);
	Student(Student& T);
	~Student();
	void set_obj(string j);
	void set_score(int s);
	void n_c();
	Student operator=(const Student& t);
	friend istream& operator>>(istream& in, Student& p);
	friend ostream& operator<<(ostream& out,const Student& p);
};