#include <iostream>
#include <vector>
using namespace std;

void workWithEmptyVector() {
    vector<int> v;
    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        cout << "size = " << v.size()
             << ", capacity = " << v.capacity() << endl;
    }
    cout << "Elements: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    workWithEmptyVector();

    return 0;
}
