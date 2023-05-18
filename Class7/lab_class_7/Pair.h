#pragma once
#include <iostream>
class Pair{
	int one;
	double two;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	void operator=(int);
	void operator=(double);
	Pair& operator*(const Pair&);
	int get_one();
	double get_two();
	void set_one(int);
	void set_two(double);
	friend std::ostream& operator<<(std::ostream&, const Pair&);
	friend std::istream& operator>>(std::istream&, Pair&);
};

inline Pair::Pair() {
	one = 0;
	two = 0;
}
inline Pair::Pair(int a, double b) {
	one = a;
	two = b;
}
inline Pair::Pair(const Pair& P) {
	one = P.one;
	two = P.two;
}
inline void Pair::operator=(int a) {
	one = a;
}
inline void Pair::operator=(double b) {
	two = b;
}
inline int Pair::get_one() { return one; }

inline double Pair::get_two() { return two; }

inline void Pair::set_one(int a) { one = a; }

inline void Pair::set_two(double b) { two = b; }

inline Pair& Pair::operator*(const Pair& P) {
	Pair a;
	a.one = one * P.one;
	a.two = two * P.two;
	return a;
}

inline std::ostream& operator<<(std::ostream& out, Pair& P) {
	out << P.get_one() << ":" << P.get_two() << " ";
	return out;
}
inline std::istream& operator>>(std::istream& in, Pair& P) {
	int a; double b;
	in >> a;
	P.set_one(a);
	in >> b;
	P.set_two(b);
	return in;
}

