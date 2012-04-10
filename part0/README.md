# Part 0

This part of the tutorial covers some ideas that are specific to programming in C++ (and C, in some cases) that you may or may not have already come across if you have experience programming in other languages.  These ideas aren't necessarily simple, but you also might not need to fully understand them in order to continue.  My intention is that you can skim or skip this part of the tutorial now, but may want to come back to it from time to time for reference.

## Rules were made to be broken

People will give you lots of rules when you're programming.  Never use global variables, always initialize pointers to NULL, never use the goto statement, etc.  These are good rules, and you should, by and large, follow them.

Don't, however, follow them blindly.  There are very good reasons to break almost every programming "rule".  

On the other hand, break these rules **sparingly**.  People say these things for good reasons.  If you think, "This would be a lot easier if I could just use a global variable." that's probably not a good enough reason to break that rule.  If, however, you consider the options carefully and come to the conclusion that using a global variable really is the best design decision, then don't fail to make the right design decision just because someone has told you very sternly never to use global variables.

The more experience you get, the less you'll break the rules, but you'll be more confident that you did the right thing when you do.

## Variable initialization (Don't count on x = 0)

On some systems, numeric variables are always initialized as zero.  For example,

```C++
int x;
int y = 42;

printf("x + y = %d\n", x + y);
```

will print out `x + y = 42` on some systems.  This may seem convenient, but in the long run it's not.  What happens when you compile that code on a system that *doesn't* initialize `x` to zero automatically?  You never know!  It could be anything - it's literally undefined behavior.

"That's not a big deal, I just have to remember to set `x` to the right value before I use it.", you might say.  That works.  Until you forget.  And then you spend a day trying to track down a bug because you forgot.  

One of the main ideas that I'm going to try to hammer into you throughout this tutorial is that spending a little time now can save you a ton of time later.  So get in the habbit of doing `int x = 0;`.  It's worth an extra three keystrokes!

This will also be really important for initializing pointers (which I'll discuss below) and class member variables (which I'll address later, when I talk about classes).

## Short-circuit evaluation

This can run the range from being a neat trick, to causing infuriatingly hard to find bugs, to being a way to write really elegant code.

C and C++ give us something called [short-circuit evaluation](http://en.wikipedia.org/wiki/Short-circuit_evaluation)for the logical `and` and `or` operators: `&&` and `||`, respectively.  For simple logical operations, these operators do just what you would expect:

```C++
bool a = true;
bool b = false;

a && b; // true AND false = false
a || b; // true OR false = true
```

It gets interesting when `a` and `b` are replaced with function calls.  Short-circuit evaluation means that the program will only evaluate `b` if it *has to*.   In `a && b`, if `a` is false (or evaluates to false), then it doesn't matter what value `b` has (or evaluates to).  The result is always false.  In fact, if `a` is true, then `b` gets completely ignored.  Similarly, in `a || b`, if `a` is true, then `b` is ignored.

You can use this to your advantage, but always be careful with it.  Suppose you're writing a function to shut down an industrial machine, and this function should return true if the shutdown was successful and false otherwise.  You might do something like the following.

```C++
bool emergencyStop()
{
    return turnOffLights() && stopMachine();
}
```

But if `turnOffLights()` fails and returns false, then `stopMachine()` will never get called and someone might get hurt!  OK, that's a contrived example, but it's surprisingly easy to trap yourself this way.  On the other hand, you can use short-circuit evaluation to your benefit.  Suppose you're writing a function to check the feasibility of some numerical problem, and that there are two known checks for feasibility: one is a necessary but not sufficient condition that is computationally very inexpensive, and the other is necessary AND sufficient but very computationally expensive.  If the first test fails, then there's no need to perform the second test, which could take a long time to perform.  In that case, you could use short-circuit logic to write the test very elegantly.

```C++
bool checkFeasibility()
{
    return easyCheck() && hardCheck();
}
```

Take a look at [`shortcircuit.cpp`](part0/shortcircuit.cpp) for some simple examples.

## Magic numbers (Don't use them)

"Magic number" can mean a few different things in programming ([wikipedia](http://en.wikipedia.org/wiki/Magic_number_(programming))).  What I'm talking about here are [unnamed numeric constants](http://en.wikipedia.org/wiki/Magic_number_\(programming\)#Unnamed_numerical_constants).  The wikipedia article has a pretty good explanation, so I won't repeat it here.  My goal here is just to make you aware of the idea.  So don't do it.

Along the same lines, use expressive variable names whenever you can, even if they're longer to type.

As usual, spending a little time up front will save you a bunch of time later on when you're looking at your code and trying to remember what `x = y*86400;` does when `seconds = days*seconds_in_a_day;` is *much* clearer.

## Header Files and Header Guards

## Pointers (Aren't that bad)

## Initialize Pointers to NULL!!!!!!11!!1
