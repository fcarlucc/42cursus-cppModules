#include "Array.hpp"

int main() {
    Array<int> numbers(3);
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    std::cout << "Contenuto dell'array di interi: ";
    for (unsigned int i = 0; i < numbers.getSize(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    Array<int> copia(numbers);
    copia[0] = 99;

    std::cout << "Originale[0]: " << numbers[0] << ", Copia[0]: " << copia[0] << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "World";
    words[2] = "!";

    std::cout << "Contenuto dell'array di stringhe: ";
    for (unsigned int i = 0; i < words.getSize(); ++i)
        std::cout << words[i] << " ";
    std::cout << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    try {
        std::cout << "Accesso a numbers[3]: ";
        std::cout << numbers[2] << std::endl;
        std::cout << "Accesso a words[5]: ";
        std::cout << words[5] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Eccezione catturata: " << e.what() << std::endl;
    }

    return 0;
}
