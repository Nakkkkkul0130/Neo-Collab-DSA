
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
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

int sumNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    int val;
    TreeNode* root = nullptr;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }

        root = insert(root, val);
    }

    int sum = sumNodes(root);
    cout << "Sum of all nodes in the BST is " << sum << endl;

    return 0;
}

