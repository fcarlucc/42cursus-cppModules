#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);           // Can do everything
        Bureaucrat joe("Joe", 140);         // Can sign ShrubberyCreationForm but not execute it
        Bureaucrat mark("Mark", 130);     // Can sign and execute ShrubberyCreationForm

        std::cout << "\n=== Creating Forms ===\n";
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << shrub;
        std::cout << robo;
        std::cout << pardon;

        std::cout << "\n=== Signing Forms ===\n";
        mark.signForm(shrub);  // Mark can sign (130 < 145)
        joe.signForm(robo);     // Joe cannot sign (140 > 72)
        bob.signForm(robo);     // Bob can sign (1 < 72)
        bob.signForm(pardon);   // Bob can sign (1 < 25)

        std::cout << "\n=== Executing Forms ===\n";
        std::cout << "Mark trying to execute shrub (signed, grade 130 vs required 137):\n";
        mark.executeForm(shrub);   // Should succeed (130 < 137)
        
        std::cout << "\nJoe trying to execute shrub (signed, grade 140 vs required 137):\n";
        joe.executeForm(shrub);     // Should fail (140 > 137)
        
        std::cout << "\nBob executing robotomy and pardon:\n";
        bob.executeForm(robo);      // Should succeed
        bob.executeForm(pardon);    // Should succeed

        std::cout << "\n=== Checking for created files ===\n";
        std::cout << "Look for 'garden_shrubbery' file in current directory!\n";

    }
    catch (std::exception const &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}