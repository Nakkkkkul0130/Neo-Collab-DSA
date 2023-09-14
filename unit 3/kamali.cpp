#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to insert an element in a sorted stack at its correct position
void insertSorted(stack<int>& sortedStack, int element) {
    if (sortedStack.empty() || element <= sortedStack.top()) {
        sortedStack.push(element);
        return;
    }
    
    int temp = sortedStack.top();
    sortedStack.pop();
    insertSorted(sortedStack, element);
    sortedStack.push(temp);
}

// Function to sort a stack in descending order
void sortStackDescending(stack<int>& inputStack) {
    stack<int> sortedStack;
    
    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();
        insertSorted(sortedStack, temp);
    }
    
    inputStack = sortedStack;
}

int main() {
    int n;
    cin >> n;
    
    if (n > 10) {
        cout << "Stack is full" << endl;
    } else if (n == 0) {
        cout << "Stack is empty" << endl;
    } else {
        stack<int> inputStack;
        
        for (int i = 0; i < n; ++i) {
            int element;
            cin >> element;
            inputStack.push(element);
        }
        
        stack<int> originalStack = inputStack;
        vector<int> originalElements;
        
        while (!originalStack.empty()) {
            originalElements.push_back(originalStack.top());
            originalStack.pop();
        }
        
        cout << "Original stack: ";
        for (int i = originalElements.size() - 1; i >= 0; --i) {
            cout << originalElements[i] << " ";
        }
        cout << endl;
        
        sortStackDescending(inputStack);
        
        cout << "Sorted stack: ";
        while (!inputStack.empty()) {
            cout << inputStack.top() << " ";
            inputStack.pop();
        }
        
        cout << endl;
    }
    
    return 0;
}
