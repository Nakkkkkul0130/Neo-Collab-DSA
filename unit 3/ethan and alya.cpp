#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

class Stack {
public:
    int arr[MAX_SIZE];
    int top;

    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1; // Signifies an empty stack
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return -1; // Signifies an empty stack
    }
};

int main() {
    Stack stack;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (stack.isFull()) {
            cout << "STACK is overflow" << endl;
            cout<<"Element not found"<<endl;
            return 0;
        }
        stack.push(value);
    }

    int searchElement;
    cin >> searchElement;

    if (stack.isEmpty()) {
        cout << "The STACK is empty" << endl;
    } else {
        bool found = false;
        while (!stack.isEmpty()) {
            int element = stack.pop();
            if (element == searchElement) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Element found" << endl;
        } else {
            cout << "Element not found" << endl;
        }
    }

    return 0;
}

