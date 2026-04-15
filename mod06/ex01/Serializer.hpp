
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
    /**
     * serialize: convert a pointer to an integer type that can hold
     * a pointer without loss. uintptr_t is the correct unsigned integer
     * type for this purpose (portable integer representation of an address).
     */
    static uintptr_t serialize(Data* ptr);
    static Data *deserialize(uintptr_t raw);
};
