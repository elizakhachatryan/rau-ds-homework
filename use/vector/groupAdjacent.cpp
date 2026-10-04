#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<vector<int>> groupAdjacent(const vector<int>& v) {
    vector<vector<int>> groups;
    if (v.empty()) {
        return groups;
    }
    vector<int> currentGroup;
    for (int i = 0; i < v.size(); i++) {
        if (currentGroup.empty() || v[i] == currentGroup.back()) {
            currentGroup.push_back(v[i]);
        } else {
            groups.push_back(currentGroup);
            currentGroup.clear();
            currentGroup.push_back(v[i]);
        }
    }
    groups.push_back(currentGroup);
    return groups;
}

int main() {
    vector<int> v = {1, 1, 2, 2, 2, 3, 1, 1};
    vector<vector<int>> result = groupAdjacent(v);
    assert(result.size() == 4);
    assert(result[0] == vector<int>({1, 1}));
    assert(result[1] == vector<int>({2, 2, 2}));
    assert(result[2] == vector<int>({3}));
    assert(result[3] == vector<int>({1, 1}));
    vector<int> v2 = {5};
    result = groupAdjacent(v2);
    assert(result.size() == 1);
    assert(result[0] == vector<int>({5}));
    vector<int> empty;
    result = groupAdjacent(empty);
    assert(result.empty());
    vector<int> v3 = {7, 7, 7};
    result = groupAdjacent(v3);
    assert(result.size() == 1);
    assert(result[0] == vector<int>({7, 7, 7}));

    cout << "All tests passed!" << endl;

    return 0;
}
