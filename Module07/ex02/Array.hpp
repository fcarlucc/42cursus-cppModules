#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		T* elements;
		unsigned int size;

	public:
		Array();
		Array(unsigned int n);
        Array(const Array &toCopy);
        Array& operator=(const Array &other);
        ~Array();

		T& operator[](unsigned int index);

		unsigned int getSize() const;

		class array_out_of_range : public std::exception {
			virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif