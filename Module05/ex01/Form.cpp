#include "Form.hpp"

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {

}

Form::Form(const Form& toCopy) {
	*this = toCopy;
	return ;
}

Form::~Form() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Form&	operator=(const Form &other) {
	if (this != &other) {
		this->setName(other.getName());
		this->setGrade(other.getGrade());
	}
}
