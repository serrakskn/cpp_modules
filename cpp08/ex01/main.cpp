#include "Span.hpp"

int main()
{
	try{

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	Span sp1 = Span(5);
	std::vector<int> values;

	values.push_back(20);
	values.push_back(1);
	values.push_back(5);

	sp1.addNumbers(values.begin(), values.end());

	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}