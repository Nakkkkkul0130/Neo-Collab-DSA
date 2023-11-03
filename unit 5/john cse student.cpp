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

Node* removeLeaves(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
    }
    root->left = removeLeaves(root->left);
    root->right = removeLeaves(root->right);
    return root;
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
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

    root = removeLeaves(root);

    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
    } else {
        inOrderTraversal(root);
    }

    return 0;
}
