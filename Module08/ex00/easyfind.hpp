#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class ElementNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Element not found in container";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	std::cout << "Searching for " << value << " in container." << std::endl;
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw ElementNotFoundException();
    }
    return it;
}

#endif