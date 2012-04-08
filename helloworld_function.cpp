/* compile: g++ helloworld_function.cpp -o helloworld_function */

#include <iostream>

void saySomething(std::string message)
{
    std::cout << message << std::endl;
}

int main(int argc, char** argv)
{
    saySomething("Hello, world");

    return 0;
}
