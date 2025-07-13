#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : AForm("Presidential", 25, 5) {
	*this = toCopy;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return this->target;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!this->getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradetoExecute())
		throw AForm::GradeTooLowException();
    
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
