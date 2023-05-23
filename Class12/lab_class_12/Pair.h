#include <iostream>
using namespace std;
class Pair {

	int first;
	double second;


public:
	Pair();
	Pair(int, double);

	Pair(const Pair&);

	~Pair();

	void get_first(int);

	void get_second(double);
	int set_first() { return first; };
	double set_second() { return second; };
	Pair random();
	Pair& operator=(const Pair&);
	Pair operator+(int);
	Pair operator+(double);
	Pair operator+(const Pair&);
	//Pair operator/(const Pair&);
	Pair operator/(int);

	bool operator>(const Pair&) const;
	bool operator<(const Pair&) const;
	bool operator<=(const Pair&) const;
	bool operator>=(const Pair&) const;
	bool operator==(const Pair&) const;

	/*bool operator>(int);
	bool operator<(int);
	bool operator<=(int);
	bool operator>=(int);

	bool operator>(double);
	bool operator<(double);
	bool operator<=(double);
	bool operator>=(double);*/

	Pair operator-(const Pair&);
	friend istream& operator>>(istream& in, Pair&);
	friend ostream& operator<<(ostream& out, Pair&);
};

