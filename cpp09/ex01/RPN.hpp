#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
	private:
		std::stack<float> values;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		float apply(float a, float b, const std::string& op);
		bool isValidOperand(const std::string &token);
		float calculate(const std::string &expression);
};

#endif