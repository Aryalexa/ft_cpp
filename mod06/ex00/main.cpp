#include "ScalarConverter.hpp"

void test(std::string str)
{
    std::cout << "🍊 input: " << str << std::endl;
    ScalarConverter::convert(str);
}

void tests()
{
    std::cout << "-----TESTS-----" << std::endl;


    std::cout << "-----🍁-----" << std::endl;
    test("a"); // 97
    test("'a'"); // 97
    test("c"); // 99
    test("'c'"); // 99
    test("'0'"); // 48

    std::cout << "-----🍁-----" << std::endl;
    test("23");
    test("-56");
    test("+36");
    test("2147483647");
    test("0");

    std::cout << "-----🍁-----" << std::endl;
    test("102.3f");
    test("102.33333333f");
    test("108f");
    test("-88f");
    test("+inff");
    test("nanf");
    test("-inff");
    test("999000999000f");// < int overflows

    std::cout << "-----🍁-----" << std::endl;
    test("1.0");
    test("-88.0");
    test("1.232323232323");
    test("999991111199999"); // < int overflows
    test("99999111119999911111"); // < int overflows
    test("+inf");
    test("-inf");
    test("nan");
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

    //tests();
    return 0;
}