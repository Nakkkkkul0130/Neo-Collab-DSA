#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void reverseQueue() {
        Node* current = front;
        Node* prev = nullptr;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        rear = front;
        front = prev;
    }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Queue queue;

    for (int i = 0; i < n; i++) {
        int position;
        cin >> position;
        queue.enqueue(position);
    }

    if (!queue.isEmpty()) {
        cout << "Queue: ";
        queue.reverseQueue();
        queue.display();
    } else {
        cout << "Queue is empty." << endl;
    }

    return 0;
}
