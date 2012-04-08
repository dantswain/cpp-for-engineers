# Part 1:  `int main`

The entry point for C and C++ programs is a function called `main`.  It turns out that we can start thinking about some useful ideas just by looking at some ways that we can use this structure.

FYI, if you're interested in a really deep look at what really happens here, take a look at the KSplice ["Hello from a libc-free world!"](https://blogs.oracle.com/ksplice/entry/hello_from_a_libc_free) blog post.  It's pretty neat, but pretty involved.

## Hello, World!

The hello world program in C++ looks like this:

```c++
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Hello, world." << std::endl;

    return 0;
}
```

You can find the [`helloworld.cpp`](part1/helloworld.cpp) file in this directory.  Compile and run it from the command line like this:

    g++ helloworld.cpp -o helloworld
    ./helloworld
    
A few things to note here.  First, `main` takes two arguments: `int argc` will be the command line argument count, and `char** argv` is the actual arguments.  Second, lots of tutorials would have you do `using namespace std` and then simplify the output line as
 
```c++
cout << "Hello, world." << endl;
```

I'm not going to do that.  Why?  Because one of my main points is going to be that **it's always worth a few extra keystrokes (and sometimes even a few extra CPU cycles) to write code that's more readable**.  You can learn more about [namespaces](http://www.cplusplus.com/doc/tutorial/namespaces/) at [cplusplus.com](http://cplusplus.com) if you want, but the take home message for right now is that using `std::cout` and `std::endl` makes it really clear that those functions, objects, or whatever they are, come from the same code module.

## Reusable Code

When you start writing a lot of programs that have a similar flavor, you start getting tired of repeating the same lines of code over and over again.  This idea is at the heart of good coding practice.  It's not just laziness, either.  It *does* make development faster when you can reuse code, but another huge benefit is maintainability.  Suppose you write 10 programs that use the same shared piece of code; then, when you improve that shared code, you're improving 10 programs all at once.

One of the maybe-not-so-obvious downsides of reusing code is that it necessarily makes the structure of the program more complicated.

Let's modify our "Hello, world" program in a pretty simple way by adding a function ([`helloworld_function.cpp`](part1/helloworld_function.cpp)).

```c++
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
```

It may not seem like much right now, but we *did* make this program a little harder to understand by shifting the 'work' to a function.  It's also pretty obvious that we've made this program a good deal more flexible, because we could change it to say just about anything we want by changing the text in `saySomething("Hello, world")`.  You can imagine that this could get much more complicated AND much more powerful pretty quickly.  This is a trade-off that we're going to have to deal with.

## Appplication Templates - Where did `int main` go?

This is one of the first hurdles that casual coders come across when starting to look at more complex projects.  It's a natural (and good!) instinct to try to understand a program from the top down by looking for `int main` and following the progression from there.  Unfortunately, this just doesn't work well on large projects. 

Here's a simple example of where `int main` can disappear pretty quickly.  Suppose we had to write a hundred programs, and all they did was output some text to the screen.  Every program would look like [`helloworld_function.cpp`](part1/helloworld_function.cpp), but with different text as an argument to the `saySomething` function.  Cutting to the chase, we could end up with something like [`say_prog.h`](part1/say_prog.h):

```c++
#include <iostream>

void saySomething(std::string message)
{
    std::cout << message << std::endl;
}

#define SAY_PROG(x) int main(int argc, char**argv){saySomething(x); return 0;}
```

And a program like [`sayHello.cpp`](part1/sayHello.cpp) that consists of two lines:

```c++
#include "say_prog.h"

SAY_PROG("Hello, world");
```

We've used a [preprocessor macro](http://www.cplusplus.com/doc/tutorial/preprocessor/) to create an application template, `SAY_PROG` that does all of the common stuff for us.  Again, we've gained a lot of flexibility at the cost of making `sayHello.cpp` harder to understand.  This is just a toy example - in the real world this specific example is probably not worth the obfuscation; I would just repeat the `int main` stuff and have a header file with my `saySomething` function.  However, this is a stepping stone to understanding some much more complicated examples.

The bottom line is that code reuse is A Good Thing and a principle motivator of code modularity, but that modularity necessarily makes code harder to understand from a top-down point of view.  We need to shift our thinking to a bottom-up approach; understand the building blocks of a program and you can often start to see how they fit together.  Better yet, you need not fully understand *all* of the building blocks in order to be able to make meaningful changes to *one* of them.

[back to main](/cpp-for-engineers)
