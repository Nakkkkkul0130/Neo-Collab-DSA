#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val <= root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

int findSmallestGreaterValue(Node* root, int target) {
    int smallestGreater = -1;

    while (root) {
        if (root->data > target) {
            smallestGreater = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return smallestGreater;
}

int main() {
    int val;
    Node* root = nullptr;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        root = insert(root, val);
    }

    int target;
    cin >> target;

    int result = findSmallestGreaterValue(root, target);

    if (result == -1) {
        cout << "No greater value found" << endl;
    } else {
        cout << "Smallest greater value: " << result << endl;
    }

    return 0;
}
