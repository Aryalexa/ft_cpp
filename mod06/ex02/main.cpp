#include <string>
#include <iostream>
#include <cstdlib>  // rand(), srand()
#include "Base.hpp"


Base* generate(void)
{
    int chosen = rand() % 3;
    switch (chosen)
    {
    case 0:
        return new A;
        break;
    case 1:
        return new B;
        break;
    case 2:
        return new C;
        break;
    default:
        break;
    }
    return NULL;
}

// prints the type, arg is a pointer
void identify(Base* p)
{
    std::string str;
    if (dynamic_cast<A *>(p) != NULL)
        str = "A";
    else if (dynamic_cast<B *>(p))
        str = "B";
    else if (dynamic_cast<C *>(p))
        str = "C";
    else
        str = "error";
    
    std::cout << str << std::endl;
}

// prints the type, arg is a reference

void identify(Base& p)
{
    using std::cout;
    using std::endl;
    try
    {
        (void)dynamic_cast<A&>(p);
        cout << "A" << endl;
        return;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        cout << "B" << endl;
        return;
    }
    catch(const std::exception& e)
    {}
    try
    {
        (void)dynamic_cast<C&>(p);
        cout << "C" << endl;
        return;
    }
    catch(const std::exception& e)
    {}
    cout << "error" << endl;
}

int main()
{
    Base *b;

    b = generate();

    identify(b);
    identify(*b);

}

