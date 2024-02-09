#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "windows.h"
#include <cmath>

using namespace std;


class Soft{
    string name;
    string developer;
    float memory;
    string licenseEnd;

public:
    Soft(){
        cout << "Введите название программы: ";
        getline(cin, name);

        cout << "Введите имя разработчика: ";
        getline(cin, developer);

        while (true){
            cout << "Введите объем занимаемой памяти: ";
            if (cin >> memory) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Надо вводить число." << endl;
            }
        }
    }
    void counting_of_daysLeft();
    void set_licenseEndDate();
    void print_properties();

    ~Soft(){
        cout << "Программа " << name << " удален." << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Soft program;
        while(true) {
            cout << "Вывод свойств программы - 1\tКупить лицензию - 2\tПодсчет количества дней до завершения лицензии  - 3\tВыйти-4" << endl;
            cout << "Сделайте выбор: ";

            int choice;
            while (true) {
                if (cin >> choice) {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка ввода! Надо вводить целое число. [1, 4]." << endl;
                }
            }
            bool end = false;
        switch (choice) {
            case 1:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                program.print_properties();
                break;
            case 2:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                program.set_licenseEndDate();
                break;
            case 3:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                program.counting_of_daysLeft();
                break;
            case 4:
                end = true;
                break;
            default:
                cout << "Нет такого варианта!!!" << endl;
                break;
        }

        if(end){
            break;
        }
    }

    return 0;
}

void Soft :: counting_of_daysLeft(){
    stringstream ss(licenseEnd);
    int day, month, year;

    ss >> day;
    ss.ignore();
    ss >> month;
    ss.ignore();
    ss >> year;

    tm licenseEndDate = {};
    licenseEndDate.tm_mday = day;
    licenseEndDate.tm_mon = month - 1;
    licenseEndDate.tm_year = year - 1900;

    time_t currentTime = time(nullptr);
    tm currentDate = *localtime(&currentTime);

    time_t difference = mktime(&licenseEndDate) - mktime(&currentDate);

    int daysRemaining = difference / (60 * 60 * 24);

    cout << "Дней до окончания лицензии: " << daysRemaining << endl;
}

void Soft :: set_licenseEndDate(){
    cout << "Введите дату (dd.mm.yyyy): ";
    getline(cin, licenseEnd);
}

void Soft :: print_properties(){
    cout << "Название: " << name << endl;
    cout << "Разработчик: " << developer << endl;
    cout << "Память: " << memory << endl;
    cout << "Дата окончания лицензии " << licenseEnd << endl;
}
