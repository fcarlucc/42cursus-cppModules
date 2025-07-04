#include "Bureaucrat.hpp"

int	main(void) {
	{
		std::cout << "-------------------------" << std::endl;
		try {
			Bureaucrat bur("Mr Bur", 20);
			bur.incrementGrade();
			bur.decrementGrade();

			Bureaucrat	high("Mr High", 1);
			high.incrementGrade();
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "-------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------" << std::endl;
		try {
			Bureaucrat bur("Mr Bur", 20);
			bur.incrementGrade();
			bur.decrementGrade();

			Bureaucrat	small("Mr Low", 150);
			small.decrementGrade();
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "-------------------------" << std::endl;
	}

	return (0);
}
