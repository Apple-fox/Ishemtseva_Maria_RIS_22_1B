#include <iostream>
#include <List>
#include <cstdlib>
#include <string>
#include <Iterator>
#include "Pair.h"
#include "List_T.h"
#include <queue>
using namespace std;
typedef list<double> Lis;
typedef priority_queue<Pair> QP;
Lis make_list_double(int n) {
    Lis l;
    for (int i = 0; i < n; i++) {
        int a = rand() % 100;
        int b = rand() % 10+1;
        l.push_back((double)a / b);
    }
    return l;
}

void print_list_double(Lis l) {
    for (auto i: l) {
        cout << i << " ";
    }
    cout << endl;
}

double average_double(Lis l) {
    double sum=0;
    int c=0;
    for (auto i : l) {
        sum += i;
        c++;
    }
    return (double)sum / c;
}

void set_range_double(Lis& l, double a, double b) {
    list<double>::iterator* ab = new list<double>::iterator[l.size()];
    int t = 0;
    list<double>::iterator pos = l.begin();
    for (list<double>::iterator i = l.begin(); i != l.end(); i++) {
        if (*i >= a && *i <= b) {
            ab[t] = i;
            t++;
        }
    }
    for (int i = 0; i < t; i++) {
        l.erase(ab[i]);
    }
}

double min_max_double(Lis& l) {
    double min = *l.begin(), max = *l.begin();
    for (list<double>::iterator i = l.begin(); i != l.end(); i++) {
        if (*i > max) max = *i;
        if (*i < min) min = *i;
    }
    return min + max;
}

void more_on_sum_double(Lis& l, double sum) {
    for (list<double>::iterator i = l.begin(); i != l.end(); i++) {
        *i += sum;
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
typedef list<Pair> Lis_Pair;
Lis_Pair make_list_Pair(int n) {
    Lis_Pair l;
    for (int i = 0; i < n; i++) {
        int a = rand() % 100;
        int b = rand() % 10 + 1;
        double c = (double)a / b;
        Pair t;
        t.get_first(a);
        t.get_second(c);
        l.push_back(t);
    }
    return l;
}

void print_list_Pair(Lis_Pair l) {
    for (auto i : l) {
        cout << i << " ";
    }
    cout << endl;
}

Pair average_Pair(Lis_Pair l) {
    Pair sum;
    sum.get_first(0);
    sum.get_second(0);
    int c = 0;
    for (auto i : l) {
        sum = sum + i;
        c++;
    }
    sum = sum / c;
    return sum;
}

void set_range_Pair(Lis_Pair& l, Pair a, Pair b) {
    list<Pair>::iterator* ab = new list<Pair>::iterator[l.size()];
    int t = 0;
    list<Pair>::iterator i = l.begin();
    for (auto j : l) {
        if (j > a && j < b) {
            ab[t] = i;
            t++;
        }
        i++;
    }
    for (int i = 0; i < t; i++) {
        cout << *ab[i] << endl;
        l.erase(ab[i]);
    }
}

Pair min_max_Pair(Lis_Pair& l) {
    Pair min = *l.begin(), max;
    for (list<Pair>::iterator i = l.begin(); i != l.end(); i++) {
        if (*i > max) max = *i;
        if (*i < min) min = *i;
    }
    return min + max;
}

void more_on_sum_Pair(Lis_Pair& l, Pair t) {
    for (list<Pair>::iterator i = l.begin(); i != l.end(); i++) {
        *i = *i + t;
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
QP make_queue_Pair(int n) {
    QP qup;
    for (int i = 0; i < n; i++) {
        int a = rand() % 100;
        int b = rand() % 10 + 1;
        double c = (double)a / b;
        Pair t;
        t.get_first(a);
        t.get_second(c);
        qup.push(t);
    }
    return qup;
}

void print_queue_Pair(QP qup) {
    Lis_Pair l;
    Pair t;
    while (!qup.empty()) {
        t = qup.top();
        cout << t << endl;
        l.push_back(qup.top());
        qup.pop();
    }
    for (auto i : l) {
        qup.push(i);
    }
}
void print_queue_T(QP qup) {
    List_T<Pair> L;
    while (!qup.empty()) {
        L.pushback(qup.top());
        qup.pop();
    }
    Node<Pair>* curr = L.get_head();
    while (curr != nullptr) {
        qup.push(curr->data);
        curr = curr->next;
    }
    curr = L.get_head();
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
}
Pair average_queue_Pair(QP qup) {
    Lis_Pair l;
    Pair sum;
    sum.get_first(0);
    sum.get_second(0);
    int c = 0;
    while (!qup.empty()) {
        l.push_back(qup.top());
        qup.pop();
    }
    for (auto i : l) {
        qup.push(i);
    }
    for (auto i : l) {
        sum = sum + i;
        c++;
    }
    sum = sum / c;
    return sum;
}

void set_range_queue_Pair(QP& qup, Pair a, Pair b) {//переделать
    Lis_Pair l;
    while (!qup.empty()) {
        l.push_back(qup.top());
        qup.pop();
    }
    auto it = l.begin();
    while (it != l.end()) {
        if (*it > a && *it < b) {
            it = l.erase(it);
        }
        else {
            ++it;
        }
    }
    for (auto i : l) {
        qup.push(i);
    }
}

Pair min_max_queue_Pair(QP& qup) {
    Lis_Pair l;
    while (!qup.empty()) {
        l.push_back(qup.top());
        qup.pop();
    }
    for (auto i : l) {
        qup.push(i);
    }
    Pair min = *l.begin(), max;
    for (list<Pair>::iterator i = l.begin(); i != l.end(); i++) {
        if (*i > max) max = *i;
        if (*i < min) min = *i;
    }
    return min + max;
}

void more_on_sum_queue_Pair(QP& qup, Pair t) {
    Lis_Pair l;
    while (!qup.empty()) {
        l.push_back(qup.top());
        qup.pop();
    }
    for (list<Pair>::iterator i = l.begin(); i != l.end(); i++) {
        *i = *i + t;
    }
    for (auto i : l) {
        qup.push(i);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
    srand(time(NULL));
    setlocale(0, "RUS");
    try {
        list<double> l;
        list<double>::iterator li = l.begin();
        int n;
        cout << "N? "; cin >> n;
        l = make_list_double(n);
        print_list_double(l);
        cout << "Первое задание для первой задачи:\n";
        cout << "Нашли среднее арифметическое и добавили в конец списка\n";
        cout << "Среднее арифметическое: ";
        double sr = average_double(l);
        cout << sr << endl;
        l.push_back(sr);
        print_list_double(l);
        cout << "Второе задание для первой задачи:\n";
        cout << "Удаляем элементы из диапазона\n";
        double a, b;
        cout << "Левая граница: "; cin >> a;
        cout << "Правая граница: "; cin >> b;
        set_range_double(l, a, b);
        print_list_double(l);
        cout << "Третье задание для первой задачи:\n";
        cout << "Посчитали сумму максимального и минимального элементов: ";
        double sum = min_max_double(l);
        cout << sum << endl;
        cout << "Прибавили сумму ко всем элементам списка\n";
        more_on_sum_double(l, sum);
        print_list_double(l);
    }
    catch (int) {
        cout << "error in double!";
    }
    try {
        list<Pair> l1;
        int n;
        cout << "N? "; cin >> n;
        l1 = make_list_Pair(n);
        print_list_Pair(l1);
        cout << "Первое задание для второй задачи:\n";
        cout << "Нашли среднее арифметическое и добавили в конец списка\n";
        cout << "Среднее арифметическое: ";
        Pair sr;
        sr = average_Pair(l1);
        cout << sr << endl;
        l1.push_back(sr);
        print_list_Pair(l1);
        cout << "Второе задание для второй задачи:\n";
        cout << "Удаляем элементы из диапазона\n";
        Pair a, b;
        cout << "Левая граница: "; cin >> a;
        cout << "Правая граница: "; cin >> b;
        set_range_Pair(l1, a, b);
        print_list_Pair(l1);
        cout << "Третье задание для второй задачи:\n";
        cout << "Посчитали сумму максимального и минимального элементов: ";
        Pair t;
        t = min_max_Pair(l1);
        cout << t;
        cout << "\nПрибавили сумму ко всем элементам списка\n";
        more_on_sum_Pair(l1, t);
        print_list_Pair(l1);
    }
    catch (int) {
        cout << "error in Pair!";
    }
    try {
        int n;
        cout << "N? "; cin >> n;
        List_T<Pair> l1(n);
        cout << l1;
        cout << "Первое задание для третьей задачи:\n";
        cout << "Нашли среднее арифметическое и добавили в конец списка\n";
        cout << "Среднее арифметическое: ";
        Pair sr;
        sr = l1.average_T(l1);
        cout << sr << endl;
        l1.pushback(sr);
        cout << l1;
        cout << "Второе задание для третьей задачи:\n";
        cout << "Удаляем элементы из диапазона\n";
        Pair a, b;
        cout << "Левая граница: "; cin >> a;
        cout << "Правая граница: "; cin >> b;
        l1.set_range_T(l1, a, b);
        cout << l1;
        cout << "Третье задание для третьей задачи:\n";
        cout << "Посчитали сумму максимального и минимального элементов: ";
        Pair sum;
        sum = l1.min_max_T(l1);
        cout << sum;
        cout << "\nПрибавили сумму ко всем элементам списка\n";
        l1.more_on_sum_T(l1, sum);
        cout << l1;
    }
    catch (int) {
        cout << "error in class T!";
    }
    try {
        int n;
        cout << "N? "; cin >> n;
        QP l1;
        l1 = make_queue_Pair(n);
        print_queue_Pair(l1);
        cout << "Первое задание для четвертой задачи:\n";
        cout << "Нашли среднее арифметическое и добавили в конец списка\n";
        cout << "Среднее арифметическое: ";
        Pair sr;
        sr = average_queue_Pair(l1);
        cout << sr << endl;
        l1.push(sr);
        print_queue_Pair(l1);
        cout << "Второе задание для четвертой задачи:\n";
        cout << "Удаляем элементы из диапазона\n";
        Pair a, b;
        cout << "Левая граница: "; cin >> a;
        cout << "Правая граница: "; cin >> b;
        set_range_queue_Pair(l1, a, b);
        print_queue_Pair(l1);
        cout << "Третье задание для четвертой задачи:\n";
        cout << "Посчитали сумму максимального и минимального элементов: ";
        Pair sum;
        sum = min_max_queue_Pair(l1);
        cout << sum;
        cout << "\nПрибавили сумму ко всем элементам списка\n";
        more_on_sum_queue_Pair(l1, sum);
        print_queue_Pair(l1);
    }
    catch (int) {
        cout << "error in queue!";
    }
    try {
        int n;
        cout << "N? "; cin >> n;
        List_T<Pair> l1;
        QP qup;
        qup = make_queue_Pair(n);
        print_queue_T(qup);
        cout << "Первое задание для пятой задачи:\n";
        cout << "Нашли среднее арифметическое и добавили в конец списка\n";
        cout << "Среднее арифметическое: ";
        Pair sr;
        sr = l1.average_queue_T(qup);
        cout << sr << endl;
        qup.push(sr);
        print_queue_T(qup);
        cout << "Второе задание для пятой задачи:\n";
        cout << "Удаляем элементы из диапазона\n";
        Pair a, b;
        cout << "Левая граница: "; cin >> a;
        cout << "Правая граница: "; cin >> b;
        l1.set_range_queue_T(qup, a, b);
        print_queue_T(qup);
        cout << "Третье задание для пятой задачи:\n";
        cout << "Посчитали сумму максимального и минимального элементов: ";
        Pair sum;
        sum = l1.min_max_queue_T(qup);
        cout << sum;
        cout << "\nПрибавили сумму ко всем элементам списка\n";
        l1.more_on_sum_queue_T(qup, sum);
        print_queue_T(qup);
    }
    catch (int) {
        cout << "error in queue and class T!";
    }
    return 0;
}

