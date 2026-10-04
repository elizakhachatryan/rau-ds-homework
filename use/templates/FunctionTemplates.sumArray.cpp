#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <typename T>
T sumArray(T* arr, int size) {
    T sum = T();
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }

    return sum;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    assert(sumArray(numbers, 5) == 15);
    double numbers2[] = {1.5, 2.5, 3.0};
    assert(sumArray(numbers2, 3) == 7.0);
    string words[] = {"Hello", " ", "World"};
    assert(sumArray(words, 3) == "Hello World");
    int empty[] = {};
    assert(sumArray(empty, 0) == 0);
    cout << "All tests passed!" << endl;

    return 0;
}
