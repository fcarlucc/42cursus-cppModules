#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy) {
    (void)toCopy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string& str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

static bool isSingleChar(const std::string& str) {
    return (str.length() == 1 && std::isprint(str[0]));
}

static bool isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "+inf" || str == "-inf" || 
            str == "nanf" || str == "+inff" || str == "-inff");
}

static bool isFloat(const std::string& str) {
    if (str.length() < 2 || str[str.length() - 1] != 'f')
        return false;
    
    std::string temp = str.substr(0, str.length() - 1);
    char* end;
    strtod(temp.c_str(), &end);
    return (*end == '\0' && temp.find('.') != std::string::npos);
}

static bool isDouble(const std::string& str) {
    if (str.find('.') == std::string::npos)
        return false;
    
    char* end;
    strtod(str.c_str(), &end);
    return (*end == '\0');
}

static bool isInt(const std::string& str) {
    if (str.empty())
        return false;
    
    char* end;
    strtol(str.c_str(), &end, 10);
    return (*end == '\0');
}

static InputType detectInputType(const std::string& str) {
    if (str.empty())
        return INVALID;
    if (isCharLiteral(str))
        return CHAR;
    if (isPseudoLiteral(str)) {
        if (str == "nanf" || str == "+inff" || str == "-inff")
            return PSEUDO_FLOAT;
        return PSEUDO_DOUBLE;
    }
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;
    if (isInt(str))
        return INT;
    if (isSingleChar(str))
        return CHAR;
    
    return INVALID;
}

static void convertAndPrintChar(double val, bool isPseudo) {
    std::cout << "char: ";
    
    if (isPseudo || std::isnan(val) || std::isinf(val)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    
    int intVal = static_cast<int>(val);
    if (val != intVal || intVal < 0 || intVal > 255) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    
    if (intVal < 32 || intVal > 126) {
        std::cout << "Non displayable" << std::endl;
        return ;
    }
    
    std::cout << "'" << static_cast<char>(intVal) << "'" << std::endl;
}

static void convertAndPrintInt(double val, bool isPseudo) {
    std::cout << "int: ";
    
    if (isPseudo || std::isnan(val) || std::isinf(val)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    
    std::cout << static_cast<int>(val) << std::endl;
}

static void convertAndPrintFloat(double val, bool isPseudo) {
    std::cout << "float: ";
    
    if (isPseudo) {
        if (std::isnan(val))
            std::cout << "nanf";
        else if (std::isinf(val) && val > 0)
            std::cout << "+inff";
        else if (std::isinf(val) && val < 0)
            std::cout << "-inff";
        std::cout << std::endl;
        return ;
    }
    
    float floatVal = static_cast<float>(val);
    std::cout << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
}

static void convertAndPrintDouble(double val, bool isPseudo) {
    std::cout << "double: ";
    
    if (isPseudo) {
        if (std::isnan(val))
            std::cout << "nan";
        else if (std::isinf(val) && val > 0)
            std::cout << "+inf";
        else if (std::isinf(val) && val < 0)
            std::cout << "-inf";
        std::cout << std::endl;
        return ;
    }
    
    std::cout << std::fixed << std::setprecision(1) << val << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
    InputType type = detectInputType(str);
    double value = 0.0;
    bool isPseudo = false;
    
    switch (type) {
        case CHAR:
            if (isCharLiteral(str))
                value = static_cast<double>(str[1]);
            else
                value = static_cast<double>(str[0]);
            break;
            
        case INT:
            value = static_cast<double>(std::atoi(str.c_str()));
            break;
            
        case FLOAT: {
            std::string temp = str.substr(0, str.length() - 1);
            value = std::atof(temp.c_str());
            break;
        }
        
        case DOUBLE:
            value = std::atof(str.c_str());
            break;
            
        case PSEUDO_FLOAT:
        case PSEUDO_DOUBLE:
            isPseudo = true;
            if (str == "nanf" || str == "nan")
                value = std::numeric_limits<double>::quiet_NaN();
            else if (str == "+inff" || str == "+inf")
                value = std::numeric_limits<double>::infinity();
            else if (str == "-inff" || str == "-inf")
                value = -std::numeric_limits<double>::infinity();
            break;
            
        case INVALID:
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return ;
    }
    
    convertAndPrintChar(value, isPseudo);
    convertAndPrintInt(value, isPseudo);
    convertAndPrintFloat(value, isPseudo);
    convertAndPrintDouble(value, isPseudo);
}
