#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

class fraction{
    double chislo;
    string name;

public:
    fraction() {chislo = 0;}
    fraction(double x): chislo(x){}

    fraction operator++();
    fraction operator++(int notused);

    fraction operator +(fraction ob2);
    fraction operator +(int chislo2);

    fraction operator -(fraction ob2);
    fraction operator -(int chislo2);

    fraction operator *(fraction ob2);
    fraction operator *(int chislo2);

    fraction operator /(fraction ob2);
    fraction operator /(int chislo2);

    double getChislo(){
        return chislo;
    }

};


int main() {
    SetConsoleOutputCP(CP_UTF8);
    double first_num, second_num;
    cout << "введите значение первого объекта: ";
    cin >> first_num;
    cout << "введите значение второго объекта: ";
    cin >> second_num;
    fraction first = first_num, second = second_num;
    fraction sum, difference, product, quotient;

    sum = first + second;
    difference = first - second;
    product = first * second;
    quotient = first / second;

    cout << "sum = " << sum.getChislo() << endl;
    cout << "difference = " << difference.getChislo() << endl;
    cout << "product = " << product.getChislo() << endl;
    cout << "quotient = " << quotient.getChislo() << endl;

    sum = first + 1;
    difference = first - 1;
    product = first * 2;
    quotient = first / 1;

    cout << "sum = " << sum.getChislo() << endl;
    cout << "difference = " << difference.getChislo() << endl;
    cout << "product = " << product.getChislo() << endl;
    cout << "quotient = " << quotient.getChislo() << endl;


    return 0;
}


fraction fraction :: operator++(){
    chislo++;
    return *this;
}


fraction fraction :: operator++(int notused){
    fraction temp_ob = *this;
    chislo++;
    return temp_ob;
}


fraction fraction :: operator +(fraction ob2){
    fraction temp_ob;
    temp_ob.chislo = this->chislo + ob2.chislo;
    return temp_ob;
}

fraction fraction :: operator +(int chislo2){
    fraction temp_ob;
    temp_ob.chislo = this->chislo + chislo2;
    return temp_ob;
}


fraction fraction :: operator -(fraction ob2){
    fraction temp_ob;
    temp_ob.chislo = this->chislo - ob2.chislo;
    return temp_ob;
}

fraction fraction :: operator -(int chislo2){
    fraction temp_ob;
    temp_ob.chislo = this->chislo - chislo2;
    return temp_ob;
}


fraction fraction :: operator *(fraction ob2){
    fraction temp_ob;
    temp_ob.chislo = this->chislo * ob2.chislo;
    return temp_ob;
}

fraction fraction :: operator *(int chislo2){
    fraction temp_ob;
    temp_ob.chislo = this->chislo * chislo2;
    return temp_ob;
}


fraction fraction :: operator /(fraction ob2){
    fraction temp_ob;
    temp_ob.chislo = this->chislo / ob2.chislo;
    return temp_ob;
}

fraction fraction :: operator /(int chislo2){
    fraction temp_ob;
    temp_ob.chislo = this->chislo / chislo2;
    return temp_ob;
}
