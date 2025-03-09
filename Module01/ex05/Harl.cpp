#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
	return ;
}

void Harl::info(void) {

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	return ;
}

void Harl::warning(void) {

	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
	return ;
}

void Harl::error(void) {

	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
	return ;
}

void Harl::complain(std::string level) {

	void	(Harl::*pf[4])(void) = {&Harl::warning, &Harl::debug, &Harl::error, &Harl::info};

	(this->*pf[level[0] % 10 % 7])();
	return ;
}
