#include <iostream>
#include <string>

using namespace std;

// Define a struct for a singly linked list node
struct ListNode {
    string data;
    ListNode* next;

    ListNode(const string& val) : data(val), next(nullptr) {}
};

// Function to create a singly linked list
ListNode* createLinkedList(int n) {
    if (n <= 0) {
        return nullptr;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        string value;
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to delete the last node of a singly linked list
ListNode* deleteLastNode(ListNode* head) {
    if (!head || !head->next) {
        // If the list is empty or has only one node, return nullptr
        return nullptr;
    }

    ListNode* current = head;
    while (current->next->next) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;

    return head;
}

// Function to print the modified linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = createLinkedList(n);

    head = deleteLastNode(head);

    printLinkedList(head);

    // Free memory for the remaining nodes
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

