#include <iostream>

using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the front of the doubly linked list
void insertAtFront(Node*& head, Node*& tail, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to delete the node at the front of the doubly linked list
void deleteAtFront(Node*& head, Node*& tail) {
    if (head == nullptr) {
        return; // List is empty, nothing to delete
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

// Function to delete the node at the end of the doubly linked list
void deleteAtEnd(Node*& head, Node*& tail) {
    if (head == nullptr) {
        return; // List is empty, nothing to delete
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

// Function to print the doubly linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int task;
        cin >> task;
        insertAtFront(head, tail, task);
    }

    // Print the initial list
    printList(head);

    // Delete the front node and print
    deleteAtFront(head, tail);
    printList(head);

    // Delete the end node and print
    deleteAtEnd(head, tail);
    printList(head);

    // Deallocate memory (free nodes)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
