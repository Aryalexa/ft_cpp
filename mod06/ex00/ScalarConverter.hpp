
#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdlib.h>

class ScalarConverter
{
/* making it not instatiable */
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(std::string str);
};




