
#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdlib.h>

class ScalarConverter
{
/* making it not instantiable */
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(const std::string &str);
};
