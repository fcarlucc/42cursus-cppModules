#include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    
    int random = std::rand() % 3;
    
    if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
    if (!p) {
        std::cout << "NULL pointer" << std::endl;
        return;
    }
    
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {}
    
    std::cout << "Unknown" << std::endl;
}
