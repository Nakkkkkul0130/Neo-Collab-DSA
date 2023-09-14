#include <iostream>
#include <stack>

using namespace std;

// Define a node structure for the linked list.
struct Node {
    int data;
    Node* next;
};

// Define a deque class that uses a linked list.
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    // Check if the deque is empty.
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert an element at the front of the deque.
    void insertFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front = newNode;
        }
    }

    // Insert an element at the rear of the deque.
    void insertRear(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Display even and odd elements separately.
    void displayEvenOdd() {
        Node* current = front;
        stack<int> oddStack;

        cout << "Even elements: ";
        while (current != nullptr) {
            if (current->data % 2 == 0) {
                cout << current->data << " ";
            } else {
                oddStack.push(current->data);
            }
            current = current->next;
        }
        cout << endl;

        cout << "Odd elements: ";
        while (!oddStack.empty()) {
            cout << oddStack.top() << " ";
            oddStack.pop();
        }
        cout << endl;
    }
};

int main() {
    Deque deque;

    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }

        if (value % 2 == 0) {
            deque.insertRear(value);
        } else {
            deque.insertFront(value);
        }
    }

    if (deque.isEmpty()) {
        cout << "Deque is empty." << endl;
    } else {
        deque.displayEvenOdd();
    }

    return 0;
}
