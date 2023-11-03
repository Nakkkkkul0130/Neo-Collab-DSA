#include <iostream>
#include <vector>

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

bool findAncestors(Node* root, int key, std::vector<int>& ancestors) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (findAncestors(root->left, key, ancestors) || findAncestors(root->right, key, ancestors)) {
        ancestors.push_back(root->data);
        return true;
    }

    return false;
}

void printAncestors(Node* root, int key) {
    std::vector<int> ancestors;
    if (findAncestors(root, key, ancestors)) {
        for (int i = 0; i < ancestors.size(); i++) {
            std::cout << ancestors[i] << " ";
        }
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

    int key;
    std::cin >> key;

    printAncestors(root, key);

    return 0;
}
