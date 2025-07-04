#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat {

	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &toCopy);
		~Bureaucrat();
		Bureaucrat&			operator=(const Bureaucrat &other);
		void				incrementGrade();
		void				decrementGrade();
		const std::string	getName() const;
		int					getGrade() const;
		void				setGrade(const int grade);
		void				signForm(Form &form);

		class GradeTooLowException : public std::exception {
			virtual const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception {
			virtual const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat &other);

#endif
