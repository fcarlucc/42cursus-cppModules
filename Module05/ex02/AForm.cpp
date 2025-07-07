#include "Form.hpp"

Form::Form()
	: name("Form"), sign(false), gradeToSign(25), gradeToExecute(10) {}

Form::Form(const Form& toCopy)
	: name(toCopy.name), sign(toCopy.sign),
		gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute) {}

Form::~Form() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Form&	Form::operator=(const Form &other) {
	if (this != &other) {
		// this->name = other.name
		this->sign = other.sign;
		// this->gradeToSign = other.gradeToSign;
		// this->gradeToExecute = other.gradeToExecute;
	}
	return *this;
}

const std::string	Form::getName() const {
	return this->name;
}

bool	Form::getSign() const {
	return this->sign;
}

void	Form::setSign(const bool sign) {
	this->sign = sign;
	return ;
}

int	Form::getGradeToSign() const {
	return this->gradeToSign;
}

int	Form::getGradetoExecute() const {
	return this->gradeToExecute;
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign)
		this->sign = true;
	else
		throw Form::GradeTooLowException();
	return ;
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade too low\n";
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade too high\n";
}

std::ostream& operator<<(std::ostream &o, Form &form) {
	if (form.getSign())
		o << "Form " << form.getName() << " is signed, grade to sign is " << form.getGradeToSign() << ", grade to execute is " << form.getGradetoExecute() << std::endl;
	else
		o << "Form " << form.getName() << " is not signed, grade to sign is " << form.getGradeToSign() << ", grade to execute is " << form.getGradetoExecute() << std::endl;

	return o;
}