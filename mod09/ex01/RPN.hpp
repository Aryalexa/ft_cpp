

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

	static bool in_set(str_set s, std::string str);
	static bool is_num(std::string str, numType *num);
	static void apply_op(std::string operation);

public:

	static double solve(std::string expression);
};
