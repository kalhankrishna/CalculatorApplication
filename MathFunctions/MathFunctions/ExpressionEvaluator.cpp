#include "pch.h"
#include "ExpressionEvaluator.h"
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

double applyOperator(double operand1, double operand2, char op) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0)
            return operand1 / operand2;
        else {
            return -1.0;
        }
    default:
        return 0.0;
    }
}

double evaluateExpression(const std::string& expression) {
    stack<double> operands;
    stack<char> operators;

    stringstream ss(expression);

    string token;
    bool lastWasOperator = false;       // Flag to track if the last token processed was an operator
    while (getline(ss, token, ' ')) {
        if (isdigit(token[0]) || (token[0] == '.' && token.size() > 1) || (isdigit(token[0]) && token.find('.') != string::npos)) {     // Check if token is a valid number
            double operand;
            stringstream(token) >> operand;
            operands.push(operand);
            lastWasOperator = false;        // Reset the flag since an operand was encountered
        }
        else if (isOperator(token[0])) {
            if (lastWasOperator) {
                return -1.0;
            }
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token[0])) {
                double operand2 = operands.top(); operands.pop();
                double operand1 = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                if (op == '/' && operand2 == 0) {       // Check for division by zero
                    return -1.0;
                }
                operands.push(applyOperator(operand1, operand2, op));
            }
            operators.push(token[0]);
            lastWasOperator = true;         // Set the flag since an operator was encountered
        }
        else {
            return -1.0;
        }
    }

    // For remaining remaining operations
    while (!operators.empty()) {
        double operand2 = operands.top(); operands.pop();
        double operand1 = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        if (op == '/' && operand2 == 0) {       // Check for division by zero
            return -1.0;
        }
        operands.push(applyOperator(operand1, operand2, op));
    }

    if (!operands.empty())
        return operands.top();
    else {
        return -1.0;
    }
}
