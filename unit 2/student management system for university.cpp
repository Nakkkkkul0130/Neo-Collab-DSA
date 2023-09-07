#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header
using namespace std;

// Structure to represent a node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to delete elements from the linked list
Node* deleteElements(Node* head, vector<int>& toDelete) {
    // Create a dummy node to serve as the header
    Node* dummy = new Node(-1);
    dummy->next = head;
    
    Node* current = dummy;
    
    while (current->next) {
        if (find(toDelete.begin(), toDelete.end(), current->next->data) != toDelete.end()) {
            // The current node's data is in the toDelete vector, so we need to delete it
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    
    // Update the head pointer and delete the dummy node
    head = dummy->next;
    delete dummy;
    
    return head;
}

// Function to reverse and print the linked list
void reverseAndPrint(Node* head) {
    vector<int> elements;
    while (head) {
        elements.push_back(head->data);
        head = head->next;
    }
    
    for (int i = elements.size() - 1; i >= 0; i--) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

int main() {
    int val;
    vector<int> elements;
    while (cin >> val && val != -1) {
        elements.push_back(val);
    }
    
    Node* head = nullptr;
    for (int i = elements.size() - 1; i >= 0; i--) {
        Node* newNode = new Node(elements[i]);
        newNode->next = head;
        head = newNode;
    }
    
    vector<int> toDelete;
    while (cin >> val && val != -1) {
        toDelete.push_back(val);
    }
    
    head = deleteElements(head, toDelete);
    
    reverseAndPrint(head);
    
    // Clean up memory by deleting the remaining nodes
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
