#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
vector<int> mergeSortedVectors(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    int i = 0;
    int j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            result.push_back(v1[i]);
            i++;
        } else {
            result.push_back(v2[j]);
            j++;
        }
    }
    while (i < v1.size()) {
        result.push_back(v1[i]);
        i++;
    }
    while (j < v2.size()) {
        result.push_back(v2[j]);
        j++;
    }
    return result;
}

int main() {
    vector<int> v1 = {1, 3, 5, 7};
    vector<int> v2 = {2, 4, 6, 8, 9};
    vector<int> result = mergeSortedVectors(v1, v2);
    assert(result.size() == 9);
    for (int i = 0; i < 9; i++) {
        assert(result[i] == i + 1);
    }
    vector<int> empty;
    vector<int> v3 = {1, 2, 3};
    result = mergeSortedVectors(empty, v3);
    assert(result.size() == 3);
    assert(result[0] == 1);
    assert(result[1] == 2);
    assert(result[2] == 3);
    result = mergeSortedVectors(empty, empty);
    assert(result.empty());
    cout << "All tests passed!" << endl;

    return 0;
}

