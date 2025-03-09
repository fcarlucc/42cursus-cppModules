#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {

	private:
		std::string	name;
		int			grade;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &toCopy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &other);
		void		incrementGrade();
		void		decrementGrade();
		std::string getName() const;
		void		setName(const std::string name);
		int   getGrade() const;
		void		setGrade(const int grade);

		class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &other);

#endif
