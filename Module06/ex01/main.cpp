#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    std::cout << "=== Serializer Test ===" << std::endl;
    
    // 1. Creiamo un oggetto Data
    Data myData(42, "Hello World", 3.14f, true);
    Data* originalPtr = &myData;
    
    std::cout << "Original object:" << std::endl;
    std::cout << "  Address: " << originalPtr << std::endl;
    std::cout << "  Data: {id=" << myData.id << ", name=\"" << myData.name << "\"}" << std::endl;
    
    // 2. SERIALIZZAZIONE: Puntatore → Numero
    uintptr_t serializedValue = Serializer::serialize(originalPtr);
    std::cout << "\nSerialization (pointer → number):" << std::endl;
    std::cout << "  Number: " << serializedValue << std::endl;
    
    // 3. DESERIALIZZAZIONE: Numero → Puntatore
    Data* deserializedPtr = Serializer::deserialize(serializedValue);
    std::cout << "\nDeserialization (number → pointer):" << std::endl;
    std::cout << "  Address: " << deserializedPtr << std::endl;
    
    // 4. VERIFICA: I puntatori devono essere uguali!
    std::cout << "\nVerification:" << std::endl;
    if (originalPtr == deserializedPtr) {
        std::cout << "  ✅ SUCCESS! Pointers match" << std::endl;
        std::cout << "  ✅ Data accessible: {id=" << deserializedPtr->id 
                  << ", name=\"" << deserializedPtr->name << "\"}" << std::endl;
    } else {
        std::cout << "  ❌ ERROR! Pointers don't match" << std::endl;
    }
    
    return 0;
}
