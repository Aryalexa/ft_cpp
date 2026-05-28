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

void RPN::apply_op(const std::string &operation) {
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
	} else {
        // This should never happen
        throw std::runtime_error("Unknown operation");
    }
}

bool RPN::to_num(const std::string &str, numType &num) {
	std::istringstream iss(str);
	iss >> num;
	if (!iss || !iss.eof()){
		return false;
	}
	return true;
}

bool RPN::in_set(const str_set &s, const std::string &str) {
	str_set::iterator it = s.find(str);
	if (it != s.end())
		return true;
	return false;
}

double RPN::solve(const std::string &expression) {
	std::ostringstream oss;
	std::istringstream iss(expression);
	std::string elem;
	numType num;
	while (!iss.eof()) {
		iss >> elem;
		if (!iss)
			throw std::runtime_error("input error");	
		//std::cout << "read " << elem << std::endl;
		if (in_set(OPERATIONS, elem) && st.size() > 1)
			apply_op(elem);
		else if (to_num(elem, num))
			st.push(num);
		else {
			oss << "bad format (" << elem << ")";
			throw std::runtime_error(oss.str());
		}
	}
	if (st.size() != 1)
		throw std::runtime_error("final value not reached");

	// get result and clean stack for next execution
	numType result = st.top();
	st = rpnStack(); // Clear stack for next execution
	return result;
}	
