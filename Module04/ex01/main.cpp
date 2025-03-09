#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; // Dog destructor should clean up correctly
	delete i; // Cat destructor should clean up correctly

	std::cout << "\nTesting array of Animals:\n";
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}

	return 0;
}
