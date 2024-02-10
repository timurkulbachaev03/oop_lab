#include <iostream>
#include "windows.h"

using namespace std;

class Rectangles{
    float a, b;

public:
    Rectangles() {a = 0; b = 0;}
    Rectangles(float first_side, float second_side) {a = first_side; b = second_side;}
    Rectangles(float side_a) { a = side_a; b = 0;}

    float rect_area(float first_side, float second_side){
        return first_side * second_side;
    }

    float rect_area(float side_a){
        return side_a * side_a;
    }
    float getA() {
        return a;
    }
    float getB(){
        return b;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Rectangles test_ob(4.5, 10);
    float rectS = test_ob.rect_area(test_ob.getA(), test_ob.getB());
    cout << "rectangle S = " << rectS << "м2" << endl;

    Rectangles square(11);
    float squareS = square.rect_area(square.getA());
    cout << "square S = " <<  squareS << "м2" << endl;

    return 0;
}
