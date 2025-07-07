#ifndef AFORM_HPP
#define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;  

	public:
		AForm();
		AForm(const AForm& toCopy);
		virtual ~AForm();
		AForm&				operator=(const AForm &other);
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

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
