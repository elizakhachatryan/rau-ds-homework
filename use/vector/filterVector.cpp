#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T, typename Predicate>
vector<T> filterVector(const vector<T>& v, Predicate predicate) {
    vector<T> result;

    for (const T& element : v) {
        if (predicate(element)) {
            result.push_back(element);
        }
    }

    return result;
}
bool isEven(int x) {
    return x % 2 == 0;
}
bool isPositive(int x) {
    return x > 0;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> result = filterVector(v, isEven);
    assert(result.size() == 3);
    assert(result[0] == 2);
    assert(result[1] == 4);
    assert(result[2] == 6);
    vector<int> v2 = {2, 4, 6};
    result = filterVector(v2, isEven);
    assert(result == v2);
    vector<int> v3 = {1, 3, 5};
    result = filterVector(v3, isEven);
    assert(result.empty());
    vector<int> empty;
    result = filterVector(empty, isEven);
    assert(result.empty());
    vector<int> v4 = {-2, -1, 0, 1, 2};
    result = filterVector(v4, isPositive);
    assert(result.size() == 2);
    assert(result[0] == 1);
    assert(result[1] == 2);
    cout << "All tests passed!" << endl;

    return 0;
}
