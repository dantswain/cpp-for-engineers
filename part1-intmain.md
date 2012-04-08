# Part 1:  `int main`

The entry point for C and C++ programs is a function called `main`.  The hello world program in C++ looks like this:

```c++
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Hello, world." << std::endl;

    return 0;
}
```

You can find the [`helloworld.cpp`](helloworld.cpp) file in this directory.  Compile and run it from the command line like this:

    g++ helloworld.cpp -o helloworld
    ./helloworld
    
    
