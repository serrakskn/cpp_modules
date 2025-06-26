#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span {
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        int shortestSpan();
        int longestSpan();
        void addNumber(int nbr);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif