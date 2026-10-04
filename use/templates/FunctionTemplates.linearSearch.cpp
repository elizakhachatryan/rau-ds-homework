#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

template <typename T>
int linearSearch(const vector<T>& v, T element) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> numbers = {10, 20, 30, 20};
    assert(linearSearch(numbers, 20) == 1);
    assert(linearSearch(numbers, 50) == -1);
    vector<double> numbers2 = {1.5, 2.5, 3.5};
    assert(linearSearch(numbers2, 2.5) == 1);
    assert(linearSearch(numbers2, 5.5) == -1);
    vector<string> words = {"cat", "dog", "bird", "dog"};
    assert(linearSearch(words, string("dog")) == 1);
    assert(linearSearch(words, string("fish")) == -1);
    vector<int> empty;
    assert(linearSearch(empty, 10) == -1);
    cout << "All tests passed!" << endl;

    return 0;
}

