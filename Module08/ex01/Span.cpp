#include "Span.hpp"

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span& other) : numbers(other.numbers), n(other.n) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        n = other.n;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (n == 0 || numbers.size() >= n) {
        throw SpanFullException();
    }
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw NoSpanException();
    }
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int min = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        unsigned int span = sorted[i] - sorted[i-1];
        if (span < min) {
            min = span;
        }
    }
    return min;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw NoSpanException();
    }
    
    int max = *std::max_element(numbers.begin(), numbers.end());
	int min = *std::min_element(numbers.begin(), numbers.end());

	return (max - min);
}

unsigned int Span::size() const {
    return numbers.size();
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
    return "Cannot calculate span: need at least 2 numbers";
}