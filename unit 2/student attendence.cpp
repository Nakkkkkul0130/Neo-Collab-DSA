#include <iostream>

using namespace std;

// Define a struct for a linked list node
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to create a new node with the given data
ListNode* createNode(int data) {
    return new ListNode(data);
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to delete all occurrences of a given number from the list
ListNode* deleteOccurrences(ListNode* head, int numToDelete) {
    // Create a dummy header node
    ListNode* dummy = createNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* current = head;

    while (current) {
        if (current->data == numToDelete) {
            // Remove the current node
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }

    // Update the head pointer and free the dummy node
    head = dummy->next;
    delete dummy;

    return head;
}

int main() {
    int n;
    cin >> n;

    ListNode* header = createNode(0);
    ListNode* current = header;

    // Build the linked list
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        current->next = createNode(data);
        current = current->next;
    }

    int numToDelete;
    cin >> numToDelete;

    // Print the original list
    cout << "Original List: ";
    printList(header->next);

    // Delete occurrences of the given number
    header->next = deleteOccurrences(header->next, numToDelete);

    // Print the modified list
    cout << "List after deleting all occurrences of " << numToDelete << ": ";
    printList(header->next);

    // Free memory
    current = header;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

