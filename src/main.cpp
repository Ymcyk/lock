#include <iostream>
#include "lock/safe.hpp"

int main()
{
    if (lock::example())
    {
        std::cout << "example is true\n";
    }
}
