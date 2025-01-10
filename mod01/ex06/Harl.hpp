
#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl
{
private:
	int _minLevel;
	enum LogLevel {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		INVALID,
		SILENCE
	};
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	LogLevel stringToLogLevel(const std::string& level);

	typedef  void (Harl::*HarlMemFn)(void);  // member-function pointer type definition

public:
	Harl();
	~Harl();
	void complain( std::string level );
	void setMinLevel( std::string level );
};

#endif
