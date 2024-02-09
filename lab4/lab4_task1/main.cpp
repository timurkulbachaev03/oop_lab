#include <iostream>
#include <string>
#include <cmath>
#include "windows.h"

using namespace std;

class Tatra;


class Kamaz {
public:
    Kamaz(float speed_plain) : speed_plain(speed_plain) {}
    friend int FrCreater(Kamaz &kamaz, Tatra &tatra, int choice);
    void enter_values(){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Навание: ";
        getline(cin, name);
        cout << "Скорость по горам: ";
        cin >> speed_mountain;
        cout << "Скорость по пустыне: ";
        cin >> speed_desert;
    }
    void getName(){
        cout << name << endl;
    }

private:
    float speed_plain;
    float speed_mountain;
    float speed_desert;
    string name;
};


class Tatra {
public:
    Tatra(float speed_plain) : speed_plain(speed_plain) {}
    void enter_values(){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Навание: ";
        getline(cin, name);
        cout << "Скорость по горам: ";
        cin >> speed_mountain;
        cout << "Скорость по пустыне: ";
        cin >> speed_desert;
    }
    friend int FrCreater(Kamaz &kamaz, Tatra &tatra, int choice);
    void getName(){
        cout << name << endl;
    }

private:
    float speed_plain;
    float speed_mountain;
    float speed_desert;
    string name;
};

int FrCreater(Kamaz &kamaz, Tatra &tatra, int choice);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Kamaz kamaz(100);
    Tatra tatra(90);
    kamaz.enter_values();
    tatra.enter_values();

    while (true) {
        cout << "По равнине - 1 \t По горам - 2 \t По пустыне - 3 \t Выйти-4" << endl;
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
        if(choice >= 4){
            break;
        }

        int winner = FrCreater(kamaz, tatra, choice);
        if (winner == 1){
            cout << "Быстрее: ";
            kamaz.getName();
        }
        else if (winner == 0){
            cout << "Скорость одинакова" << endl;
        }
        else{
            cout << "Быстрее: ";
            tatra.getName();
        }

    }

    return 0;
}


int FrCreater(Kamaz &kamaz, Tatra &tatra, int choice) {
    switch (choice) {
        case 1:
            if (kamaz.speed_plain > tatra.speed_plain)
                return 1;
            else if (kamaz.speed_plain == tatra.speed_plain)
                return 0;
            else
                return -1;
            break;

        case 2:
            if (kamaz.speed_mountain > tatra.speed_mountain)
                return 1;
            else if (kamaz.speed_mountain == tatra.speed_mountain)
                return 0;
            else
                return -1;
            break;

        case 3:
            if (kamaz.speed_desert > tatra.speed_desert)
                return 1;
            else if (kamaz.speed_desert == tatra.speed_desert)
                return 0;
            else
                return -1;
            break;
        default:
            break;
    }
}
