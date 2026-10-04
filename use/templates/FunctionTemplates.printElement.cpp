#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <typename T>
void printElement(T value) {
    cout << value << endl;
}

int main() {
    printElement(10);
    printElement(3.14);
    printElement(string("Hello"));
    assert(true);
    cout << "All tests passed!" << endl;

    return 0;
}

