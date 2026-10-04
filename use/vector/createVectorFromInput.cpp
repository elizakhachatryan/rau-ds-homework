#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
using namespace std;

vector<int> createVectorFromInput() {
    vector<int> v;
    int x;

    while (cin >> x && x != 0) {
        v.push_back(x);
    }
    return v;
}

int main() {
    cout << "Enter numbers (0 to stop): ";
    vector<int> v = createVectorFromInput();
    assert(v.size() == 3);
    assert(v[0] == 7);
    assert(v[1] == 8);
    assert(v[2] == 9);
    cout << "Size: " << v.size() << endl;
    cout << "Elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    cout << "All tests passed!" << endl;

    return 0;
}
