#include <iostream>
#include "windows.h"

using namespace std;

class Int{
    long double value;

public:
    Int() {value = 0;}
    Int(long double val) : value(val){}

    long double getValue(){
        return value;
    }

    Int operator=(Int ob2);
    Int operator+(Int ob2);
    Int operator-(Int ob2);
    Int operator/(Int ob2);
    Int operator*(Int ob2);
    Int operator++();
    Int operator++(int notused);
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        long double first, second;
        cout << "enter first num: ";
        cin >> first;
        if (first > 2147483648 or first < -2147483648){
            throw "введенное значение выходит за границы типа int.";
        }
        cout << "enter second num: ";
        cin >> second;
        if (second > 2147483648 or second < -2147483648){
            throw "введенное значение выходит за границы типа int.";
        }

        Int first_number = first, second_num = second;
        Int sum, difference, product, quotient;
        sum = first_number + second_num;
        if (sum.getValue() > 2147483648 or sum.getValue() < -2147483648){
            throw "введенное значение выходит за границы типа int.";
        }
        cout << "My numbers sum = " << sum.getValue() << endl;

        difference = first_number - second_num;
        if (difference.getValue() > 2147483648 or difference.getValue() < -2147483648){
            throw "введенное значение выходит за границы типа int.";
        }
        cout << "My numbers difference = " << difference.getValue() << endl;

        product = first_number * second_num;
        if (product.getValue() > 2147483648 or product.getValue() < -2147483648){
            throw "введенное значение выходит за границы типа int.";
        }
        cout << "My numbers product = " << product.getValue() << endl;

        quotient = first_number / second_num;
        if (quotient.getValue() > 2147483648 or quotient.getValue() < -2147483648){
            throw "введенное значение выходит за границы типа int.";
        }
        cout << "My numbers quotient = " << quotient.getValue() << endl;

        Int f, s;
        f = first_number++;
        if (first_number.getValue() > 2147483648 or first_number.getValue() < -2147483648){
            throw "введенное значение выходит за границы типа int.";
        }
        cout << "number postincrement (num++) = " << f.getValue() << endl;

        s = ++first_number;
        if (first_number.getValue() > 2147483648 or first_number.getValue() < -2147483648){
            throw "введенное значение выходит за границы типа int.";
        }
        cout << "number preincrement (++num) = " << s.getValue() << endl;
    }
    catch (const char* errorMessage){
        std::cerr << "Ошибка: " << errorMessage << endl;
    }

    return 0;
}


Int Int :: operator=(Int ob2){
    value = ob2.value;
    return *this;
}


Int Int :: operator+(Int ob2){
    Int temp_ob;
    temp_ob.value = value + ob2.value;
    return temp_ob;
}


Int Int :: operator-(Int ob2){
    Int temp_ob;
    temp_ob.value = value - ob2.value;
    return temp_ob;
}


Int Int :: operator/(Int ob2){
    Int temp_ob;
    temp_ob.value = value / ob2.value;
    return temp_ob;
}


Int Int :: operator*(Int ob2){
    Int temp_ob;
    temp_ob.value = value * ob2.value;
    return temp_ob;
}


Int Int :: operator++(){
    value++;
    return *this;
}


Int Int :: operator++(int notused){
    Int temp_ob = *this;
    value++;
    return temp_ob;
}
