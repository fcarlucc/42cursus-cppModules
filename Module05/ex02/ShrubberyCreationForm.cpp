#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm("Shrubbery", 145, 137) {
	*this = toCopy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return this->target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!this->getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradetoExecute())
		throw AForm::GradeTooLowException();
	
	std::string filename = this->getTarget() + "_shrubbery";

	std::ofstream ofs(filename.c_str());
	if (!ofs) {
		throw std::runtime_error("Unable to open file");
	}

	ofs << "                  $\n"
		   "                 $$$\n"
		   "                $$$$$\n"
		   "               $$$$$$$\n"
		   "                $$$$$\n"
		   "               $$$$$$$\n"
		   "              $$$$$$$$$\n"
		   "             $$$$$$$$$$$\n"
		   "            $$$$$$$$$$$$$\n"
		   "             $$$$$$$$$$$\n"
		   "            $$$$$$$$$$$$$\n"
		   "           $$$$$$$$$$$$$$$\n"
		   "          $$$$$$$$$$$$$$$$$\n"
		   "         $$$$$$$$$$$$$$$$$$$\n"
		   "        $$$$$$$$$$$$$$$$$$$$$\n"
		   "         $$$$$$$$$$$$$$$$$$$\n"
		   "        $$$$$$$$$$$$$$$$$$$$$\n"
		   "       $$$$$$$$$$$$$$$$$$$$$$$\n"
		   "      $$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "     $$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "      $$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "     $$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "      $$$$$$$$$$$$$$$$$$$$$$$$$\n"
		   "       $$$$$$$$$$$$$$$$$$$$$$$\n"
		   "        $$$$$$$$$$$$$$$$$$$$$\n"
		   "         $$$$$$$$$$$$$$$$$$$\n"
		   "                |||||\n"
		   "                |||||\n"
		   "                |||||\n"
		   "                |||||\n"
		   "                |||||\n"
		   "                |||||\n"
		   "...............<|||||>...............\n";
	ofs.close();
}
