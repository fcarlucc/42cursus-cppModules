#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T& x) {
    std::cout << x << " ";
}

void increment(int& x) {
    x++;
}

int main() {
    std::cout << "Testing iter with int array:" << std::endl;
    int a[] = {0, 1, 2, 3, 4};
    iter(a, 5, print<int>);
    std::cout << std::endl;
    iter(a, 5, increment);
    iter(a, 5, print<int>);
    std::cout << std::endl;
    
    std::cout << "Testing iter with string array:" << std::endl;
    std::string b[] = {"Hello", "world,", "this", "is", "iter", "!"};
    iter(b, 6, print<std::string>);
    std::cout << std::endl;
    
    return 0;
}