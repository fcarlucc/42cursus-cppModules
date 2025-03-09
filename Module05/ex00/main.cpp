#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	bureaucrat("Bureaucrat", 20);
		bureaucrat.incrementGrade();
		bureaucrat.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		Bureaucrat	big("Bureaucrat Big", 1);
		std::cout << big << std::endl;
		big.incrementGrade();
		std::cout << big << std::endl;
		big.decrementGrade();
		std::cout << big << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		Bureaucrat	small("Bureaucrat Small", 150);
		std::cout << small << std::endl;
		small.decrementGrade();
		std::cout << small << std::endl;
		small.incrementGrade();
		std::cout << small << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}