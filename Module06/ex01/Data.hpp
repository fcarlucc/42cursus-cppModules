#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int id;
    std::string name;
    float value;
    bool isActive;
    
    Data();
    Data(int id, const std::string& name, float value, bool isActive);
    Data(const Data &toCopy);
    Data& operator=(const Data &other);
    ~Data();
};

#endif
