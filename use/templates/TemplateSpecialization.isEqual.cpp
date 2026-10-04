#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

template <typename T>
bool isEqual(T a, T b) {
    return a == b;
}
template <>
bool isEqual<const char*>(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

int main() {
    assert(isEqual(10, 10) == true);
    assert(isEqual(10, 20) == false);
    assert(isEqual(3.14, 3.14) == true);
    assert(isEqual(3.14, 2.71) == false);
    const char* str1 = "Hello";
    const char* str2 = "Hello";
    const char* str3 = "World";
    assert(isEqual(str1, str2) == true);
    assert(isEqual(str1, str3) == false);
    cout << "All tests passed!" << endl;

    return 0;
}

