#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <iomanip>

class PmergeMe {
    private:
        std::deque<int> deque;
        std::vector<int> vector;

        // Funzioni template per Ford-Johnson
        template<typename Container>
        void fordJohnsonSort(Container& container);
        
        template<typename Container>
        std::vector<int> generateJacobsthal(int n);
        
        template<typename Container>
        void binaryInsert(Container& container, int value);

    public:
        PmergeMe();
        PmergeMe(char **nums);
        PmergeMe(const PmergeMe &toCopy);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sortDeque();
        void sortVector();
        bool isValidNumber(const char *num);
};

#endif