
#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}
void Harl::debug( void )
{
	std::cout << "debug msg?" << std::endl;
}
void  Harl::info( void )
{
	std::cout << "info msg." << std::endl;
}

void  Harl::warning( void )
{
	std::cout << "warning msg!" << std::endl;
}
void  Harl::error( void )
{
	std::cout << "error msg!!" << std::endl;
}
Harl::LogLevel Harl::stringToLogLevel(const std::string& level) {
	if (level == "DEBUG") return DEBUG;
	if (level == "INFO") return INFO;
	if (level == "WARNING") return WARNING;
	if (level == "ERROR") return ERROR;
	return INVALID;
}

void Harl::complain( std::string level )
{
	LogLevel logLevel = stringToLogLevel(level);

	//OP 1 - array
	if (logLevel == INVALID)
	{
		std::cout << "Invalid log level" << std:: endl;
		return;
	}
	const HarlMemFn fns[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	(this->*(fns[logLevel]))();
	
	// OP 2 - switch
	// HarlMemFn log;
	// switch (logLevel)
	// {
	// case LogLevel::DEBUG:
	// 	log = &Harl::debug;
	// 	break;
	// case LogLevel::INFO:
	// 	log = &Harl::info;
	// 	break;
	// case LogLevel::WARNING:
	// 	log = &Harl::warning;
	// 	break;
	// case LogLevel::ERROR:
	// 	log = &Harl::error;
	// 	break;
	// default:
	// 	std::cout << "Invalid log level" << std:: endl;
	// 	return;
	// 	break;
	// }
	// (this->*log)();
}
