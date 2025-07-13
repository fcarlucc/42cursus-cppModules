#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    std::cout << "🏢 TESTING INTERN CLASS 🏢\n\n";
    
    try {
        // Create intern and bureaucrat
        Intern intern;
        Bureaucrat boss("Boss", 1);
        
        std::cout << "=== TESTING VALID FORMS ===\n";
        
        // Test all 3 valid forms (exact example from subject included)
        std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
        std::string targets[] = {"garden", "Bender", "Marvin"};
        
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Form " << (i+1) << ": " << formNames[i] << " ---\n";
            
            AForm* form = intern.makeForm(formNames[i], targets[i]);
            if (form) {
                std::cout << *form;
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
        }
        
        std::cout << "\n=== TESTING INVALID FORMS ===\n";
        
        // Test invalid form names
        std::string invalidNames[] = {"coffee making", "ROBOTOMY REQUEST", "invalid form"};
        for (int i = 0; i < 3; i++) {
            std::cout << "\nTesting: \"" << invalidNames[i] << "\"\n";
            AForm* invalid = intern.makeForm(invalidNames[i], "target");
            if (!invalid) {
                std::cout << "✅ Correctly rejected invalid form\n";
            } else {
                std::cout << "❌ Should have failed\n";
                delete invalid;
            }
        }
        
        std::cout << "\n=== SUBJECT EXAMPLE ===\n";
        // Exact code from subject
        {
            Intern intern;
            AForm* rrf;
            rrf = intern.makeForm("robotomy request", "Bender");
            if (rrf) {
                std::cout << "✅ Subject example works!\n";
                delete rrf;
            }
        }
        
        std::cout << "\n✅ ALL TESTS COMPLETED!\n";
        std::cout << "📁 Check for generated *_shrubbery files\n";
        
    } catch (std::exception const &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}