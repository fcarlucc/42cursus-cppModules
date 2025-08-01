#ifndef FORM_HPP
#define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;  

	public:
		Form();
		Form(const Form& toCopy);
		~Form();
		Form&				operator=(const Form &other);
		const std::string	getName() const;
		bool				getSign() const;
		void				setSign(const bool sign);
		int					getGradeToSign() const;
		int					getGradetoExecute() const;
		void				beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
