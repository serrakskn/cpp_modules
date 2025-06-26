#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include "PmergeMe.hpp"
void parseInput(int argc, char* argv[], std::vector<int>& vec, std::list<int>& lst) {
    std::string fullInput;
    for (int i = 1; i < argc; ++i) {
        fullInput += std::string(argv[i]) + " ";
    }

    std::istringstream iss(fullInput);
    std::string token;

    while (iss >> token) {
        for (size_t j = 0; j < token.size(); ++j) {
            if (!std::isdigit(token[j])) {
                std::cerr << "Error" << std::endl;
                std::exit(1);
            }
        }

        std::istringstream ss(token);
        int num;
        ss >> num;

        vec.push_back(num);
        lst.push_back(num);
    }
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;
    PmergeMe pmerge;

    parseInput(argc, argv, vec, lst);

    std::cout << "Before: ";
    pmerge.printContainer(vec);

    std::clock_t startVec = std::clock();
    pmerge.mergeInsertionSortVector(vec);
    std::clock_t endVec = std::clock();
    double durationVec = double(endVec - startVec) / CLOCKS_PER_SEC;

    std::clock_t startList = std::clock();
    pmerge.mergeInsertionSortList(lst);
    std::clock_t endList = std::clock();
    double durationList = double(endList - startList) / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    pmerge.printContainer(vec);
    
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
              << durationVec * 1e6 << " us" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " 
              << durationList * 1e6 << " us" << std::endl;

    return 0;
}
