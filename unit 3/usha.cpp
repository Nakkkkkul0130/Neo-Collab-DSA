#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

string infixToPostfix(string expression) {
    stack<char> operatorStack;
    string postfix = "";

    for (char &c : expression) {
        if (c == ' ') {
            continue; // Ignore spaces
        } else if (isalnum(c)) {
            postfix += c; // Append operands to the postfix expression
        } else if (c == '(') {
            operatorStack.push(c); // Push '(' onto the stack
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop '('
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string expression;
    getline(cin, expression);

    string postfix = infixToPostfix(expression);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

