//#include <cctype>
#include <exception>


// T is a container of ints. 
// Returns index
template <typename T>
size_t easyfind(T c, int x) {
	typename T::iterator it;
	int i = 0;
	for (it = c.begin(); it != c.end(); ++it)
	{
		if ((*it) == x) return i;
		++i;
	}
	throw std::runtime_error("not found");
}

template <typename T>
void easyfind_test(std::string container_name, T cont, 
	int search1, int search2)
{
	using std::cout;
	using std::endl;

	cout << container_name << " ---" << endl;

	int searching;
	searching = search1;
	try {
		int idx =  easyfind(cont, searching);
		cout << "container at " << idx << " = " << searching << endl;
	}
	catch (std::exception &e) {
		cout << "exception caught: " << e.what() << endl;
	}
	searching = search2;
	try {
		int idx =  easyfind(cont, searching);
		cout << "container at " << idx << " = " << searching << endl;
	}
	catch (std::exception &e) {
		cout << "exception caught: " << e.what() << endl;
	}
}