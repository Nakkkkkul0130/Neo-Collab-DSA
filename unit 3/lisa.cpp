#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> stackA;
    
    // Push elements onto stack A
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        stackA.push(value);
    }
    
    // Output elements in stack A (original order)
    cout << "Stack A elements: ";
    stack<int> stackB; // Create an empty stack for stackB
    while (!stackA.empty()) {
        cout << stackA.top() << " ";
        stackB.push(stackA.top()); // Push elements to stackB in reverse order
        stackA.pop();
    }
    cout << endl;
    
    // Output elements in Stack B (reversed order)
    cout << "Elements in Stack B (reversed): ";
    while (!stackB.empty()) {
        cout << stackB.top() << " ";
        stackB.pop();
    }
    cout << endl;
    
    return 0;
}
