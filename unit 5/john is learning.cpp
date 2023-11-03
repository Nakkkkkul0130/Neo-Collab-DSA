#include <iostream>
#include <algorithm>

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
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int getHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return std::max(leftHeight, rightHeight) + 1;
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

    int height = getHeight(root);
    std::cout << height << std::endl;

    return 0;
}
