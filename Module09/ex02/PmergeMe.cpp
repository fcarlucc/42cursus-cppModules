#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **nums) {
    vector.clear();
    deque.clear();

    while (*(++nums)) {
        if (!isValidNumber(*nums)) {
            std::cerr << "Error: Invalid number: " << *nums << std::endl;
            exit(1);
        }
        std::istringstream iss(*nums);
        int num;
        iss >> num;
        deque.push_back(num);
        vector.push_back(num);
    }
}

PmergeMe::PmergeMe(const PmergeMe &toCopy) : deque(toCopy.deque), vector(toCopy.vector) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        deque = other.deque;
        vector = other.vector;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortDeque() {
    std::cout << "Before: ";
    for (size_t i = 0; i < deque.size(); ++i) {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;
    
    std::clock_t start = std::clock();
    fordJohnsonSort(deque);
    std::clock_t end = std::clock();
    
    std::cout << "After:  ";
    for (size_t i = 0; i < deque.size(); ++i) {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;
    
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << deque.size() 
              << " elements with std::deque: " << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}

void PmergeMe::sortVector() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    std::clock_t start = std::clock();
    fordJohnsonSort(vector);
    std::clock_t end = std::clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
    
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vector.size() 
              << " elements with std::vector: " << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}

bool PmergeMe::isValidNumber(const char *num) {
    if (!num || !*num)
        return false;
    for (int i = 0; num[i]; ++i)
        if (!std::isdigit(num[i]))
            return false;
    return true;
}

// ===== IMPLEMENTAZIONE FORD-JOHNSON =====

template<typename Container>
void PmergeMe::fordJohnsonSort(Container& container) {
    if (container.size() <= 1)
        return;
    
    // Caso base: se abbiamo solo 2 elementi, ordiniamoli direttamente
    if (container.size() == 2) {
        if (container[0] > container[1]) {
            std::swap(container[0], container[1]);
        }
        return;
    }
    
    // Gestione elemento dispari (straggler)
    int straggler = -1;
    bool hasStraggler = false;
    if (container.size() % 2 == 1) {
        straggler = container.back();
        container.pop_back();
        hasStraggler = true;
    }
    
    // Creazione coppie e ordinamento locale
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2) {
        int a = container[i];
        int b = container[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    
    // Estrazione winners per ordinamento ricorsivo
    Container winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        winners.push_back(pairs[i].second);
    }
    
    // Ordinamento ricorsivo dei winners
    fordJohnsonSort(winners);
    
    // Costruzione main chain
    container.clear();
    if (!pairs.empty()) {
        container.push_back(pairs[0].first); // Primo perdente
    }
    for (typename Container::iterator it = winners.begin(); it != winners.end(); ++it) {
        container.push_back(*it);
    }
    
    // Inserimento elementi pending con sequenza Jacobsthal
    std::vector<int> pending;
    for (size_t i = 1; i < pairs.size(); ++i) {
        pending.push_back(pairs[i].first);
    }
    
    if (!pending.empty()) {
        std::vector<int> jacobsthal = generateJacobsthal<Container>(pending.size());
        
        // Inserimento usando ordine Jacobsthal
        // Prima inseriamo secondo la sequenza di Jacobsthal
        for (size_t i = 1; i < jacobsthal.size(); ++i) {
            int end = std::min(jacobsthal[i], static_cast<int>(pending.size()) - 1);
            int start = jacobsthal[i-1];
            
            // Inserisci in ordine decrescente nell'intervallo Jacobsthal
            for (int j = end; j > start; --j) {
                if (j >= 0 && j < static_cast<int>(pending.size())) {
                    binaryInsert(container, pending[j]);
                }
            }
        }
        
        // Inserisci eventuali elementi rimanenti non coperti da Jacobsthal
        std::vector<bool> inserted(pending.size(), false);
        for (size_t i = 1; i < jacobsthal.size(); ++i) {
            int end = std::min(jacobsthal[i], static_cast<int>(pending.size()) - 1);
            int start = jacobsthal[i-1];
            for (int j = end; j > start; --j) {
                if (j >= 0 && j < static_cast<int>(pending.size())) {
                    inserted[j] = true;
                }
            }
        }
        
        // Inserisci gli elementi non ancora inseriti
        for (size_t j = 0; j < pending.size(); ++j) {
            if (!inserted[j]) {
                binaryInsert(container, pending[j]);
            }
        }
    }
    
    // Inserimento straggler
    if (hasStraggler) {
        binaryInsert(container, straggler);
    }
}

template<typename Container>
std::vector<int> PmergeMe::generateJacobsthal(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    if (n <= 0) return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n == 1) return jacobsthal;
    
    while (true) {
        int next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
        if (next >= n) break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

template<typename Container>
void PmergeMe::binaryInsert(Container& container, int value) {
    typename Container::iterator pos = std::lower_bound(container.begin(), container.end(), value);
    container.insert(pos, value);
}
