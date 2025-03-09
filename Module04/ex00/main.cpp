#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // the cat sound
	j->makeSound(); // the dog sound
	meta->makeSound(); // generic animal sound

	delete meta;
	delete j;
	delete i;

	std::cout << "\nTesting WrongAnimal and WrongCat:\n";
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	wrongCat->makeSound(); // the WrongAnimal sound
	wrongMeta->makeSound(); // generic wrong animal sound

	delete wrongMeta;
	delete wrongCat;

	return 0;
}
