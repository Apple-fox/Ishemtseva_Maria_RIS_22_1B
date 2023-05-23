#include <iostream>
#include <set>
#include "Pair.h"
#include "Container.h"
using namespace std;
typedef multiset<double, less<int>>ms;
typedef multiset<Pair, less<Pair>> msP;
ms::iterator i;

void make_multi_double(ms& s, int n) {
    for (int j = 0; j < n; j++) {
        int a = rand() % 100;
        int b = rand() % 10 + 1;
        s.insert((double)a / b);
    }
}

void print_multi_double(ms& s) {
    for (i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
}

double average_double(ms s) {
    double sum = 0;
    int c = 0;
    for (i = s.begin(); i != s.end(); i++) {
        sum += *i;
        c++;
    }
    return (double)sum / c;
}
void set_range_double(ms& s, double a, double b) {
    int t = 0;
    ms::iterator* ab = new ms::iterator[s.size()];
    for (i = s.begin(); i != s.end(); i++) {
        if (*i >= a && *i <= b) {
            ab[t] = i;
            t++;
        }
    }
    for (int i = 0; i < t; i++) {
        s.erase(ab[i]);
    }
}
double min_max_double(ms& s) {
    double min = *s.begin(), max = *s.begin();
    for (ms::iterator i = s.begin(); i != s.end(); i++) {
        if (*i > max) max = *i;
        if (*i < min) min = *i;
    }
    return min + max;
}

ms more_on_sum_double(ms s, double sum) {
    ms res;
    for (ms::iterator i = s.begin(); i != s.end(); i++) {
        res.insert(*i + sum);
    }
    return res;
}
//========================================================================================================
msP make_multi_Pair(int n) {
    msP s;
    for (int i = 0; i < n; i++) {
        int a = rand() % 100;
        int b = rand() % 10 + 1;
        double c = (double)a / b;
        Pair t;
        t.get_first(a);
        t.get_second(c);
        s.insert(t);
    }
    return s;
}

void print_multi_Pair(msP& s) {
    for (msP::iterator i = s.begin(); i != s.end(); i++) {
        Pair t = *i;
        cout << t;
    }
}

Pair average_Pair(msP s) {
    Pair sum;
    sum.get_first(0);
    sum.get_second(0);
    int c = 0;
    for (msP::iterator i = s.begin(); i != s.end(); i++) {
        sum = sum + *i;
        c++;
    }
    sum = sum / c;
    return sum;
}

void set_range_Pair(msP& s, Pair a, Pair b) {
    msP::iterator* ab = new msP::iterator[s.size()];
    int t = 0;
    Pair e;
    for (msP::iterator i = s.begin(); i != s.end(); i++) {
        e = *i;
        cout << e;
        if (*i >= a && *i <= b) {
            ab[t] = i;
            t++;
        }
    }
    for (int i = 0; i < t; i++) {
        Pair t = *ab[i];
        cout << t << endl;
        s.erase(ab[i]);
    }
}

Pair min_max_Pair(msP& s) {
    Pair min = *s.begin(), max;
    for (msP::iterator i = s.begin(); i != s.end(); i++) {
        if (*i > max) max = *i;
        if (*i < min) min = *i;
    }
    return min + max;
}

msP more_on_sum_Pair(msP s, Pair t) {
    msP res;
    for (msP::iterator i = s.begin(); i != s.end(); i++) {
        Pair y = *i;
        res.insert(y + t);
    }
    return res;
}
//==========================================================================================================
int main(){
    srand(time(NULL));
    setlocale(0, "RUS");
    /*ms s;
    int n;
    cout << "N? "; cin >> n;
    make_multi_double(s, n);
    print_multi_double(s);
    cout << "\nПервое задание для первой задачи\n";
    cout << "Найти среднее арифметическое и добавить в конец множества\n";
    cout << "Среднее арифметическое: ";
    double sr = average_double(s);
    cout << sr << endl;
    s.insert(sr);
    cout << "Вывод множества\n";
    print_multi_double(s);
    
    cout << "\nВторое задание для первой задачи:\n";
    cout << "Удаляем элементы из диапазона\n";
    double a, b;
    cout << "Левая граница: "; cin >> a;
    cout << "Правая граница: "; cin >> b;
    set_range_double(s, a, b);
    cout << "Вывод множества\n";
    print_multi_double(s);
    
    cout << "\nТретье задание для первой задачи:\n";
    cout << "Посчитали сумму максимального и минимального элементов: ";
    double sum = min_max_double(s);
    cout << sum << endl;
    cout << "Прибавили сумму ко всем элементам множества\n";
    s = more_on_sum_double(s, sum);
    cout << "Вывод множества\n";
    print_multi_double(s);*/
    //====================================================================================================
    /*msP sP;
    int n1;
    cout << "N? "; cin >> n1;
    sP = make_multi_Pair(n1);
    print_multi_Pair(sP);
    cout << "\nПервое задание для первой задачи\n";
    cout << "Найти среднее арифметическое и добавить в конец множества\n";
    cout << "Среднее арифметическое: ";
    Pair sr1 = average_Pair(sP);
    cout << sr1 << endl;
    sP.insert(sr1);
    cout << "Вывод множества\n";
    print_multi_Pair(sP);

    cout << "\nВторое задание для первой задачи:\n";
    cout << "Удаляем элементы из диапазона\n";
    Pair a1, b1;
    cout << "Левая граница: "; cin >> a1;
    cout << "Правая граница: "; cin >> b1;
    set_range_Pair(sP, a1, b1);
    cout << "Вывод множества\n";
    print_multi_Pair(sP);

    cout << "\nТретье задание для первой задачи:\n";
    cout << "Посчитали сумму максимального и минимального элементов: ";
    Pair sum1 = min_max_Pair(sP);
    cout << sum1 << endl;
    cout << "Прибавили сумму ко всем элементам множества\n";
    sP = more_on_sum_Pair(sP, sum1);
    cout << "Вывод множества\n";
    print_multi_Pair(sP);*/
    //====================================================================================
    int n2;
    cout << "N? "; cin >> n2;
    Container<Pair> v(n2);
    v.Print();
    cout << "\nПервое задание для третьей задачи\n";
    cout << "Найти среднее арифметическое и добавить в конец множества\n";
    cout << "Среднее арифметическое: ";
    Pair sr1 = v.average_T();
    cout << sr1 << endl;
    v.insert_t(sr1);
    cout << "Вывод множества\n";
    v.Print();

    cout << "\nВторое задание для третьей задачи:\n";
    cout << "Удаляем элементы из диапазона\n";
    Pair a1, b1;
    cout << "Левая граница: "; cin >> a1;
    cout << "Правая граница: "; cin >> b1;
    v.set_range_T(a1, b1);
    cout << "Вывод множества\n";
    v.Print();

    cout << "\nТретье задание для третьей задачи:\n";
    cout << "Посчитали сумму максимального и минимального элементов: ";
    Pair sum1 = v.min_max_T();
    cout << sum1 << endl;
    cout << "Прибавили сумму ко всем элементам множества\n";
    v.more_on_sum_T(sum1);
    cout << "Вывод множества\n";
    v.Print();
    return 0;
}
