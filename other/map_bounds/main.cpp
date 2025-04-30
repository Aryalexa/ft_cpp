#include <map>
#include <iostream>

// first elem whose key is > k
void test_upper_g(const std::map<int, int> &m, int k) {
	std::map<int, int>::const_iterator it;
	it = m.upper_bound(k);
	std::cout << k << "-up->" << it->first << ": "<< it->second << std::endl;
}

// first elem whose key is >= k
void test_lower_g(const std::map<int, int> &m, int k) {
	std::map<int, int>::const_iterator it;
	it = m.lower_bound(k);
	std::cout << k << "-lo->" << it->first << ": "<< it->second << std::endl;
}

// last elem whose key is <= k
void test_lower_l(const std::map<int, int> &m, int k) {
	std::map<int, int>::const_iterator it;
	it = m.lower_bound(k);
	if (it->first == k)
		std::cout << k << "-->" << it->first << ": "<< it->second << std::endl;
	else {
		--it;
		std::cout << k << "-->" << it->first << ": "<< it->second << std::endl;
	
	}
}

int main() {

	std::map<int, int> mapi;
	mapi[1] = 10;
	mapi[3] = 30;
	mapi[4] = 40;

	test_upper_g(mapi, 0);
	test_upper_g(mapi, 1);
	test_upper_g(mapi, 2);
	test_upper_g(mapi, 3);
	test_upper_g(mapi, 4);
	test_upper_g(mapi, 5);

	test_lower_g(mapi, 0);
	test_lower_g(mapi, 1);
	test_lower_g(mapi, 2);
	test_lower_g(mapi, 3);
	test_lower_g(mapi, 4);
	test_lower_g(mapi, 5);

	test_lower_l(mapi, 0);
	test_lower_l(mapi, 1);
	test_lower_l(mapi, 2);
	test_lower_l(mapi, 3);
	test_lower_l(mapi, 4);
	test_lower_l(mapi, 5);

}