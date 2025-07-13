#include "AForm.hpp"

AForm::AForm() : name("AForm"), sign(false), gradeToSign(21), gradeToExecute(42) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) :
	name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& toCopy)
	: name(toCopy.name), sign(toCopy.sign),
		gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute) {}

AForm::~AForm() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

AForm&	AForm::operator=(const AForm &other) {
	if (this != &other) {
		// this->name = other.name
		this->sign = other.sign;
		// this->gradeToSign = other.gradeToSign;
		// this->gradeToExecute = other.gradeToExecute;
	}
	return *this;
}

const std::string	AForm::getName() const {
	return this->name;
}

bool	AForm::getSign() const {
	return this->sign;
}

void	AForm::setSign(const bool sign) {
	this->sign = sign;
	return ;
}

int	AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int	AForm::getGradetoExecute() const {
	return this->gradeToExecute;
}

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign)
		this->sign = true;
	else
		throw AForm::GradeTooLowException();
	return ;
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Grade too low\n";
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Grade too high\n";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Error the form is not signed\n";
}

std::ostream& operator<<(std::ostream &o, const AForm &Aform) {
	if (Aform.getSign())
		o << "AForm " << Aform.getName() << " is signed, grade to sign is " << Aform.getGradeToSign() << ", grade to execute is " << Aform.getGradetoExecute() << std::endl;
	else
		o << "AForm " << Aform.getName() << " is not signed, grade to sign is " << Aform.getGradeToSign() << ", grade to execute is " << Aform.getGradetoExecute() << std::endl;

	return o;
}