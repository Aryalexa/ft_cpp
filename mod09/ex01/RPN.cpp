#include "RPN.hpp"

RPN::str_set RPN::init_operations() {
    RPN::str_set s;
    s.insert("+");
    s.insert("-");
    s.insert("*");
    s.insert("/");
    return s;
}

const RPN::str_set RPN::OPERATIONS = RPN::init_operations();
RPN::rpnStack RPN::st;

void RPN::apply_op(std::string operation) {
	numType num1, num2;

	num2 = st.top();
	st.pop();
	num1 = st.top();
	st.pop();

	if (operation == "+")
		st.push(num1 + num2);
	else if (operation == "-")
		st.push(num1 - num2); 
	else if (operation == "*")
		st.push(num1 * num2); 
	else if (operation == "/") {
		if (num2 == 0)
			throw std::runtime_error("div by zero");	
		st.push(num1 / num2); 
	}
}

bool RPN::is_num(std::string str, numType *num) {
	std::istringstream iss(str);
	iss >> *num;
	if (!iss || !iss.eof()){
		//std::cout << "isnum: false" << std::endl;
		return false;
	}
	//std::cout << "is_num: true" << std::endl;
	return true;
}

bool RPN::in_set(str_set s, std::string str) {
	str_set::iterator it = s.find(str);
	if (it != s.end())
		return true;
	return false;
}

double RPN::solve(std::string expression) {
	std::ostringstream oss;
	std::istringstream iss(expression);
	std::string elem;
	numType num;
	while (!iss.eof()) {
		iss >> elem;
		if (!iss)
			throw std::runtime_error("bad format");	
		//std::cout << "read " << elem << std::endl;
		if (in_set(OPERATIONS, elem) && st.size() > 1)
			apply_op(elem);
		else if (is_num(elem, &num))
			st.push(num);
		else {
			oss << "bad format (" << elem << ")";
			throw std::runtime_error(oss.str());
		}
	}
	if (st.size() != 1)
		throw std::runtime_error("final value not reached");	
	// return last remaining num
	return st.top();
}	
