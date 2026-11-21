#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int findMax(TreeNode* root) {
    if (root == nullptr) {
        return INT_MIN;
    }
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return max(root->val, max(leftMax, rightMax));
}

int findMin(TreeNode* root) {
    if (root == nullptr) {
        return INT_MAX;
    }
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return min(root->val, min(leftMin, rightMin));
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);

    int maxVal = findMax(root);
    int minVal = findMin(root);
    cout << "Maximum value: " << maxVal << endl;
    cout << "Minimum value: " << minVal;

    return 0;
}
