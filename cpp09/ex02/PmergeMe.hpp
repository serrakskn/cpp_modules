#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    std::vector<int> generateJacobsthalSequence(int n);
    void mergeInsertionSortVector(std::vector<int> &vec);
    void mergeInsertionSortList(std::list<int> &lst);
    void binaryInsertion(std::vector<int> &sorted, int value);
    void binaryInsertion(std::list<int> &sorted, int value);
    void printContainer(const std::vector<int> &vec);
    void printContainer(const std::list<int> &lst);
};

#endif
