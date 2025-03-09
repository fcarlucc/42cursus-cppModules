#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade) {
    if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
    std::cout << this->getName() << ", bureaucrat grade " << this->getGrade() << "." << std::endl;
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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->setName(other.getName());
        this->setGrade(other.getGrade());
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

void Bureaucrat::setName(const std::string name) {
    this->name = name;
    return ;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::setGrade(const int grade) {
    this->grade = grade;
    return ;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

void Bureaucrat::incrementGrade() {
    if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
    return ;
}

void Bureaucrat::decrementGrade() {
    if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
    return ;
}

void		Bureaucrat::signForm(Form &form) {
	try {
		if (form.beSigned(*this))
			std::cout << this->name << " signed " << form.getName()<< std::endl;
	} catch (std::exception &e) {
		std::cout << this->name << " couldn't signed ";
		std::cout << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << " bureaucrat grade "<<obj.getGrade() << std::endl;
	return os;
}