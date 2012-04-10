/* g++ shortcircuit.cpp -o shortcircuit */

#include <iostream>

bool trueFunction(){ std::cout << "trueFunction "; return true; };
bool falseFunction(){ std::cout << "falseFunction "; return false; };

int main(int argc, char** argv)
{
    std::cout << "trueFunction && falseFunction: ";
    trueFunction() && falseFunction();
    std::cout << std::endl;

    std::cout << "falseFunction && trueFunction: ";
    falseFunction() && trueFunction();
    std::cout << std::endl;

    std::cout << "trueFunction || falseFunction: ";
    trueFunction() || falseFunction();
    std::cout << std::endl;

    std::cout << "falseFunction || trueFunction: ";
    falseFunction() || trueFunction();
    std::cout << std::endl;

    return 0;
}
