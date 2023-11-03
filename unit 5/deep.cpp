#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        if (root->data % 2 == 0) {
            std::cout << root->data << " ";
        }
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    std::cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        root = insert(root, value);
    }

    inorderTraversal(root);

    return 0;
}
