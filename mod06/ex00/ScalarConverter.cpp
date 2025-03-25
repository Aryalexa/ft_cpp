#include "ScalarConverter.hpp"

static const int PRECISION = 1;
static const std::string OK = "ok";

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::~ScalarConverter()
{
}
static bool is_number(std::string str)
{
	unsigned long i = 0;
	if (str[i] == '-') i++;
	if (str.length() - i <= 0)
		return false;
	for (; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}
static double to_ldouble(std::string str)
{
	double converted = std::atof(str.c_str());
	return converted;
	// double	number = 0;
	// int	sign = 1;

	// int i = 0;
	// if (str[i] == '-' || str[i] == '+')
	// {
	// 	if (str[i] == '-')
	// 		sign = sign * (-1);
	// 	i++;
	// }
	// while (std::isdigit(str[i]))
	// {
	// 	number = number * 10 + sign * (str[i] - '0');
	// 	i++;
	// }
	// return (number);
}
static int to_int(std::string str)
{
	int	number = 0;
	int	sign = 1;

	int i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (std::isdigit(str[i]))
	{
		number = number * 10 + sign * (str[i] - '0');
		i++;
	}
	return (number);
}

// static float to_float(std::string str)
// {
// 	float number = 0;
// 	int	sign = 1;

// 	int i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = sign * (-1);
// 		i++;
// 	}
// 	while (std::isdigit(str[i]))
// 	{
// 		number = number * 10 + sign * (str[i] - '0');
// 		i++;
// 	}
// 	return (number);
// }

static bool is_int(std::string str)
{
	// numeric with optional minus sign
	if (!is_number(str))
		return false;
	// no points
	if (str.find('.') != std::string::npos)
		return false;
	// check limits
	double d = to_ldouble(str);
	if (d > std::numeric_limits<int>::max())
		return false;
	if (d < std::numeric_limits<int>::min())
		return false;
	
	return true;
}

// static bool is_float(std::string str)
// {
// 	// numeric with optional minus sign
// 	if (!is_number(str))
// 		return false;
// 	// only one point
// 	if (str.find('.') != std::string::npos)
// 	{
// 		std::size_t point_pos = str.find('.');
// 		std::string second_part = str.substr(point_pos + 1);
// 		if (!second_part.empty() && second_part.find('.') != std::string::npos)
// 			return false;
// 	}
// 	// check limits
// 	long double d = to_ldouble(str);
// 	if (d > std::numeric_limits<float>::max())
// 		return false;
// 	if (d < std::numeric_limits<float>::min())
// 		return false;
	
// 	return true;
// }

static void display(
	std::string msg_c, char c,
	std::string msg_i, int i, 
	std::string msg_f, float f, 
	std::string msg_d, double d)
{
	using std::cout;
	using std::endl;
	using std::fixed;
	using std::setprecision;

	cout << "char: ";
	if (msg_c == OK)
		cout << "'" << c << "'" << endl;
	else
		cout << msg_c << endl;
	cout << "int: ";
	if (msg_i == OK)
		cout << i << endl;
	else
		cout << msg_i << endl;
	cout << "float: ";
	if (msg_f == OK)
		cout << fixed << setprecision(PRECISION) << f << "f" << endl;
	else
		cout << msg_f << endl;
	cout << "double: ";
	if (msg_d == OK)
		cout << fixed << setprecision(PRECISION) << d << endl;
	else
		cout << msg_d << endl;
}

static void treat_char(char c)
{
	using std::cout;
	using std::endl;
	using std::fixed;
	using std::setprecision;

	display(
		OK, c,
		OK, static_cast<int>(c),
		OK, static_cast<float>(c),
		OK, static_cast<double>(c)
	);
}

static void treat_int(std::string str)
{
	int i = to_int(str);

	char c = 0;
	std::string msg_c = OK;
	if (std::isprint(i))
		c = static_cast<char>(i);
	else
		msg_c = "Non displayable";

	display(
		msg_c, c,
		OK, i,
		OK, static_cast<float>(i),
		OK, static_cast<double>(i));
}




void ScalarConverter::convert(std::string str)
{
	if (str.length() == 3 && *str.begin() == '\'' && *str.rbegin() == '\''
		&& std::isprint(str[1]))
		treat_char(str[1]);
	else if (is_int(str))
		treat_int(str);
	else
		std::cout << "not impl" << std::endl;
	
}
