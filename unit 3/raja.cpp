#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> operands;

    for (char &c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0'); // Convert char to int and push onto the stack
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    string expression;
    cin >> expression;

    int result = evaluatePostfix(expression);

    cout << result << endl;

    return 0;
}

