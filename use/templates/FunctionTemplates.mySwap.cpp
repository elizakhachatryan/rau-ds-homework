#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 10;
    int b = 20;
    mySwap(a, b);
    assert(a == 20);
    assert(b == 10);
    double x = 1.5;
    double y = 2.5;
    mySwap(x, y);
    assert(x == 2.5);
    assert(y == 1.5);
    string s1 = "Hello";
    string s2 = "World";
    mySwap(s1, s2);
    assert(s1 == "World");
    assert(s2 == "Hello");
    cout << "All tests passed!" << endl;

    return 0;
}
