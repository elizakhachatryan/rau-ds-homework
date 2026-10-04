#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void manageCapacity(vector<int>& v) {
    cout << "Before:" << endl;
    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;
    v.reserve(v.size() + 500);

    for (int i = 1; i <= 500; i++) {
        v.push_back(i);
    }
    cout << "After:" << endl;
    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;
}

int main() {
    vector<int> v = {10, 20, 30};
    manageCapacity(v);
    assert(v.size() == 503);
    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);
    assert(v[3] == 1);
    assert(v[502] == 500);

    cout << "All tests passed!" << endl;

    return 0;
}
