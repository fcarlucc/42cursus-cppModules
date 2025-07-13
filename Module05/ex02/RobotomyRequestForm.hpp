#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {

    private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &toCopy);
		~RobotomyRequestForm();
		RobotomyRequestForm&  operator=(const RobotomyRequestForm &other);
        std::string             getTarget(void) const;
		void                    execute(const Bureaucrat& executor) const;
};

#endif