#include <iostream>
#include "windows.h"
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

class Aeroflot {
    static int nextId;
    int id;

public:
    int flight_number;
    string departure_point;
    string flight_destination;
    string arrival_time;
    string departure_time;
    string place_of_registration;

    Aeroflot(){
        id = nextId++;
    }
    void entering_values(){
        while (true){
            cout << "Введите номер рейса: ";
            if (cin >> flight_number) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Надо вводить целое число." << endl;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введите пункт отправления: ";
        getline(cin, departure_point);

        cout << "Введите пункт назначения: ";
        getline(cin, flight_destination);

        cout << "Введите время отправления: ";
        getline(cin, departure_time);

        cout << "Введите время прибытия: ";
        getline(cin, arrival_time);

        cout << "Введите место регистрации: ";
        getline(cin, place_of_registration);

    }

    void print_values(){
        cout << id <<"\t" << flight_number <<"\t\t" << departure_point << "\t\t"<< flight_destination <<"\t\t" << arrival_time;
        cout << "\t\t" << departure_time << "\t\t" << place_of_registration << endl;
    }

    int getId(){
        return id;
    }

};

int Aeroflot::nextId = 1;

bool compareByDestination(const Aeroflot& a, const Aeroflot& b) {
    return a.flight_destination < b.flight_destination;
}

void print_table(Aeroflot* table, size_t &size);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Aeroflot flight1;
    flight1.flight_number = 101;
    flight1.departure_point = "Bishkek";
    flight1.flight_destination = "Moscow";
    flight1.departure_time = "13:00";
    flight1.arrival_time = "17:15";
    flight1.place_of_registration = "Terminal1";

    Aeroflot flight2;
    flight2.flight_number = 102;
    flight2.departure_point = "Bishkek";
    flight2.flight_destination = "Istambul";
    flight2.departure_time = "13:10";
    flight2.arrival_time = "16:15";
    flight2.place_of_registration = "Terminal2";

    Aeroflot flight3;
    flight3.flight_number = 102;
    flight3.departure_point = "Bishkek";
    flight3.flight_destination = "Tokyo";
    flight3.departure_time = "15:00";
    flight3.arrival_time = "23:40";
    flight3.place_of_registration = "Terminal3";


//    Aeroflot example;
//    example.entering_values();
//    cout << endl;

    Aeroflot all_flights[]{flight1, flight2, flight3};
    size_t size = sizeof(all_flights) / sizeof(all_flights[0]);
    cout << "size = " << size << endl;


    if(size > 0){
        sort(all_flights, all_flights + size, compareByDestination);
        cout << "Отсортировано!" << endl;
        print_table(all_flights, size);

    }
    else{
        cout << "Ошибка!!! Нет объектов в таблице." << endl;
    }


    return 0;
}



void print_table(Aeroflot* table, size_t &size){
    cout << "ID | Номер рейса | Пункт отпарвления | Пункт назначения | Время прибытия | Время отправления | Мето регистрации" << endl;
    for(size_t i = 0; i < size; i++){
        table[i].print_values();
    }
}
