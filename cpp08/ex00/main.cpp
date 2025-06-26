#include "easyfind.hpp"

int main() {
    int intArr[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> numbers(intArr, intArr + sizeof(intArr) / sizeof(int));

    try {
        std::vector<int>::iterator it = easyfind(numbers, 4);
        std::cout << "Found value: " << *it << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 8);
        std::cout << "Found value: " << *it << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}