#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
    
    std::cout << "\n--- Testing with std::vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found " << *it << " in vector at position " << (it - vec.begin()) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found " << *it << " in vector" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Testing with std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    
    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found " << *it << " in list" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found " << *it << " in list" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Testing with empty container ---" << std::endl;
    std::vector<int> empty_vec;
    
    try {
        std::vector<int>::iterator it = easyfind(empty_vec, 1);
        std::cout << "Found " << *it << " in empty vector" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
