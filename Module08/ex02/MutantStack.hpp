#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <list>
#include <stack>
#include <deque>
#include <iostream>


/**
 * @brief Classe template che estende std::stack rendendolo iterabile.
 * 
 * std::stack è un container adapter che di default utilizza std::deque come container
 * sottostante ma non espone iteratori. 
 * MutantStack eredita da std::stack e rende disponibili
 * gli iteratori del container interno (deque per default),
 * permettendo di iterare attraverso gli elementi della stack.
 * 
 */
template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack& toCopy);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif