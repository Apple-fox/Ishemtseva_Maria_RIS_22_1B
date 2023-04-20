#include <iostream>
#include "New_Person.h"
using namespace std;

class New_Student :
	public New_Person {
public:
	New_Student();
	New_Student(string name, double age, string ob, int sco);
	New_Student(New_Student& T);
	~New_Student();
	void Show();
	void set_obj(string j);
	void set_score(int s);
	void n_c();
	New_Student operator=(const New_Student& t);
	friend istream& operator>>(istream& in, New_Student& p);
	friend ostream& operator<<(ostream& out, New_Student& p);
protected:
	string obj;
	int score;
};