#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
void resizeVector(vector<T>& v, int newSize, T defaultValue) {
    cout << "Before: ";
    for (T x : v) {
        cout << x << " ";
    }
    cout << endl;
    v.resize(newSize, defaultValue);
    cout << "After: ";
    for (T x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3};
    resizeVector(v, 5, 42);
    assert(v.size() == 5);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
    assert(v[3] == 42);
    assert(v[4] == 42);
    resizeVector(v, 2, 100);
    assert(v.size() == 2);
    assert(v[0] == 1);
    assert(v[1] == 2);

    cout << "All tests passed!" << endl;

    return 0;
}

