#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int findSubsequence(const vector<int>& mainVec, const vector<int>& subVec) {
    if (subVec.empty()) {
        return 0;
    }
    if (subVec.size() > mainVec.size()) {
        return -1;
    }
    for (int i = 0; i <= mainVec.size() - subVec.size(); i++) {
        bool found = true;
        for (int j = 0; j < subVec.size(); j++) {
            if (mainVec[i + j] != subVec[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> mainVec = {1, 2, 3, 4, 5, 6};
    vector<int> subVec = {3, 4, 5};
    assert(findSubsequence(mainVec, subVec) == 2);
    vector<int> sub2 = {7, 8};
    assert(findSubsequence(mainVec, sub2) == -1);
    vector<int> sub3 = {1, 2};
    assert(findSubsequence(mainVec, sub3) == 0);
    vector<int> sub4 = {5};
    assert(findSubsequence(mainVec, sub4) == 4);
    vector<int> empty;
    assert(findSubsequence(mainVec, empty) == 0);
    cout << "All tests passed!" << endl;
    return 0;
}
