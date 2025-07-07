#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	{
		std::cout << "-------------------------" << std::endl;
		try {
			Bureaucrat bur("Mr Bur", 20);
			Form form;

			bur.signForm(form);
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "-------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------" << std::endl;
		try {
			Bureaucrat bur("Mr Bur", 30);
			Form form;

			bur.signForm(form);
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "-------------------------" << std::endl;
	}

	return (0);
}
