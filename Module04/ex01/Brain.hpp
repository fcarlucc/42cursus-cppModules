#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {

	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain &toCopy);
		~Brain();
		Brain&		operator=(const Brain &other);
		void		setIdea(const std::string idea, int id);
		std::string	getIdea(int id) const;
};

#endif
