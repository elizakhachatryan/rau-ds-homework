#include <iostream>
#include <algorithm>
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

void mirrorTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    mirrorTree(root);
    cout << "Mirror tree: ";
    preorder(root);

    return 0;
}
