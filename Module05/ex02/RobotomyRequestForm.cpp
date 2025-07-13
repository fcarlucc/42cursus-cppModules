#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm("Robotomy", 72, 45) {
	*this = toCopy;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return this->target;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!this->getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradetoExecute())
		throw AForm::GradeTooLowException();
    
	srand(time(NULL));
	if (rand() % 2)
		std::cout << "Earing some drilling noisees.. " << this->target << " has been robotomized" << std::endl;
	else
		std::cout << "Earing some drilling noisees.. " << this->target << " has failed to be robotomized" << std::endl;
}
