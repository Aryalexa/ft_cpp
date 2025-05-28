#include <string>
#include <iostream>
#include <unistd.h> // getpid()
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include "Base.hpp"


Base* generate(void)
{
    srand(time(0) + getpid());
    int chosen = rand() % 3;
    switch (chosen)
    {
    case 0:
        return new A;
        break;
    case 1:
        return new B;
        break;
    default:
        return new C;
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
    
    std::cout << str;
}

// prints the type, arg is a reference

void identify(Base& p)
{
    using std::cout;
    try {
        (void)dynamic_cast<A&>(p);
        cout << "A";
        return;
    }
    catch(const std::exception& e) {}
    try {
        (void)dynamic_cast<B&>(p);
        cout << "B";
        return;
    }
    catch(const std::exception& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        cout << "C";
        return;
    }
    catch(const std::exception& e) {}
    cout << "error";
}

int main()
{
    Base *b;

    b = generate();

    std::cout << "identified pointer: ";
    identify(b);
    std::cout << std::endl;

    std::cout << "identified reference: "; 
    identify(*b);
    std::cout << std::endl;

    delete b;
}

