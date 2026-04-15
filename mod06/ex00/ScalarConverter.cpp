#include "ScalarConverter.hpp"

static const int PRECISION = 1;
static const bool INFO = false;

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::~ScalarConverter()
{
}
/** CONVERSION *************************/

static int to_int(const std::string &str)
{
	int i = std::atoi(str.c_str());
	return i;
}

static float to_float(const std::string &str)
{
	double d = std::atof(str.c_str());
	float f = static_cast<float>(d);
	return f;
}

static double to_double(const std::string &str)
{
	double d = std::atof(str.c_str());
	return d;
}

/** CHECKS *************************/

static bool is_char(const std::string &str)
{
	return (str.length() == 3 
		&& *str.begin() == '\'' && *str.rbegin() == '\''
		&& std::isprint(str[1])) ||
		(str.length() == 1 && std::isprint(str[0]));
}

static bool is_print(int c)
{
	return (c >= 32 && c <= 126);
}

/**
 * check if the string is numeric, 
 * one minus or one plus sign are allowed at the beginning,
 * points are allowed.
 * 
 * BUT the number of points is not controlled
 */
static bool is_numeric(const std::string &str)
{
	unsigned long i = 0;
	if (str[i] == '-' || str[i] == '+') i++;
	if (str.length() - i <= 0)
		return false;
	for (; i < str.length(); i++)
		if (!std::isdigit(str[i]) && str[i] != '.')
			return false;
	return true;
}

static bool is_int(const std::string &str)
{
	// numeric
	if (!is_numeric(str))
		return false;
	// no points
	if (str.find('.') != std::string::npos)
		return false;
	// check limits
	double d = to_double(str);
	if (d > std::numeric_limits<int>::max())
		return false;
	if (d < std::numeric_limits<int>::min())
		return false;
	
	return true;
}

static bool is_float(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	// ends with an 'f'
	if (*str.rbegin() != 'f')
		return false;
	// trim the 'f'
	std::string numstr = str.substr(0, str.length() - 1);
	// numeric
	if (!is_numeric(numstr))
		return false;
	// contains 0 or 1 decimal point only
	if (numstr.find('.') != std::string::npos)
	{
		std::size_t point_pos = numstr.find('.');
		std::string second_part = numstr.substr(point_pos + 1);
		if (!second_part.empty() && second_part.find('.') != std::string::npos)
			return false;
	}
	// check limits
	long double d = to_double(numstr);
	if (d > std::numeric_limits<float>::max())
		return false;
	if (d < - std::numeric_limits<float>::max())
		return false;
	return true;
}

static bool is_double(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	// numeric
	if (!is_numeric(str))
		return false;
	// contains 0 or 1 decimal point only
	if (str.find('.') != std::string::npos)
	{
		std::size_t point_pos = str.find('.');
		std::string second_part = str.substr(point_pos + 1);
		if (!second_part.empty() && second_part.find('.') != std::string::npos)
			return false;
	}
	return true;
}

/** DISPLAY *************************/

static void display(double d, int precision = PRECISION)
{
	using std::cout;
	using std::endl;
	using std::fixed;
	using std::setprecision;

	if (d > std::numeric_limits<int>::max() || 
		d < std::numeric_limits<int>::min())
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
	}
	else
	{
		int i = static_cast<int>(d);
		cout << "char: ";
		if (is_print(i))
			cout << "'" << static_cast<char>(i) << "'" << endl;
		else
			cout << "Non displayable" << endl;		
		cout << "int: ";
		cout << i << endl;
	}
	cout << "float: ";
	cout << fixed << setprecision(precision)
		<< static_cast<float>(d) << "f" << endl;
	cout << "double: ";
	cout << fixed << setprecision(precision) 
		<< d << endl;
}

static void display_nan()
{
	using std::cout;
	using std::endl;

	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	cout << "float: nanf" << endl;
	cout << "double: nan" << endl;
}

static void display_inf()
{
	using std::cout;
	using std::endl;

	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	cout << "float: +inff" << endl;
	cout << "double: +inf" << endl;
}

static void display_minus_inf()
{
	using std::cout;
	using std::endl;

	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	cout << "float: -inff" << endl;
	cout << "double: -inf" << endl;
}

/** count decimals after '.' in an input string (does not consider trailing 'f') */
static int count_decimals_from_input(const std::string &s)
{
	std::size_t pos = s.find('.');
	if (pos == std::string::npos)
		return 0;
	return static_cast<int>(s.length() - pos - 1);
}

/** PROCESS *************************/

static void handle_char(char c)
{
	if (INFO) std::cout << "✨char!✨" << std::endl;
	display(static_cast<int>(c));
}

static void handle_int(const std::string &str)
{
	if (INFO) std::cout << "✨int!✨" << std::endl;
	int i = to_int(str);
	display(i);
}

static void handle_float(const std::string &str)
{
	if (INFO) std::cout << "✨float!✨" << std::endl;
	if (str == "+inff")
		display_inf();
	else if (str == "-inff")
		display_minus_inf();
	else if (str == "nanf")
		display_nan();
	else
	{
		float f = to_float(str);
		int precision = PRECISION;
	// determine decimals from input (trim trailing 'f')
	std::string numstr = str.substr(0, str.length() - 1);
	int decimals = count_decimals_from_input(numstr);
	precision = (decimals == 0) ? 1 : decimals;
		display(f, precision);
	}
}

static void handle_double(const std::string &str)
{
	if (INFO) 
	{
		std::cout << "✨double!✨" << std::endl;
		// check limits
		if (str.length() > 16)
			std::cout << "Warning: may be losing precision" << std::endl;
	}
	if (str == "+inf")
		display_inf();
	else if (str == "-inf")
		display_minus_inf();
	else if (str == "nan")
		display_nan();
	else
	{
		double d = to_double(str);
		int precision = PRECISION;
	int decimals = count_decimals_from_input(str);
	precision = (decimals == 0) ? 1 : decimals;
		display(d, precision);
	}
}

/** convert *************************/
void ScalarConverter::convert(const std::string &str)
{
	
	if (is_int(str))
		handle_int(str);
	else if (is_float(str))
		handle_float(str);
	else if (is_double(str))
		handle_double(str);
	else if (is_char(str))
	{
		if (str.length() == 3)
			handle_char(str[1]);
		else if (str.length() == 1)
			handle_char(str[0]);
	}
	else
		std::cout << "not supported❌" << std::endl;
}
