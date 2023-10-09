#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    int t;
    cin >> t;

    TreeNode* root = nullptr;

    for (int i = 0; i < t; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    preOrderTraversal(root);
    cout << endl;

    return 0;
}
