
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->val << " "; 

    preOrderTraversal(root->left); 

    preOrderTraversal(root->right); 
}

int main() {
    int N;
    cin >> N;

    TreeNode* root = nullptr;

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;

       
        TreeNode* newNode = new TreeNode(value);

        if (root == nullptr) {
            root = newNode; t
        } else {
            TreeNode* current = root;
            while (true) {
               
                if (value < current->val) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    
    preOrderTraversal(root);

    return 0;
}
