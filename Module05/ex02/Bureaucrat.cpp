#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade) {
	if (this->grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (this->grade < MAX_GRADE)
		throw GradeTooHighException();
	std::cout << *this << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy) {
	*this = toCopy;
	return ;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		// this->name = other.name;
		this->grade = other.grade;
	}
	return *this;
}

const std::string	Bureaucrat::getName() const {
	return this->name;
}

int	Bureaucrat::getGrade() const {
	return this->grade;
}

void	Bureaucrat::setGrade(const int grade) {
	this->grade = grade;
	return ;
}

void	Bureaucrat::incrementGrade() {
	if (this->grade <= MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
	return ;
}

void	Bureaucrat::decrementGrade() {
	if (this->grade >= MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
	return ;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		if (form.getSign())
			std::cout << this->name << " signed " << form.getName() << "\n" << std::endl;
	} catch (std::exception &e) {
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << *this << "executed " << form << std::endl;
	} catch(const std::exception& e) {
		std::cout << *this << " couldn't execute " << form << std::endl;
		std::cout << "because: " << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low\n";
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high\n";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}
