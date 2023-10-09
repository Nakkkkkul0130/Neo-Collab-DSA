#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructBinaryTree(const vector<int>& arr, int index, int n) {
    if (index >= n || arr[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[index]);
    root->left = constructBinaryTree(arr, 2 * index + 1, n);
    root->right = constructBinaryTree(arr, 2 * index + 2, n);

    return root;
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    TreeNode* root = constructBinaryTree(arr, 0, n);

    
    postorderTraversal(root);
    cout << endl;

    return 0;
}
