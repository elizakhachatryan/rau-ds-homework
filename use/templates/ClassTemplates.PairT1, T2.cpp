#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b) {
        first = a;
        second = b;
    }
    void print() {
        cout << first << " " << second << endl;
    }
    T1 getFirst() {
        return first;
    }
    T2 getSecond() {
        return second;
    }
};

int main() {
    Pair<int, string> p(10, "Hello");
    assert(p.getFirst() == 10);
    assert(p.getSecond() == "Hello");
    Pair<double, int> p2(3.14, 5);
    assert(p2.getFirst() == 3.14);
    assert(p2.getSecond() == 5);
    p.print();
    p2.print();
    cout << "All tests passed!" << endl;
    return 0;
}

