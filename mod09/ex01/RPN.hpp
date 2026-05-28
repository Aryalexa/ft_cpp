

#pragma once

#include <string>
#include <stack>
#include <sstream>
#include <set>
#include <iostream>

class RPN
{
private:
	typedef double numType;
	typedef std::stack<numType> rpnStack;
	typedef std::set<std::string> str_set;

	static rpnStack st;
	static str_set init_operations();
	static const str_set OPERATIONS;

	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	static bool in_set(const str_set &s, const std::string &str);
	static bool to_num(const std::string &str, numType &num);
	static void apply_op(const std::string &operation);

public:

	static double solve(const std::string &expression);
};
