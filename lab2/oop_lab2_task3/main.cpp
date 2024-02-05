#include <iostream>
#include "windows.h"
#include <stdexcept>
#include <iterator>
#include <typeinfo>
#include <cstring>

using namespace std;

template<typename F>
class Stack {
    struct Node {
        F value;
        Node *next;
    };
    Node *base;
public:
    Stack() : base(nullptr) {}
    ~Stack() {
        clear();
    }
    void push(const F &value) {
        base = new Node{value, base};
    }
    void pop() {
        if (isEmpty()) {
            underflow_error("stack is empty");
        }
        Node *current = base;
        base = base->next;
        delete current;
    }

    bool isEmpty() const {
        return base == nullptr;
    }

    const T &top() const {
        if (isEmpty()) {
            underflow_error("stack is empty");
        }
        return base->value;
    }
    void clear() {
        while (base != nullptr) {
            Node *current = base;
            base = base->next;
            delete current;
        }
    }

};

template <class T>
void add_to_stack(T value, Stack<float> *&fl, Stack<int> *&integer);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Stack<int> first_stack;
    Stack<float> second_stack;
    Stack<int> *first = &first_stack;
    Stack<float> *second = &second_stack;




//    int f;
//    cout << "Ведите номер вагона: ";
//    cin >> t

    add_to_stack(second, first);
    add_to_stack(second, first);

    cout << "integer vagons = " << first_stack.top() << endl;
    cout << "float vagons = " << second_stack.top() << endl;

    return 0;
}

template <class T>
void add_to_stack(T value, Stack<float> *&fl, Stack<int> *&integer){
//    T value;
//    cout << "Введите номер вагона";
//    cin >> value;
    const char *variable_type = typeid(value).name();
    if(strcmp(variable_type, "f") == 0){
        fl->push(value);
    }
    else{
        if(strcmp(variable_type, "i") == 0){
            integer->push(value);
        }
    }
    variable_type = nullptr;

}
