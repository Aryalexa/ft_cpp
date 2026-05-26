//#include <cctype>
#include <exception>
#include <algorithm>


// T is a container of ints. 
// Returns index
template <typename T>
size_t easyfind(T c, int x) {
	size_t i = 0;
	for (typename T::iterator iter = c.begin(); iter != c.end(); ++iter) {
		if (*iter == x)
			return i;
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