#include <iostream>
#include "app.hpp"

int main(int argc, char **argv)
{
    lock::App app{};
    return app.parse(argc, argv);
}
