#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other) {

		this->_numbers = other._numbers;
		this->_maxSize = other._maxSize;
	return* this;
}

Span::~Span() {}

int Span::shortestSpan() {
	if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span!");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

int Span::longestSpan() {
	if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span!");
    }

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}

void Span::addNumber(int nbr) {
	if (_numbers.size() >= _maxSize) {
        throw std::overflow_error("Span is full, cannot add more numbers!");
    }
    _numbers.push_back(nbr);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while (begin != end) {
        if (_numbers.size() >= _maxSize) {
            throw std::overflow_error("Span is full, cannot add more numbers!");
        }
        _numbers.push_back(*begin);
        ++begin;
    }
}


