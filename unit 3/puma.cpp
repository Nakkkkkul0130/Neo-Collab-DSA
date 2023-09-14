#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

bool isOperator(char c) {
    return precedence.find(c) != precedence.end();
}

string infixToPostfix(string expression) {
    stack<char> operators;
    string postfix = "";

    for (char &c : expression) {
        if (c == ' ') {
            continue; // Ignore spaces
        } else if (isdigit(c) || c == '.') {
            postfix += c; // Append operands to the postfix expression
        } else if (c == '(') {
            operators.push(c); // Push '(' onto the stack
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence[c] <= precedence[operators.top()]) {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += ' ';
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string expression;
    getline(cin, expression);

    string postfix = infixToPostfix(expression);

    cout << "The RPN is: " << postfix << endl;

    return 0;
}

