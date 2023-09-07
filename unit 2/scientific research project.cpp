#include <iostream>
using namespace std;

// Structure to represent a node in the circular linked list
struct Node {
    float data;
    Node* next;

    Node(float val) : data(val), next(nullptr) {}
};

// Function to insert a new experimental data value at the end of the list
void insertAtEnd(Node*& header, float value) {
    Node* newNode = new Node(value);
    
    if (!header) {
        // If the list is empty, make the new node point to itself
        newNode->next = newNode;
        header = newNode; // Set the header to the new node
    } else {
        newNode->next = header->next; // New node points to the first node
        header->next = newNode; // Header points to the new node
        header = newNode; // Update the header to the new last node
    }
}

// Function to display the circular linked list
void display(Node* header) {
    if (!header) {
        cout << "Linked List is empty." << endl;
        return;
    }

    Node* current = header->next;

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != header->next);

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* header = nullptr;

    for (int i = 0; i < n; i++) {
        float value;
        cin >> value;
        insertAtEnd(header, value);
    }

    display(header);

    // Clean up memory by deleting the nodes
    if (header) {
        Node* current = header;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != header);
    }

    return 0;
}

