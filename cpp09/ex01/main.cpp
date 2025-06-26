#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Please provide a valid RPN expression" << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    RPN rpn;

    float result = rpn.calculate(expression);
    if (result != -1) {
        std::cout << result << std::endl;
    }

    return 0;
}
