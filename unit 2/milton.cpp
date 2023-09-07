#include <iostream>
using namespace std;

// Structure to represent a node in the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to check if the circular linked list is sorted in non-decreasing order
bool isSorted(Node* head) {
    if (!head) {
        return true; // An empty list is considered sorted
    }

    Node* current = head;
    do {
        if (current->data > current->next->data) {
            return false; // If a decreasing element is found, the list is not sorted
        }
        current = current->next;
    } while (current->next != head);

    return true; // If no decreasing elements are found, the list is sorted
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Circular reference
        } else {
            tail->next = newNode;
            tail = newNode;
            newNode->next = head; // Circular reference
        }
    }

    if (isSorted(head)) {
        cout << "The list is sorted in non-decreasing order." << endl;
    } else {
        cout << "The list is not sorted in non-decreasing order." << endl;
    }

    // Clean up memory by deleting the nodes
    if (head) {
        Node* current = head;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }

    return 0;
}

