#include <iostream>
#include "List.h"
#include "List3.h"
#include "Error.h"
using namespace std;

int main()
{
    //первый метод
    //--------------------------------------
    /*try {
        List x(2);
        List y;
        cout << x;
        cout << "\nNumber? ";
        int i;
        cin >> i;
        cout << x[i] << endl;
        x.pushfront(45);
        cout << x << endl;
        x.popback();
        cout << x << endl;
        x.popback();
        cout << x << endl;
        x.popback();
    }
    catch(int) {
        cout << "***ERROR***\n";
    }*/
    //--------------------------------------
    //второй метод
    try {
        List3 x(2);
        int y;
        setlocale(0, "RUS");
        cout << x << endl;
        //cout << "Number? ";
        //int i;
        //cin >> i;
        //cout << x[i] << endl;
        //y = x + 3;
        //cout << y;
        x.pushfront(555);
        cout << "После добавления\n";
        cout << x << endl;
        x.popback();
        cout << "После удаления\n";
        cout << x << endl;
        x.popback();
        cout << "После удаления\n";
        cout << x << endl;
        x.popback();
    }
    catch (Error& e) {
        e.what();
    }
    return 0;
}

