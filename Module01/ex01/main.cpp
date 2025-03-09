#include "Zombie.hpp"

int main() {

	int			n;
	std::string	name;

	std::cout << "N of zombies :\n- > ";
	std::cin >> n;
	std::cout << "Name :\n- > ";
	std::cin >> name;

	Zombie* zombies = zombieHorde(n, name);
	
	delete[] zombies;

	return 0;
}
