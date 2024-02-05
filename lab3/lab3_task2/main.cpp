#include <iostream>
#include <string>
#include "windows.h"
#include <cmath>

using namespace std;


class Nomenclature{
    string name;
    float cost_price;
    float wholesale_price;
    float retail_markup;
    int items_amount;
    float tax_percentage;

public:
    float calculation_income(int quantity = 1){
        float revenue;
        if(quantity > 10){
            revenue = wholesale_price * quantity;
        }
        else{
            revenue = (cost_price + retail_markup) * quantity;
        }

        return (revenue - (cost_price * quantity) - ((cost_price * tax_percentage / 100) * quantity));
    }

    void print_all_values(){
        cout << "\t\tИнформация о товаре" << endl;
        cout << "Название товара: " << name << endl;
        cout << "Себестоимость: " << cost_price << endl;
        cout << "Оптовая цена: " << wholesale_price << endl;
        cout << "Розничная наценка: " << retail_markup << endl;
        cout << "Процент налогов = " << tax_percentage << "%" << endl;
        cout << "Количество товаров на складе: " << items_amount << endl;
    }

    Nomenclature(){
        cout << "Введите название товара: ";
        getline(cin, name);

        while (true){
            cout << "Введите себестоимость товара: ";
            if (cin >> cost_price) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Надо вводить число." << endl;
            }
        }

        while (true){
            cout << "Введите оптовую цену товара: ";
            if (cin >> wholesale_price) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Надо вводить число." << endl;
            }
        }

        while (true){
            cout << "Введите розничную наценку товара: ";
            if (cin >> retail_markup) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Надо вводить число." << endl;
            }
        }

        while (true){
            cout << "Введите процент налогов: ";
            if (cin >> tax_percentage) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Надо вводить число." << endl;
            }
        }

        while (true){
            cout << "Введите количество товаров на складе: ";
            if (cin >> items_amount) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Надо вводить число." << endl;
            }
        }
    }

    void sell(int quantity){
        if (items_amount > quantity)
            items_amount -= quantity;
        else
            cout << "Не хватает товаров! \n Количество на складе: " << items_amount << endl;
    }

    ~Nomenclature(){
        cout << "Товар " << name << " удален." << endl;
    }

};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Nomenclature shoes;
    while(true) {
        cout << "Подсчет возможного дохода - 1\tПродажа товара - 2\tПолучить список - 3\tВыйти-4" << endl;
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
                int temp;
                cout << "Введите количество: ";
                cin >> temp;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Возможный чистый доход = " << shoes.calculation_income(temp) << endl;
                break;
            case 2:
                int temp1;
                cout << "Введите количество: ";
                cin >> temp1;
                shoes.sell(temp1);
                break;
            case 3:
                shoes.print_all_values();
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

