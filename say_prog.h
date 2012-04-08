#include <iostream>

void saySomething(std::string message)
{
    std::cout << message << std::endl;
}

#define SAY_PROG(x) int main(int argc, char**argv){saySomething(x); return 0;}
