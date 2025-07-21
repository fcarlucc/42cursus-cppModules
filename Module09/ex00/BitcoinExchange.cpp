#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    loadDatabase(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy) : data(toCopy.data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open database file");
    }

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        lineCount++;
        
        // Skip header line if it exists
        if (lineCount == 1 && (line == "date,exchange_rate" || line.find("date") != std::string::npos)) {
            continue;
        }
        
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string valueStr = line.substr(commaPos + 1);
            
            char* endPtr;
            float value = std::strtof(valueStr.c_str(), &endPtr);
            
            if (endPtr != valueStr.c_str() && *endPtr == '\0') {
                data[date] = value;
            }
        }
    }
}

const std::map<std::string, float>& BitcoinExchange::getData() const {
    return data;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        lineCount++;
        if (line.empty()) continue;
        
        // Skip header line if it's the first line and contains "date | value"
        if (lineCount == 1 && line == "date | value") {
            continue;
        }
        
        size_t pipePos = line.find(" | ");
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 3);
        
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        char* endPtr;
        float value = std::strtof(valueStr.c_str(), &endPtr);
        
        if (endPtr == valueStr.c_str() || *endPtr != '\0') {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        // Calculate and display result
        float rate = getExchangeRate(date);
        if (rate > 0) {
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
    }
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = data.find(date);
    if (it != data.end()) {
        return it->second;
    }
    
    // Find the closest earlier date
    std::map<std::string, float>::const_iterator closest = data.end();
    for (std::map<std::string, float>::const_iterator iter = data.begin(); iter != data.end(); ++iter) {
        if (iter->first < date) {
            closest = iter;
        } else {
            break;
        }
    }
    
    if (closest != data.end()) {
        return closest->second;
    }
    
    std::cerr << "Error: no exchange rate found for date => " << date << std::endl;
    return -1;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }
    
    // Basic range checks
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());
    
    if (year < 2009 || year > 2030) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    return true;
}

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& exchange) {
    const std::map<std::string, float>& data = exchange.getData();
    for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); ++it) {
        os << it->first << ": " << it->second << std::endl;
    }
    return os;
}