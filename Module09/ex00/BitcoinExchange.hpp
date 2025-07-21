#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

class BitcoinExchange {
    private:
        std::map<std::string, float> data;
        void loadDatabase(const std::string& filename);
        bool isValidDate(const std::string& date) const;
    
    public:
        BitcoinExchange(const std::string& filename);
        BitcoinExchange(const BitcoinExchange& toCopy);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        const std::map<std::string, float>& getData() const;
        void processInputFile(const std::string& filename);
        float getExchangeRate(const std::string& date) const;
};

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& exchange);

#endif