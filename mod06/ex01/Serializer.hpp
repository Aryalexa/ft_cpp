
#pragma once

#include <string>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
/* making it not instatiable */
private:
    Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data *deserialize(uintptr_t raw);
};
