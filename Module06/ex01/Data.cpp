#include "Data.hpp"

Data::Data() : id(0), name(""), value(0.0f), isActive(false) {}

Data::Data(int id, const std::string& name, float value, bool isActive) 
    : id(id), name(name), value(value), isActive(isActive) {}

Data::Data(const Data& toCopy) 
    : id(toCopy.id), name(toCopy.name), value(toCopy.value), isActive(toCopy.isActive) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        value = other.value;
        isActive = other.isActive;
    }
    return *this;
}

Data::~Data() {}
