#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {

	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n";
	return ;
}

void Harl::info(void) {

	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
	return ;
}

void Harl::warning(void) {

	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n\n";
	return ;
}

void Harl::error(void) {

	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
	return ;
}

void Harl::complain(std::string level) {

	void	(Harl::*pf[4])(void) = {&Harl::warning, &Harl::debug, &Harl::error, &Harl::info};

	switch (level[0] % 10 % 7) {

		case 1:
			(this->*pf[1])();
			(this->*pf[2])();
			(this->*pf[3])();
			break ;
		case 3:
			(this->*pf[3])();
			break ;
		case 0:
			(this->*pf[0])();
			(this->*pf[1])();
			(this->*pf[2])();
			(this->*pf[3])();
			break ;
		case 2:
			(this->*pf[2])();
			(this->*pf[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return ;
}
