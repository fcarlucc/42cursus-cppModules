#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {
	private:
		std::vector<int> numbers;
		unsigned int n;

	public:
		Span(unsigned int n);
		Span(const Span& toCopy);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		unsigned int size() const;
		
		template<typename Iterator>
		void addRange(Iterator begin, Iterator end);

		class SpanFullException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		
		class NoSpanException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
};

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
        addNumber(*it);
    }
}

#endif