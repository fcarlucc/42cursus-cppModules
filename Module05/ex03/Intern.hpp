#ifndef INTERN_HPP
#define INTERN_HPP

#include <map>
#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {

	public :
		Intern();
		~Intern();
		Intern(const Intern &toCopy);
		Intern & operator=(const Intern &other);

		AForm*  makeForm(std::string formName, std::string target);
};

#endif
