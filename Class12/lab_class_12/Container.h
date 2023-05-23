#pragma once
#include <iostream>
#include <set>
using namespace std;
//template <class T>

template <class T>
class Container{
	multiset<T, less<T>> v;
    typedef multiset<T, less<T>> msP;
    int len;
	//msP::iterator begin;
	//msP::iterator end;
public:
	Container(void);
	Container(int n);
	void Print();
	T random();
	~Container();
    T average_T();
    void set_range_T(T, T);
    T min_max_T();
    void insert_t(T);
    void more_on_sum_T(T);
};

template <class T>
Container<T>::Container() {
	len = 0;
}
template<class T>
Container<T>::~Container() {

}
template<class T>
T Container<T>::random() {
	int a = rand() % 100;
	int b = rand() % 10 + 1;
	double c = (double)a / b;
	T t;
	t.get_first(a);
	t.get_second(c);
	return t;
}
template <class T>
Container<T>::Container(int n) {
	T a;
	for (int i = 0; i < n; i++) {
		a = random();
		v.insert(a);
	}
	len = n;
}

template<class T>
void Container<T>::Print() {
	for (auto i : v) {
		//T t = *i;
		cout << i << endl;
	}
	cout << endl;
}

template<class T>
T Container<T>::average_T() {
    T sum;
    sum.get_first(0);
    sum.get_second(0);
    int c = 0;
    for (auto i : v) {
        sum = sum + i;
        c++;
    }
    sum = sum / c;
    return sum;
}
template<class T>
void Container<T>::set_range_T(T a, T b) {
    T* ab = new T[v.size()];
    int t = 0;
    for (auto i : v) {
        if (i >= a && i <= b) {
            ab[t] = i;
            t++;
        }
    }
    for (int i = 0; i < t; i++) {
        v.erase(ab[i]);
        len--;
    }
}
template<class T>
void Container<T>::insert_t(T n) {
    len++;
    v.insert(n);
}
template<class T>
T Container<T>::min_max_T() {
    T min = *v.begin(), max;
    for (auto i : v) {
        if (i > max) max = i;
        if (i < min) min = i;
    }
    return min + max;
}
template<class T>
void Container<T>::more_on_sum_T(T t) {
    multiset<T, less<T>> res;
    for (auto i : v) {
        T y = i;
        res.insert(y + t);
    }
    v = res;
}
