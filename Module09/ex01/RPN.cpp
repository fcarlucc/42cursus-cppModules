#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (std::isdigit(token[0]) || (token.length() == 2 && token[0] == '-' && std::isdigit(token[1]))) {

            double num = std::atof(token.c_str());
            if (num >= 10 || num <= -10) {
                throw std::runtime_error("Error");
            }
            stack.push(num);
        }
        else if (token.length() == 1) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error");
            }
            
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            
            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    if (b == 0) throw std::runtime_error("Error");
                    stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Error");
            }
        }
        else {
            throw std::runtime_error("Error");
        }
    }
    
    if (stack.size() != 1) {
        throw std::runtime_error("Error");
    }
    
    std::cout << stack.top() << std::endl;
}