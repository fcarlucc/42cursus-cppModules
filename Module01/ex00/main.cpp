#include "Zombie.hpp"

int main() {

	Zombie* zombie = newZombie("heap");

	randomChump("stack");
	delete zombie;
	
	return 0;
}
