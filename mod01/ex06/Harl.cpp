
#include "Harl.hpp"

Harl::Harl() : _minLevel(Harl::DEBUG)
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

void Harl::setMinLevel( std::string level )
{
	LogLevel logLevel = stringToLogLevel(level);
	if (logLevel == INVALID)
	{
		_minLevel = SILENCE;
		std::cout << "It doesn't even matter" << std:: endl;
		return;
	}
	_minLevel = logLevel;

}


void Harl::complain( std::string level )
{
	LogLevel logLevel = stringToLogLevel(level);
	if (logLevel < _minLevel)
		return;

	HarlMemFn log;
	switch (logLevel)
	{
	case DEBUG:
		log = &Harl::debug;
		break;
	case INFO:
		log = &Harl::info;
		break;
	case WARNING:
		log = &Harl::warning;
		break;
	case ERROR:
		log = &Harl::error;
		break;
	default:
		std::cout << "Invalid log level" << std:: endl;
		return;
		break;
	}
	(this->*log)();
}
