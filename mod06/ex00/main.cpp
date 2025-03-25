#include "ScalarConverter.hpp"

void test(std::string str)
{
    std::cout << "🍊 input: " << str << std::endl;
    ScalarConverter::convert(str);
}

void tests()
{
    std::cout << "-----TESTS-----" << std::endl;

    test("'c'");
    test("'a'");
    test("'0'");
    test(" '0'");
    test("'0' ");


    test("23");
    test("999991111199999");
    test("-56");
    test("-");
}

int main(int argn, char *argv[])
{
    if (argn != 2)
    {
        std::cout << "Expected one argument" << std::endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);

    tests();
    return 0;
}