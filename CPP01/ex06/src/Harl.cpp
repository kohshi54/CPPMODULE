#include "Harl.hpp"

// Harl::Harl()
// {

// }

// Harl::~Harl()
// {

// }

void Harl::complain( std::string level )
{
    const char* levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void (Harl::*F)();
	F fp[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int index = -1;

	for (size_t i = 0; i < sizeof(levels)/sizeof(levels[0]); ++i)
	{
		if (level == levels[i]) {
			index = i;
			break;
		}
	}
	switch (index)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			(this->*fp[0])();
		case 1:
			(this->*fp[1])();
		case 2:
			(this->*fp[2])();
		case 3:
			(this->*fp[3])();
		default:
			break;
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << " [ WARNING ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << " [ ERROR ] " << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}