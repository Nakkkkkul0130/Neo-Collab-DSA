#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
    return isalnum(c);
}

string infixToPostfix(string expression) {
    stack<char> operators;
    string postfix = "";

    for (char &c : expression) {
        if (c == ' ') {
            continue; // Ignore spaces
        } else if (isOperand(c)) {
            postfix += c; // Append operands to the postfix expression
        } else if (c == '(') {
            operators.push(c); // Push '(' onto the stack
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Clear the newline character

    for (int i = 1; i <= n; i++) {
        string expression;
        getline(cin, expression);

        // Validate the expression
        bool valid = true;
        stack<char> parentheses;
        for (char c : expression) {
            if (c == '(') {
                parentheses.push(c);
            } else if (c == ')') {
                if (parentheses.empty() || parentheses.top() != '(') {
                    valid = false;
                    break;
                }
                parentheses.pop();
            }
        }
        if (!parentheses.empty() || !valid) {
            cout << "Invalid expression" << endl;
            continue;
        }

        // Convert and print the postfix expression
        string postfix = infixToPostfix(expression);
        cout << "Postfix expression " << i << ": " << postfix << endl;
    }

    return 0;
}

