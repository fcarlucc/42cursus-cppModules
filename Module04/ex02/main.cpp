#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main() {

	Cat* cat = new Cat();
	Dog* dog = new Dog();

	std::cout << cat->getType() << " makes sound: ";
	cat->makeSound();

	std::cout << dog->getType() << " makes sound: ";
	dog->makeSound();

	delete cat;
	delete dog;

	return 0;
}
