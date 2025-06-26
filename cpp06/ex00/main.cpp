#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./ScalarConverter <literal>" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    ScalarConverter::convert(input);

    return 0;
}
