#include <iostream>
#include "windows.h"
#include <string>

using namespace std;

struct Employee {
    int id;
    string lastName;
    int age;
    string specialization;
    double averageSalary;
    void print_information() const {
        cout << endl;
        cout << "ID: " << id << endl;
        cout << "Фамилия: " << lastName << endl;
        cout << "Возраст: " << age << endl;
        cout << "Специализация: " << specialization << endl;
        cout << "Средний оклад: " << averageSalary << endl;
    }

    void input_information()  {
        cout << "Введите вашу фамилию: ";
        getline(cin, lastName);

        cout << "Введите возраст: ";
        cin >> age;
        cin.ignore();
        cout << "Введите вашу специализацию: ";
        getline(cin, specialization);
        id = 5;
        averageSalary = 25000;
    }

};

struct Factory {
    int id;
    string name;
    string address;
    int amountWorker;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Factory elInstruments {1, "Электроинструменты",  "Промышленная, 123", 150};
    Factory technoSteel {2, "ТехноСталь", "Строительный, 45", 135};
    Factory bioTech {2, "БиоТех", " Биологическая, 34", 200};

    Employee ivan {1, "Иванов", 33, "Инженер-конструктор", 66000};
    Employee elena {2, "Смирнова", 28, "Лаборант", 50000};
    Employee aleksandr {3, "Зайцев", 29, "Мастер по производству", 58000};
    Employee olga {4, "Загитова", 23, "Лаборант", 50000};
    Employee example;
    example.input_information();
    example.print_information();

    Employee our_employees[4] {ivan, elena, aleksandr, olga};

    for (int i = 0; i < 4; i++){
        our_employees[i].print_information();
        cout << endl;
    }

    return 0;
}


