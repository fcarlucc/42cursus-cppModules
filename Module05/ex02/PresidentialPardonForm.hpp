#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

    private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &toCopy);
		~PresidentialPardonForm();
		PresidentialPardonForm&  operator=(const PresidentialPardonForm &other);
        std::string             getTarget(void) const;
		void                    execute(const Bureaucrat& executor) const;
};

#endif