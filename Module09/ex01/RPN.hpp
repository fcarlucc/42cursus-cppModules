#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <stdexcept>

class RPN {
    private:
        std::stack<double, std::list<double> > stack;

    public:
        RPN();
        ~RPN();
    
    void calculate(const std::string& expression);
};

#endif