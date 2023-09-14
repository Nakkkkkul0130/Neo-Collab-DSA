#include <iostream>

// Define a Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Define a Queue class using a linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to enqueue an order
    void enqueue(int order) {
        Node* newNode = new Node(order);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue an order
    int dequeue() {
        if (isEmpty()) {
            return -1; // Return a special value to indicate an empty queue
        }
        int order = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return order;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to compare two queues for equality
    bool isEqual(Queue& otherQueue) {
        Node* current1 = front;
        Node* current2 = otherQueue.front;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        // If both queues are empty at this point, they are equal
        return current1 == nullptr && current2 == nullptr;
    }
};

int main() {
    int N1, N2;
    std::cin >> N1;

    Queue queue1;
    for (int i = 0; i < N1; ++i) {
        int order;
        std::cin >> order;
        queue1.enqueue(order);
    }

    std::cin >> N2;

    Queue queue2;
    for (int i = 0; i < N2; ++i) {
        int order;
        std::cin >> order;
        queue2.enqueue(order);
    }

    bool areEqual = queue1.isEqual(queue2);

    if (areEqual) {
        std::cout << "The queues have the same elements in the same order." << std::endl;
    } else {
        std::cout << "The queues do not have the same elements in the same order." << std::endl;
    }

    return 0;
}

