#include <iostream>
#include "iter.hpp"

int main() {
	int numbers[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "Orijinal array: ";
	iter(numbers, intSize, printValue<int>);
	std::cout << std::endl;

	iter(numbers, intSize, doubleValue<int>);
	std::cout << "Doubled array: ";
	iter(numbers, intSize, printValue<int>);
	std::cout << std::endl;

	const char *words[] = {"Hello", "World", "C++", "Templates"};
	size_t wordSize = sizeof(words) / sizeof(words[0]);

	std::cout << "Words: ";
	iter(words, wordSize, printValue<const char *>);
	std::cout << std::endl;
	
	return 0;
}
