#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    
    std::cout << "\n--- Test 1: Subject test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 2: Span full exception ---" << std::endl;
    try {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 3: No span exception ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 4: Large test with 15,000 numbers ---" << std::endl;
    try {
        Span largeSp = Span(15000);
        std::srand(std::time(NULL));
        
        for (int i = 0; i < 15000; ++i) {
            largeSp.addNumber(std::rand() % 100000);
        }
        
        std::cout << "Added " << largeSp.size() << " numbers" << std::endl;
        std::cout << "Shortest span: " << largeSp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 5: Testing addRange with iterators ---" << std::endl;
    try {
        std::vector<int> numbers;
        for (int i = 1; i <= 10; ++i) {
            numbers.push_back(i * 10);
        }
        
        Span sp = Span(15);
        sp.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Added " << sp.size() << " numbers using addRange" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 6: Edge case with identical numbers ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(1);
        sp.addNumber(10);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
