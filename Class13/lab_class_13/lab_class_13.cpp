#include <iostream>
#include <list>
#include <vector>
#include "Pair.h"
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef list<Pair> Lis_Pair;
typedef priority_queue<Pair> QP;
typedef map<int, Pair> mp;
Pair sr;
Pair a, b;

struct Comp_less {
public:
    bool operator()(Pair p1, Pair p2) {
        return (p1 > p2);
    }
};
struct Sort_Range {
public:
    bool operator()(Pair p1) {
        return (p1 >= a && p1 <= b);
    }
};

struct Sum_s {
    Pair operator()(Pair p) {
        return p + sr;
    }
};
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

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        cout << t;
        l.push_back(qup.top());
        qup.pop();
    }
    for (auto i : l) {
        qup.push(i);
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

void set_range_queue_Pair(QP& qup, Pair a, Pair b) {
    Lis_Pair l;
    while (!qup.empty()) {
        l.push_back(qup.top());
        qup.pop();
    }
    l.remove_if(Sort_Range());
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

void more_on_sum_queue_Pair(QP& qup) {
    Lis_Pair l;
    while (!qup.empty()) {
        l.push_back(qup.top());
        qup.pop();
    }
    Lis_Pair res1;
    res1.resize(l.size());
    transform(l.begin(), l.end(), res1.begin(), Sum_s());
    l = res1;

    for (auto i : l) {
        qup.push(i);
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
mp make_map_Pair(int n) {
    mp ma;
    for (int i = 0; i < n; i++) {
        int a = rand() % 100;
        int b = rand() % 10 + 1;
        double c = (double)a / b;
        Pair t;
        t.get_first(a);
        t.get_second(c);
        ma[i] = t;
    }
    return ma;
}

void print_map_Pair(mp ma) {
    for (auto i : ma) {
        cout << i.second << endl;
    }
}

Pair average_map_Pair(mp ma) {
    Pair sum;
    sum.get_first(0);
    sum.get_second(0);
    int c = 0;
    for (auto i : ma) {
        sum = sum + i.second;
        c++;
    }
    sum = sum / c;
    return sum;
}

void set_range_map_Pair(mp& ma, Pair a, Pair b) {
    Sort_Range s;
    int it = 0;
    int *indexs = new int[ma.size()];
    for (auto i : ma) {
        if (s(i.second)) {
            indexs[it] = i.first;
            it++;
        }
    }
    for (int i = 0; i < it; i++) {
        ma.erase(indexs[i]);
    }
}

Pair min_max_map_Pair(mp& ma) {
    Lis_Pair l;
    Pair min = ma[0], max;
    for (auto i : ma) {
        if (i.second > max) max = i.second;
        if (i.second < min) min = i.second;
    }
    return min + max;
}
void more_on_sum_map_Pair(mp& ma, Pair t) {
    for (auto& i : ma) {
        i.second = i.second + t;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
    setlocale(0, "RUS");
    srand(time(NULL));
    //=========================================================================================
    //list<Pair> l1;
    int n;
    //cout << "N? "; cin >> n;
    //l1 = make_list_Pair(n);
    //print_list_Pair(l1);
    //Lis_Pair::iterator r;
    //r = max_element(l1.begin(), l1.end());
    //cout << "Максимальный элемент списка = " << *r;
    //Pair p = *r;
    //cout << "Первое задание для первой задачи:\n";
    //cout << "Нашли среднее арифметическое и добавили в конец списка\n";
    //cout << "Среднее арифметическое: ";
    //sr = average_Pair(l1);
    //cout << sr << endl;
    //l1.push_back(sr);
    //print_list_Pair(l1);
    ////------------------
    //cout << " Сортировка по убыванию\n";
    //l1.sort(Comp_less());
    //print_list_Pair(l1);
    //cout << "Сортировка по возрастанию\n";
    //l1.sort();
    //print_list_Pair(l1);
    ////------------------
    //cout << "Второе задание для первой задачи:\n";
    //cout << "Удаляем элементы из диапазона\n";
    ////Lis_Pair::iterator a1, b1;
    //cout << "Левая граница: "; cin >> a;
    //cout << "Правая граница: "; cin >> b;
    //l1.remove_if(Sort_Range());
    //print_list_Pair(l1);
    ////------------------
    //cout << "Третье задание для первой задачи:\n";
    //cout << "Посчитали сумму максимального и минимального элементов: ";
    //Pair t;
    //sr = (*max_element(l1.begin(), l1.end()) + *min_element(l1.begin(), l1.end()));
    //cout << sr;
    //cout << "\nПрибавили сумму ко всем элементам списка\n";
    //Lis_Pair res;
    //res.resize(l1.size());
    //transform(l1.begin(), l1.end(), res.begin(), Sum_s());
    //l1 = res;
    //print_list_Pair(l1);
    ////=====================================================================================
    //QP qup;
    //cout << "N? "; cin >> n;
    //qup = make_queue_Pair(n);
    //print_queue_Pair(qup);
    //cout << "Первое задание для второй задачи:\n";
    //cout << "Нашли среднее арифметическое и добавили в конец списка\n";
    //cout << "Среднее арифметическое: ";
    //sr = average_queue_Pair(qup);
    //cout << sr << endl;
    //qup.push(sr);
    //print_queue_Pair(qup);
    ////------------------
    //cout << "Второе задание для второй задачи:\n";
    //cout << "Удаляем элементы из диапазона\n";
    //cout << "Левая граница: "; cin >> a;
    //cout << "Правая граница: "; cin >> b;
    //set_range_queue_Pair(qup, a, b);
    //
    //print_queue_Pair(qup);
    ////------------------
    //cout << "Третье задание для второй задачи:\n";
    //cout << "Посчитали сумму максимального и минимального элементов: ";
    //sr = min_max_queue_Pair(qup);
    //cout << sr;
    //cout << "\nПрибавили сумму ко всем элементам списка\n";
    //more_on_sum_queue_Pair(qup);
    //print_queue_Pair(qup);
    ////=====================================================================================
    mp map_Pair;
    cout << "N? "; cin >> n;
    map_Pair = make_map_Pair(n);
    print_map_Pair(map_Pair);
    cout << "Первое задание для третьей задачи:\n";
    cout << "Нашли среднее арифметическое и добавили в конец списка\n";
    cout << "Среднее арифметическое: ";
    sr = average_map_Pair(map_Pair);
    cout << sr << endl;
    map_Pair[n] = sr;
    n++;
    print_map_Pair(map_Pair);
    //------------------
    cout << "Второе задание для третьей задачи:\n";
    cout << "Удаляем элементы из диапазона\n";
    cout << "Левая граница: "; cin >> a;
    cout << "Правая граница: "; cin >> b;
    set_range_map_Pair(map_Pair, a, b);

    print_map_Pair(map_Pair);
    //------------------
    cout << "Третье задание для третьей задачи:\n";//не работает!!
    cout << "Посчитали сумму максимального и минимального элементов: ";
    sr = min_max_map_Pair(map_Pair);
    cout << sr;
    cout << "\nПрибавили сумму ко всем элементам списка\n";
    more_on_sum_map_Pair(map_Pair, sr);
    print_map_Pair(map_Pair);
    return 0;
}
