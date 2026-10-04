#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Range {
private:
    T start;
    T end;

public:
    Range(T start, T end) {
        this->start = start;
        this->end = end;
    }
    bool contains(const T& value) {
        return value >= start && value <= end;
    }
    T length() {
        return end - start;
    }
    void print() {
        cout << "[" << start << ", " << end << "]" << endl;
    }
};

int main() {
    Range<int> intRange(3, 10);
    assert(intRange.contains(3));
    assert(intRange.contains(5));
    assert(intRange.contains(10));
    assert(!intRange.contains(11));
    assert(intRange.length() == 7);
    intRange.print();
    Range<double> doubleRange(1.5, 5.5);
    assert(doubleRange.contains(1.5));
    assert(doubleRange.contains(3.0));
    assert(doubleRange.contains(5.5));
    assert(!doubleRange.contains(6.0));
    assert(doubleRange.length() == 4.0);
    doubleRange.print();
    Range<char> charRange('a', 'f');
    assert(charRange.contains('a'));
    assert(charRange.contains('c'));
    assert(charRange.contains('f'));
    assert(!charRange.contains('z'));
    assert(charRange.length() == 5);
    charRange.print();
    cout << "All tests passed!" << endl;

    return 0;
}

