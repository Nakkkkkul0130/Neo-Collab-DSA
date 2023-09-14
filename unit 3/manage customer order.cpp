#include <iostream>

class Queue {
private:
    int capacity;
    int front;
    int rear;
    int* elements;

public:
    // Constructor to initialize the queue
    Queue(int size) {
        capacity = size;
        front = rear = -1;
        elements = new int[capacity];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Function to add a customer order to the end of the queue (Enqueue)
    void enqueue(int order) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        elements[rear] = order;
    }

    // Function to retrieve the details of the first customer order in the queue (Get Front)
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1; // Return a special value to indicate an error
        }
        return elements[front];
    }

    // Function to retrieve the details of the last customer order in the queue (Get Rear)
    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No rear element." << std::endl;
            return -1; // Return a special value to indicate an error
        }
        return elements[rear];
    }
};

int main() {
    int capacity;
    std::cin >> capacity;

    Queue queue(capacity);

    for (int i = 0; i < capacity; ++i) {
        int order;
        std::cin >> order;
        queue.enqueue(order);
    }

    int front = queue.getFront();
    int rear = queue.getRear();

    if (front != -1 && rear != -1) {
        std::cout << "Front element: " << front << std::endl;
        std::cout << "Rear element: " << rear << std::endl;
    }

    return 0;
}
