#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern& Intern::operator=(const Intern & rhs) {
    (void)rhs;
	return *this;
}

Intern::~Intern() {}

// TYPEDEF PER PUNTATORE A FUNZIONE  ~Factory Pattern
// Definisce un tipo per puntatori a funzioni
typedef AForm* (*FormCreator)(const std::string&);

// FUNZIONI FACTORY STATICHE
static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    // STRUTTURA LOCALE per associare nome → funzione di creazione
    struct FormPair {
        const char* name;        // Nome del form come stringa
        FormCreator creator;     // Puntatore alla funzione di creazione
    };
    
    // 🎯 ARRAY STATICO di associazioni nome-costruttore
    // static = inizializzato una sola volta, efficiente
    // const = immutabile, sicuro
    static const FormPair forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPardon}
        // Aggiungiere altri form qui se necessario
    };
    
    // 🔄 RICERCA LINEARE nell'array
    // sizeof(forms)/sizeof(forms[0]) = numero di elementi nell'array
    for (size_t i = 0; i < sizeof(forms)/sizeof(forms[0]); ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);  // Chiama la funzione di creazione
        }
    }
    
    std::cout << "Intern: Error, form '" << formName << "' does not exist." << std::endl;
    return NULL;
}