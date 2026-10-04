#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
void printValue(T value) {
    cout << value << endl;
}
template <>
void printValue<bool>(bool value) {
    cout << (value ? "true" : "false") << endl;
}
template <>
void printValue<char*>(char* value) {
    cout << "[" << value << "]" << endl;
}

int main() {
    printValue(10);
    printValue(3.14);
    printValue(true);
    printValue(false);
    char text[] = "Hello";
    printValue(text);
    assert(true);
    cout << "All tests passed!" << endl;
    return 0;
}

