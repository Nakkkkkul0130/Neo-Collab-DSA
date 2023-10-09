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

int postorderTraversal(TreeNode* root, int& height) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = postorderTraversal(root->left, height);
    int rightHeight = postorderTraversal(root->right, height);

    height = max(leftHeight, rightHeight) + 1;

    cout << root->val << " ";
    return height;
}

int main() {
    int n;
    cin >> n;

    int height = 0;
    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "Post-order traversal: ";
    postorderTraversal(root, height);
    cout << endl << "Height of the tree: " << height - 1 << endl;

    return 0;
}
