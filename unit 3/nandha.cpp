#include <iostream>

using namespace std;

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
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int getTop() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    Stack stack;
    int n, element;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> element;
        stack.push(element);
    }

    stack.display();
    int topElement = stack.getTop();
    if (topElement != -1) {
        cout << "Top element is " << topElement << endl;
    }

    stack.pop();
    stack.display();
    topElement = stack.getTop();
    if (topElement != -1) {
        cout << "Top element is " << topElement << endl;
    } 
    return 0;
}

// only 1 test case is failed