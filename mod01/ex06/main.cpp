#include "Harl.hpp"

int main(int argn, char *argv[])
{
	if (argn != 2)
	{
		std::cout << "Error. One argument was expected." << std::endl;
		return (1);
	}
	Harl h;
	h.setMinLevel(argv[1]);
	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");

	return 0;
}