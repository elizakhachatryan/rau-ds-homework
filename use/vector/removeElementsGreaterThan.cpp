#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int removeElementsGreaterThan(vector<int>& v, int limit) {
    int removed = 0;
    while (!v.empty() && v.back() > limit) {
        v.pop_back();
        removed++;
    }
    return removed;
}

int main() {
    vector<int> v = {1, 3, 5, 7, 9};
    int removed = removeElementsGreaterThan(v, 5);
    assert(removed == 2);
    assert(v.size() == 3);
    assert(v[0] == 1);
    assert(v[1] == 3);
    assert(v[2] == 5);
    vector<int> v2 = {1, 2, 3};
    removed = removeElementsGreaterThan(v2, 5);
    assert(removed == 0);
    assert(v2.size() == 3);
    vector<int> v3 = {5, 6, 7};
    removed = removeElementsGreaterThan(v3, 4);
    assert(removed == 3);
    assert(v3.empty());
    cout << "All tests passed!" << endl;

    return 0;
}
```
