#include <iostream>
#include <string>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    void push(int data) {
        if (size >= 32) {
            std::cout << "Stack is full. Cannot push more elements." << std::endl;
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        size++;
    }

    int pop() {
        if (is_empty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return -1; // Return a sentinel value indicating an error
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }

    bool is_empty() const {
        return size == 0;
    }

    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }
};

std::string decimal_to_binary(int decimal) {
    Stack binary_stack;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary_stack.push(remainder);
        decimal /= 2;
    }

    std::string binary_representation = "";
    while (!binary_stack.is_empty()) {
        binary_representation += std::to_string(binary_stack.pop());
    }

    return binary_representation;
}

int main() {
    int decimal;
    std::cin >> decimal;

    std::string binary = decimal_to_binary(decimal);

    std::cout << "Binary representation: " << binary << std::endl;

    return 0;
}

