#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <typename T, int N>
class FixedArray {
private:
    T data[N];

public:
    void set(int index, T value) {
        data[index] = value;
    }
    T get(int index) {
        return data[index];
    }
    int size() {
        return N;
    }
};

int main() {
    FixedArray<int, 5> numbers;
    numbers.set(0, 10);
    numbers.set(1, 20);
    assert(numbers.get(0) == 10);
    assert(numbers.get(1) == 20);
    assert(numbers.size() == 5);
    FixedArray<double, 3> decimals;
    decimals.set(0, 1.5);
    decimals.set(1, 2.5);
    assert(decimals.get(0) == 1.5);
    assert(decimals.get(1) == 2.5);
    assert(decimals.size() == 3);
    FixedArray<string, 2> words;
    words.set(0, "Hello");
    words.set(1, "World");
    assert(words.get(0) == "Hello");
    assert(words.get(1) == "World");
    assert(words.size() == 2);
    cout << "All tests passed!" << endl;

    return 0;
}

