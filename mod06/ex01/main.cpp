
#include "Serializer.hpp"
#include <iomanip>
#include <cassert>


static void show_data(const Data &data)
{
	using std::cout;
	using std::endl;
	cout << "d " << std::setprecision(14) << data.d << endl;
	cout << "i " << data.i << endl;
	cout << "str \"" << data.str << "\"" << endl;
}

int main()
{
	Data data;
	data.d = 123.45678901;
	data.i = -34567;
	data.str = "Hola, \n¿Cómo estás?";

	std::cout << "BEFORE" << std::endl;
	show_data(data);
	
	uintptr_t address = Serializer::serialize(&data);
	std::cout << "..." << std::endl;
	Data *ptr = Serializer::deserialize(address);

	// assert: same pointer
	assert(ptr == &data);

	std::cout << std::endl;
	std::cout << "AFTER" << std::endl;
	show_data(*ptr);

}