#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: " << av[0] << " <numbers>" << std::endl;
        return 1;
    }

    try {
        PmergeMe pmerge(av);

        pmerge.sortDeque();
        pmerge.sortVector();
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}