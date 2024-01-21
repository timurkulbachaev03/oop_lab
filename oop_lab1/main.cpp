#include <iostream>
#include "windows.h"
#include "math.h"
#include <cmath>

using namespace std;

double power(double n, int d=2);

double power(char some_sym, int d = 2){
    return pow(static_cast<double>(some_sym)    , d);
}

int power(int some_number, int d = 2){
    int res = some_number;
    for(int i = 1; i < d; i++){
        res = res * some_number;
    }
    return res;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // task 1 start
    double some_num;
    while (true){
        cout << "Введите какое-то число: ";
        if (cin >> some_num) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Надо вводить вещественное число." << endl;
        }
    }

    int degree;
    while (true){
        cout << "Введите стпень (число большее 2) = ";
        if (cin >> degree) {
            if(degree < 2)
                cout << "Степень числа должна быть больше двух." << endl;
            else
                break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Надо вводить вещественное число." << endl;
        }
    }

    cout << some_num << " ** " << degree << " = " << power(some_num, degree) << endl;

    //task1 end

    //task2 start
    char symbol;

    while (true){
        cout << "Введите какой нибудь символ: ";
        if (cin >> symbol) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Надо вводить только один символ число." << endl;
        }
    }

    int degree_sym;
    while (true){
        cout << "Введите стпень (число большее 2) = ";
        if (cin >> degree_sym) {
            if(degree_sym < 2)
                cout << "Степень числа должна быть больше двух." << endl;
            else
                break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Надо вводить вещественное число." << endl;
        }
    }


    cout << symbol << "( " << static_cast<double>(symbol) << " ) ** ";
    cout << degree_sym << " = " << power(symbol, degree_sym) << endl;

    int third_variable = 10, third_degree = 4;
    cout << third_variable << " ** " << third_degree << " = " << power(third_variable, third_degree);

    // task2 end


    // task3 start

    


    return 0;
}

double power(double n, int d){
    double res = n;
    for(int i = 1; i < d; i++){
        res = res * n;
    }
    return res;
}


