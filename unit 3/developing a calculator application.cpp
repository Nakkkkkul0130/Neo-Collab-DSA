#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluateRPN(string expression) {
    stack<int> operands;

    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            operands.push(stoi(token)); // Convert string to integer and push onto the stack
        } else if (isOperator(token[0])) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            int result;
            switch (token[0]) {
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
    getline(cin, expression);

    int result = evaluateRPN(expression);

    cout << "The result is: " << result << endl;

    return 0;
}
