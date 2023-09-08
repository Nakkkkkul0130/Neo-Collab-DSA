#include <iostream>

using namespace std;

// Define a struct for an employee record node
struct EmployeeNode {
    int employeeID;
    EmployeeNode* next;

    EmployeeNode(int id) : employeeID(id), next(nullptr) {}
};

// Function to create a new employee record node with the given employee ID
EmployeeNode* createEmployeeNode(int id) {
    return new EmployeeNode(id);
}

// Function to print the employee list
void printEmployeeList(EmployeeNode* head) {
    EmployeeNode* current = head;
    while (current) {
        cout << current->employeeID << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to split the employee list into even and odd lists
void splitEmployeeList(EmployeeNode* head, EmployeeNode*& evenHead, EmployeeNode*& oddHead) {
    EmployeeNode* current = head->next; // Skip the header node

    EmployeeNode* evenTail = nullptr;
    EmployeeNode* oddTail = nullptr;

    while (current) {
        EmployeeNode* newNode = createEmployeeNode(current->employeeID);

        if (current->employeeID % 2 == 0) {
            // Employee ID is even
            if (!evenHead) {
                evenHead = newNode;
                evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        } else {
            // Employee ID is odd
            if (!oddHead) {
                oddHead = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        }

        current = current->next;
    }
}

int main() {
    int n;
    cin >> n;

    EmployeeNode* header = createEmployeeNode(0); // Create a header node
    EmployeeNode* current = header;

    // Build the employee linked list
    for (int i = 0; i < n; ++i) {
        int employeeID;
        cin >> employeeID;
        current->next = createEmployeeNode(employeeID);
        current = current->next;
    }

    EmployeeNode* evenHead = nullptr;
    EmployeeNode* oddHead = nullptr;

    // Split the employee list into even and odd lists
    splitEmployeeList(header, evenHead, oddHead);

    // Print the even and odd lists
    cout << "Even List: ";
    printEmployeeList(evenHead);

    cout << "Odd List: ";
    printEmployeeList(oddHead);

    // Free memory
    current = header;
    while (current) {
        EmployeeNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

