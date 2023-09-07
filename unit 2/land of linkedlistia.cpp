#include <iostream>
using namespace std;

// Structure to represent a node in the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new node at the end of the circular linked list
Node* insertAtEnd(Node* header, int value) {
    Node* newNode = new Node(value);

    if (!header) {
        // If the list is empty, make the new node point to itself
        newNode->next = newNode;
        return newNode; // Return the new header
    } else {
        newNode->next = header->next; // New node points to the first node
        header->next = newNode; // Header points to the new node
        return newNode; // Return the updated header
    }
}

// Function to display the circular linked list
void display(Node* header) {
    if (!header) {
        return;
    }

    Node* current = header->next;
    bool firstElement = true;

    do {
        if (!firstElement) {
            cout << " ";
        }
        cout << current->data;
        firstElement = false;
        current = current->next;
    } while (current != header->next);

    cout << endl;
}

// Function to perform pairwise swapping of adjacent elements
Node* pairwiseSwap(Node* header) {
    if (!header || header->next == header) {
        return header; // No elements or only one element, no need to swap
    }

    Node* current = header->next;
    Node* prev = header;

    do {
        Node* nextNode = current->next;
        Node* nextPair = nextNode->next;

        prev->next = nextNode;
        nextNode->next = current;
        current->next = nextPair;

        prev = current;
        current = nextPair;

    } while (current != header->next && current->next != header->next);

    return header; // Return the new header
}

int main() {
    int n;
    cin >> n;

    Node* header = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        header = insertAtEnd(header, value);
    }

    cout << "Original linked list: ";
    display(header);

    header = pairwiseSwap(header);

    cout << "Linked list after pairwise swapping: ";
    display(header);

    return 0;
}
