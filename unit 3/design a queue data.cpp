#include <iostream>

class Queue {
private:
    int size;
    int front;
    int rear;
    int* elements;

public:
    // Constructor to initialize the queue
    Queue(int capacity) {
        size = capacity;
        front = rear = -1;
        elements = new int[size];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Function to add an integer to the end of the queue (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        elements[rear] = value;
    }

    // Function to remove and print elements from the queue (Dequeue)
    void dequeueAll() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        std::cout << "Dequeuing elements: ";
        while (!isEmpty()) {
            std::cout << elements[front] << " ";
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int capacity;
    std::cin >> capacity;

    Queue queue(capacity);

    for (int i = 0; i < capacity; ++i) {
        int value;
        std::cin >> value;
        queue.enqueue(value);
    }

    queue.dequeueAll();

    return 0;
}

