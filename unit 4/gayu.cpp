#include <iostream>
#include <vector>

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

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    int choice;
    TreeNode* root = nullptr;
    
    while (true) {
        cin >> choice;
        
        if (choice == 1) {
            int n;
            cin >> n;
            vector<int> values(n);
            for (int i = 0; i < n; i++) {
                cin >> values[i];
                root = insert(root, values[i]);
            }
            cout << "BST with " << n << " nodes is ready to use!" << endl;
        } else if (choice == 2) {
            cout << "BST Traversal in POSTORDER" << endl;
            postOrderTraversal(root);
            cout << endl;
        } else if (choice == 3) {
            break;
        } else {
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}
