#include <stdexcept>

template <typename T>
Array<T>::Array() : elements(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), size(n) {}

template <typename T>
Array<T>::Array(const Array& toCopy) : elements(NULL), size(0) {
    size = toCopy.size;
    elements = new T[size];
    for (unsigned int i = 0; i < size; ++i) {
        elements[i] = toCopy.elements[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        if (elements != NULL)
            delete[] elements;

        size = other.size;
        elements = new T[size];
        for (unsigned int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    if (elements != NULL)
        delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size)
        throw Array<T>::array_out_of_range();
    return elements[index];
}

template <typename T>
unsigned int Array<T>::getSize() const {
    return this->size;
}

template <typename T>
const char* Array<T>::array_out_of_range::what() const throw() {
    return "Index is out of bounds";
}
