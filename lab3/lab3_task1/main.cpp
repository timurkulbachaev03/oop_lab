#include <iostream>
#include <string>
#include "windows.h"
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;


class MyTimer{
    int seconds;

public:
    MyTimer(int ent_second){
        seconds = ent_second;
    }

    MyTimer(string &ent_txt){
        int sec;
        istringstream isd(ent_txt);
        isd >> sec;
        seconds = sec;
    }

    MyTimer(string &ent_txt_first, string &ent_txt_second){
        int sec, min;
        istringstream iss(ent_txt_first);
        iss >> min;
        istringstream isd(ent_txt_second);
        isd >> sec;
        sec += min * 60;
        seconds = sec;
    }
    int getSecond(){
        return seconds;
    }

    void run() {
        while (seconds > 0) {
            cout << "Осталось времени: " << seconds << " секунд." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            seconds--;
        }

        cout << "Звонок! Таймер истек." << endl;
    }
};



int main() {
    SetConsoleOutputCP(CP_UTF8);
    MyTimer obj(15);
    cout << "Секунды: " << obj.getSecond() << endl;
    obj.run();
    return 0;
}
