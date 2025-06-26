#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other){
	(void)other;
	return *this;
}
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
{
    std::vector<int> jacobsthalSeq;

    if (n > 0) jacobsthalSeq.push_back(1);
    if (n > 1) jacobsthalSeq.push_back(3);

    for (int i = 2; i < n; ++i)
        jacobsthalSeq.push_back(jacobsthalSeq[i - 2] + 2 * jacobsthalSeq[i - 1]);

    return jacobsthalSeq;
}

void PmergeMe::mergeInsertionSortVector(std::vector<int> &vec)
{
	if (vec.size() < 2)
		return;

	// Step 1: Pairing and sorting within pairs
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> leftovers;
	for (unsigned int i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}
	if (vec.size() % 2 != 0)
		leftovers.push_back(vec.back());

	// Step 2: Extract larger elements and sort
	std::vector<int> mainChain;
	for (unsigned int i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].first);
	}
	std::sort(mainChain.begin(), mainChain.end());

	// Step 3: Insert smaller elements using Jacobsthal order
	std::vector<bool> added(pairs.size(), false);
	std::vector<int> jacobSeq = generateJacobsthalSequence(pairs.size() + 1);
	for (unsigned int i = 0; i < pairs.size(); ++i) {
		int idx = jacobSeq[i] - 1;
		if (idx >= 0 && idx < (int)pairs.size()) {
			binaryInsertion(mainChain, pairs[idx].second);
			added[idx] = true;
		}
	}

	for (unsigned int i = 0; i < pairs.size(); ++i) {
		if (!added[i])  // If this small element wasn't added yet
			binaryInsertion(mainChain, pairs[i].second);
	}

	// Step 4: Insert leftover elements
	for (unsigned int i = 0; i < leftovers.size(); ++i)
		binaryInsertion(mainChain, leftovers[i]);

	vec = mainChain;
}

void PmergeMe::mergeInsertionSortList(std::list<int> &lst)
{
    if (lst.size() < 2)
        return;

    // Step 1: Pairing and sorting within pairs
    std::list<std::pair<int, int> > pairs;
    std::list<int> leftovers;
    
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        if (it != lst.end()) {
            int first = *it;
            ++it;
            if(it != lst.end()) {
                int second = *it;
                if (first > second)
                    pairs.push_back(std::make_pair(second, first));
                else
                    pairs.push_back(std::make_pair(first, second));
                ++it;
            }
            else
                leftovers.push_back(first);
        }
    }

    // Step 2: Extract larger elements and sort
    std::list<int> mainChain;
    for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
        mainChain.push_back(pair_it->second);
    }
    mainChain.sort();

    // Step 3: Insert smaller elements using Jacobsthal order
    std::vector<bool> added(pairs.size(), false);
    std::vector<int> jacobSeq = generateJacobsthalSequence(pairs.size() + 1);

    for (unsigned int i = 0; i < pairs.size(); ++i) {
        int idx = jacobSeq[i] - 1;
        if (idx >= 0 && idx < (int)pairs.size()) {
            std::list<std::pair<int, int> >::iterator pair_it = pairs.begin();
            std::advance(pair_it, idx);
            binaryInsertion(mainChain, pair_it->first);
            added[idx] = true;
        }
    }

    // Step 4: Insert any remaining small elements
    for (unsigned int i = 0; i < pairs.size(); ++i) {
        if (!added[i]) {
            // Find the correct position in sorted list
            std::list<std::pair<int, int> >::iterator pair_it = pairs.begin();
            std::advance(pair_it, i);  // Move iterator to the correct position
            binaryInsertion(mainChain, pair_it->first);
        }
    }

    // Step 5: Insert leftover elements
    for (std::list<int>::iterator leftover_it = leftovers.begin(); leftover_it != leftovers.end(); ++leftover_it) {
        binaryInsertion(mainChain, *leftover_it);
    }
    lst = mainChain;
}



void PmergeMe::binaryInsertion(std::list<int> &sorted, int value)
{
    if (sorted.empty()) {
        sorted.push_back(value);
        return;
    }

    std::list<int>::iterator left = sorted.begin();
    std::list<int>::iterator right = sorted.end();
    std::list<int>::iterator mid;

    int size = std::distance(left, right);
    
    while (size > 0) {
        mid = left;
        std::advance(mid, size / 2);
        
        if (*mid < value)
        {
            left = ++mid;
            size -= size / 2 + 1;
        }
        else {
            size /= 2;
        }
    }
    sorted.insert(left, value);
}


void PmergeMe::binaryInsertion(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

void PmergeMe::printContainer(const std::vector<int> &vec)
{
	for (unsigned int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printContainer(const std::list<int> &lst)
{
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
