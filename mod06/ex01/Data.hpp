
#pragma once

#include <string>
#include <iostream>

// class Data
// {
// private:
//     int data_int;
//     std::string data_str;
// public:
//     Data();
//     Data(const Data &other);
//     Data &operator=(const Data &other);
//     ~Data();
// };

struct Data
{
    // public by default
    int i;
    double d;
    std::string str;
};