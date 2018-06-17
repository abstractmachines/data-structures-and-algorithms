# C++11

We will be using C++11 and the C++ Standard Library for our algorithms.

This section includes information on how to use modern C++ for algorithm
problem solving.

## Use the containers

Don't use strcpy() or strncpy(), use std::container.copy().

Don't use conditionals if nullptr, use std::container.empty().

### Use emplace over append
See Perfect Forwarding and Modern C++ by Scott Meyers.

## Use smart pointers instead of "new" whenever possible

In modern C++, we don't really use the "new" keyword very often. Instead, we
use smart pointers, because they're easier to manage and don't require as much
manual memory management. Raw pointers are the kinds of pointers we learned in
CS coursework: manually managed memory (new, malloc, delete, etc). Other
pointers that aren't "raw" are considered "smart" pointers, which "smartly
manage themselves" via constructs automating memory management for them.

### auto_ptr is deprecated
`auto_ptr`, in existence prior to C++11, should not be used in C++ Standard
Library std:: containers. That's because unless very carefully handled,
auto_ptrs leak memory. They have problematic copy semantics, and a problematic
copy constructor (recall the [C++ Rule of Three](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming))).

Speaking of copy semantics, an article on modern C++ and **Move Semantics** is
included here [from Stack Overflow](http://stackoverflow.com/questions/3106110/what-are-move-semantics).
It also covers information on L-Values and R-Values.

These topics all relate to pointers regarding **access.** With inter-process
communication (IPC) and inter-thread communication, controlled access is
important for critical code sections / critical paths in order to avoid race
conditions, so tools such as locks, mutexes, and semaphores are used to control
access. I won't be covering most of that information here.


| Pointer Type     | Memory management / access  | Notes |
| ---------------- |:--------------------------:|
| **Raw**              | Manually                               | malloc, free, new, delete |
| **Unique (smart)**   | Self-managed via ownership relationships  | A unique pointer cannot be shared, it can be "moved." That's how ownership is transferred. _std::unique_  _std::move()_ |
| **Shared (smart)**   | Self-managed via shared ownership and reference counting  | Many shared pointers can own one object. Atomic std:: ref counts.  _std::shared__ptr_  _make__shared()_|
| **Weak (smart)**   | Holds weak (non ownership) reference to shared_ptr's object  | For object tracking; must be converted to shared pointer to access object.  _std::weak__ptr_ |

Some good references:

- [University of Michigan PDF: C++ Smart Pointers](http://umich.edu/~eecs381/handouts/C++11_smart_ptrs.pdf)

- [Eli Bendersky](http://eli.thegreenplace.net/2012/06/20/c11-using-unique_ptr-with-standard-library-containers)


## Exceptions, Error Codes, Assertions

### Exceptions and error codes: recovery/continuation is desired
Exceptions and error handling are for situations in which control flow
interruptions are minimized and in which control flow happens as smoothly
as possible. Recovery - or reporting errors nicely to user - is the goal.

### Assertions : debugging tool to ensure program is running properly
Not a production-code construct. Used for debugging to tell whether the
program is running properly.

**Assert stops execution at the statement, for debugging.
Exceptions stop execution at the handler.**

### Use Exceptions for high-level use cases
Logic errors, etc. Exceptions unwind the stack.

##### Problems with exceptions: raw pointers and delete
Since exceptions alter the program control flow and using delete often depends
on a particular fall-through/control flow, delete may never get called if an
exception is caught and handled _before that delete can be called._

All the more justification for not using raw pointers.
**Use smart pointers. If you must use raw pointers, call delete in a destructor.**

##### Exception use cases
- Thing happens -> exception handled -> recover, continue execution
(or exit failure)
- Run time error conditions  
- "Out of memory"
- "File not Found"
- "Wrong data type entered"
- Always check arguments to public functions with exceptions

##### Exception best practices
- If you create your own class, inherit from std::exception. Study the
UML diagrams for std::exception. [cpp reference](http://en.cppreference.com/w/cpp/error/exception)
[tutorials point](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)
- You can throw bare integers or arrays but it's considered bad style; instead,
throw some variation of std::exception. Subclass it.
- If you absolutely have to use raw pointers, follow best practices and
place delete calls in the destructor.
- Validate input specifically: best practices
"I/O errors are not exceptional." Try to use the inherent qualities - aka the
virtual methods in istream base classes for cin subclass to validate input.
This includes std::cin.fail(), std::cin.clear() bits, std::cin.ignore() clear
buffers, and the istream >> operator doing type checking. See also, using
std::isAlpha() to validate std::string types, and getopt to validate and
parse command line args argc, argv.


### Use Error Codes for low-level system use cases requiring granularity
Error codes are commonly used in C and COM programming for explicit handling of
 "every" possible situation, and detail-oriented low-level reporting.  Error
 codes return an integer data type. `"Exit 0" success` and `"Exit 1"  failure`
 are integer error codes that low level/Linux systems programmers are accustomed
 to seeing.

Many C and COM programs also use globals to check error status after every
function invocation and check it against the last stack push.

Sometimes exceptions aren't always the answer (see "the exception that crashed
an airline").

##### Error code use cases
- Low level system calls return a type of abort/trap, and we want to know
exactly what occurred
- Distributed systems bus messages and statuses
- Wrong protocol / handshake
- Need full duplex, but only half duplex, etc (just an example)

### Use Assertions for debugging

#### Assertion use cases
- Debugging (not production)
- Assertions are used to check that things are operating properly.
- API / network not available
- Logic error in code


## Strings and streams

### std::cin

returns an istream object. [MSDN](https://msdn.microsoft.com/en-us/library/71t65ya2.aspx)

**EOFBit flag and cin.clear()**

cin looks for the end of file "signal" and terminates in response to EOF (upon discovering delimiter and/or n characters).

If that EOF is not discovered, cin sets an EOF bit flag. Use .clear() to clear that bit for future use of cin.

References:

•[Quora](https://www.quora.com/Can-you-explain-cin-ignore-and-cin-clear-for-C++-When-is-it-appropriate-to-use-these-How-do-they-effect-the-next-cin)

### std::stringstream

Associates a string with a stringstream object.

### Use Cases: Stringstream over cin

#### Use Case: for converting strings to numerical types
Why would I use a stringstream instead of cin?

Use Case: When you want to convert strings into numerical types.

Stringstream notable member functions include:

**Getter str()**

Get (return) the contents of its buffer in string type.

**Setter str(string)**

Set the the contents of the buffer with the string argument.


[Here is an example of how to use string streams, from Stack Overflow.](http://stackoverflow.com/questions/20594520/what-exactly-does-stringstream-do) :

```
std::ostringstream os;

os << "dec: " << 15 << " hex: " << std::hex << 15 << std::endl;

std::cout << os.str() << std::endl;
```
That's it.


## Const correctness

This is material taken from lectures with Michael Hoffman at Oregon Institute of Technology's Software Engineering in C++ courses. I've paraphrased it, but really this is Michael's work. He is definitely an authoritative source on C/C++.

Const is primarily used to prevent mutation; it can also be used for
polymorphism (function overloading).

### Const position and ordering : always read C++ right to left

The tradition is to place const last, and this is echoed in how const member functions are declared. However, placing const last isn't the only option.

[from Stack Overflow](http://stackoverflow.com/questions/15157113/position-of-const-keyword)

Read the rules from right to left:

`void * const ptr1;`
myPointer1 is a const pointer to void.

`void const *ptr2;`
myPointer2 is a pointer to a const void.

`const void *ptr3;`
myPointer3 is a pointer to a void const. This is the exact same thing as ptr2, the only difference is syntax.

`Object const * ptr4;`
ptr4 is a pointer to a const Object.

`Object const * const ptr5;`
ptr5 is a const pointer to a const Object.

```
void afunction(const char * const str1, char * const str2)
```
str1 is a const pointer to a const char. str2 is a const pointer to a char.

### Const variables / generics
```
const std::array<int, RANGE> arr const = {5,4,7,9,0,1,2,3,8,6};
```

### Const member functions : const must be declared on the right
```
class someClass
{
	public:
	int someInt() const;
}
```

### Const and polymorphism

Two member functions can be exactly the same except for the `const` keyword, and hence overloaded.

The function that is invoked depends on the const-ness of the calling object/context.

### Member-wise (bit-wise) constness
What: All data members must be preserved

How: **Member functions** declared with the `const keyword`.

### Logical constness
What: Objects can appear unchanged externally and be somewhat opaque, as implementations can alter the data for member variables as needed. This is generally done with efficiency in mind.

How: **Member variables** declared with the `mutable keyword`.

Member variables declared with the `mutable keyword` can be altered in const member functions!

## Casting
There are several types of casting:
- C style casting
- Static casting
- Dynamic casting
- Const casting

### Casting is "full duplex"

Casting can go from derived class to base class (intuitively clear), and also
from base class to derived class (less intuitive).

What is the difference between static and dynamic casting?
>Casting Review: Static and Dynamic casting:
Well, think about the names of those things. "Static" means at compile time, and "dynamic" means at run time. Now, what is casting? It's type changing. So, dynamic, type changes, means: determined latently - i.e. at runtime. And static means determined at compile time.

So, use static when you know the type, or can easily get the type. Use dynamic when it's inconvenient to do so.

### Code Samples
#### Static Casting
```
int staticCast(double d)
{
	int x = static_cast<int> (d);
	return x;
}

// main() :
char charToCast = 'z';

cout << typeid(charToCast).name(); // c (for char) <typeinfo>
cout << charToCast;                // z

int nowAnInt = cCast(charToCast);

cout << typeid(nowAnInt).name(); // i (for integer) <typeinfo>
cout << nowAnInt;                // 42
```

#### Dynamic Casting
TODO:  more on this soon

Notes of things to cover:
- polymorphism
- void pointers, function pointers
- RTTI Run Time Type Identification,
- latent/late/runtime

#### C Style Casting
```
int cCast(char c)
{
	int n = 42;
	c = ( char ) n; // or c = char ( n )

	return c;
}

// main():
double doubleToCast = 3.14;
cout << typeid(doubleToCast).name(); // d (for double) <typeinfo>
cout << doubleToCast;                // 3.14

int nowAnInt = staticCast(doubleToCast);

cout << typeid(nowAnInt).name(); // i (for integer) <typeinfo>
cout << nowAnInt;                // 3 (truncates)
```
