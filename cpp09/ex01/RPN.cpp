#include "RPN.hpp"
#include <sstream>
#include <string>
#include <cstdlib> 

RPN::RPN() {}

RPN::RPN(const RPN& other) { this->values = other.values; }

RPN& RPN::operator=(const RPN& other) {
	if(this != &other) {
		this->values = other.values;
	}
	return* this;
}

RPN::~RPN() {}

float RPN::apply(float a, float b, const std::string& op) {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0) {
			std::cerr << "Error: Division by zero" << std::endl;
			return -1;
		}
		return a / b;
	}
	std::cerr << "Error: Unknown operator" << std::endl;
	return -1;
}

bool RPN::isValidOperand(const std::string &token) {
	if (token.length() == 1 && token[0] >= '0' && token[0] <= '9') {
		return true;
	}
	return false;
}

float RPN::calculate(const std::string& expression) {
	std::istringstream ss(expression);
	std::string token;

	while (ss >> token) {
		if(isValidOperand(token)) {
			values.push(std::atof(token.c_str()));
		}
		else if(token == "+" || token == "-" || token == "*" || token == "/") {
			if(values.size() < 2) {
				std::cerr << "Error: Insufficient operands" << std::endl;
				return -1;
			}
			float b = values.top();
			values.pop();
			float a = values.top();
			values.pop();
			float result = apply(a, b, token);
			values.push(result);
		} else {
			std::cerr << "Error" << std::endl;
			return -1;
		}
	}
	if(values.size() == 1) {
		return values.top();
	} else {
		std::cerr << "Error: Invalid expression" << std::endl;
		return -1;
	}
}