#include <iostream>
#include "windows.h"
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

class Student {
    static int nextId;
    int id;
    string fullname;
    string birthdate;
    string phone;
    string group_name;

public:
    Student() {
        id = nextId++;
    }
    int getID() {
        return id;
    }
    string getPhone(){
        return phone;
    }
    string getFullname(){
        return fullname;
    };
    bool is_valid() const {
        return !fullname.empty();
    }

    void print_values();
    void enter_values();
};
int Student::nextId = 1;
bool compareByDestination(Student& a, Student& b) {
    return a.getFullname() < b.getFullname();
}


void search_by_phone(Student* object, size_t &size);
void add_newStudent(Student*& mas, size_t &size);
void print_all_object(Student* mas, size_t& size);
void delete_student(Student*& object, size_t &size);


int main() {
    SetConsoleOutputCP(CP_UTF8);
    size_t size = 0;
    Student *pi_one;
    pi_one = new Student[size];

    while(true){
        cout << "Новый студент-1\tУдалить студента-2\tНайти студента-3\tПолучить список-4";
        cout << "\tСортировка-5\tВыйти-6" << endl;
        cout << "Сделайте выбор: ";

        int choice;
        while (true){
            if (cin >> choice) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Надо вводить целое число. [1, 6]." << endl;
            }
        }
        bool end = false;
        switch(choice){
            case 1:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                add_newStudent(pi_one, size);
                break;
            case 2:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                delete_student(pi_one, size);
                break;
            case 3:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                search_by_phone(pi_one, size);
                break;
            case 4:
                print_all_object(pi_one, size);
                break;
            case 5:
                sort(pi_one, pi_one + size, compareByDestination);
                break;
            case 6:
                end = true;
                break;
            default:
                cout << "Нет такого варианта!!!" << endl;
                break;
        }
        if (end) {
            break;
        }
    }

    delete [] pi_one;
    return 0;
}


void Student::print_values() {
    cout << endl;
    cout << "ID: " << id << endl;
    cout << "ФИО студента: " << fullname << endl;
    cout << "Дата рождения: " << birthdate << endl;
    cout << "Номер телефона: " << phone << endl;
    cout << "Название группы: " << group_name << endl;
}


void Student::enter_values() {
    cout << "Введите ФИО студента: "; getline(cin, fullname);
    cout << "Введите Дата рождения: "; getline(cin, birthdate);
    cout << "Введите Номер телефона: "; getline(cin, phone);
    cout << "Введите Название группы: "; getline(cin, group_name);
    cout << endl;
}


void search_by_phone(Student* object, size_t& size){
    if(size == 0){
        cout << "В массиве нет объектов!!!" << endl;
        return;
    }
    string phone_number;
    cout << "Введите номер телефона: ";
    getline(cin, phone_number);

    for(int i = 0; object[i].is_valid(); i++){
        if(object[i].getPhone() == phone_number){
            cout << "Student found: " << endl;
            object[i].print_values();
            break;
        }
    }
}


void add_newStudent(Student*& mas, size_t &size){
    Student *new_pi_one = new Student[size+1];
    for(size_t i = 0; i < size; i++){
        new_pi_one[i] = mas[i];
    }
    size++;
    cout << endl << "Текущая длина массива = " << size << endl;
    new_pi_one[size - 1].enter_values();

    delete [] mas;
    mas = new_pi_one;
}


void print_all_object(Student* mas, size_t& size){
    if(size == 0){
        cout << "В массиве нет объектов!!!" << endl;
        return;
    }
    for(size_t i = 0; i < size; i++){
        mas[i].print_values();
    }
    cout << endl;
}


void delete_student(Student*& object, size_t &size){
    if(size == 0){
        cout << "В массиве нет объектов!!!" << endl;
        return;
    }
    string student_name;
    cout << "Введите ФИО студента для удалния: ";
    getline(cin, student_name);

    cout << "size = " << size << endl;

    for(size_t i = 0; i < size; i++) {
        if (object[i].getFullname() == student_name) {
            size_t index_to_remove = i;
            Student *new_pi_one = new Student[size - 1];

            for (size_t t = 0, j = 0; t < size; ++t) {
                if (t != index_to_remove) {
                    new_pi_one[j++] = object[t];
                }
            }

            delete[] object;
            object = new_pi_one;
            size--;
            cout << "выход из delete!" << endl;
        }
    }
}
