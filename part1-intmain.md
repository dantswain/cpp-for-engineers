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
    
A few things to note here.  First, `main` takes two arguments: `int argc` will be the command line argument count, and `char** argv` is the actual arguments.  Second, lots of tutorials would have you do `using namespace std` and then simplify the output line as
 
```c++
cout << "Hello, world." << endl;
```

I'm not going to do that.  Why?  Because I want you to get in the habit of writing code that's readable at the expense of using more keystrokes.  You can learn more about [namespaces](http://www.cplusplus.com/doc/tutorial/namespaces/) at [cplusplus.com](http://cplusplus.com) if you want, but the take home message for right now is that using `std::cout` and `std::endl` makes it really clear that those functions, objects, or whatever they are, come from the same code module.
