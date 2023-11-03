#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
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

Node* deleteNodesGreaterThanThreshold(Node* root, int threshold) {
    if (root == nullptr) {
        return nullptr;
    }

    root->left = deleteNodesGreaterThanThreshold(root->left, threshold);
    root->right = deleteNodesGreaterThanThreshold(root->right, threshold);

    if (root->data > threshold) {
        Node* temp = root;
        root = root->left ? root->left : root->right;
        delete temp;
    }

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

    int threshold;
    std::cin >> threshold;

    root = deleteNodesGreaterThanThreshold(root, threshold);
    inOrderTraversal(root);
    return 0;
}
