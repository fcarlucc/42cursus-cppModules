#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <iostream>

enum InputType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_FLOAT,
    PSEUDO_DOUBLE,
    INVALID
};

class ScalarConverter {

    // Subject richiede che la classe non sia istanziabile
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &toCopy);
		ScalarConverter & operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void convert(const std::string& str);
};

#endif