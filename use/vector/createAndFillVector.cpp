#include <iostream>
#include <vector>
using namespace std;

void createAndFillVector(int N) {
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << "\nsize = " << v.size();
    cout << "\ncapacity = " << v.capacity();
}

int main() {
    createAndFillVector(5);
}
