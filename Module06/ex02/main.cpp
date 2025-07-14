#include "Base.hpp"

int main() {
    std::cout << "=== Real Type Identification Test ===" << std::endl;
    
    std::cout << "\n1. Random generation test:" << std::endl;
    for (int i = 0; i < 6; i++) {
        Base* obj = generate();
        std::cout << "Object " << (i + 1) << " - Pointer: ";
        identify(obj);
        std::cout << "Object " << (i + 1) << " - Reference: ";
        identify(*obj);
        delete obj;
        std::cout << std::endl;
    }
    
    std::cout << "2. Specific type tests:" << std::endl;
    
    // Test A
    std::cout << "\nTesting A:" << std::endl;
    Base* a = new A();
    std::cout << "Pointer: ";
    identify(a);
    std::cout << "Reference: ";
    identify(*a);
    delete a;
    
    // Test B
    std::cout << "\nTesting B:" << std::endl;
    Base* b = new B();
    std::cout << "Pointer: ";
    identify(b);
    std::cout << "Reference: ";
    identify(*b);
    delete b;
    
    // Test C
    std::cout << "\nTesting C:" << std::endl;
    Base* c = new C();
    std::cout << "Pointer: ";
    identify(c);
    std::cout << "Reference: ";
    identify(*c);
    delete c;
    
    // Test NULL
    std::cout << "\nTesting NULL:" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "NULL pointer: ";
    identify(nullPtr);
    
    return 0;
}
