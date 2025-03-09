#ifndef FORM_HPP
#define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		~Form();
		Form(Form& toCopy);
		Form&               operator=(const Form &other);
		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getGradeToSign(void) const;
		int					getGradetoExecute(void) const;
		void				beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif