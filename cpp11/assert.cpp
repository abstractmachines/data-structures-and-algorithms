/*
compile with C++11: $ g++ assert.cpp -std=c++11

Expected result: a will pass when assert(), b will fail when assert()

Expected output:
Assert will throw an exception and exit program if false.

Integer is assigned: 42.assert(x == 42).

Assertion failed: (x == 42), function assertIt, file assert.cpp, line 22.
Integer is assigned: 2.assert(x == 42).Abort trap: 6

*/

#include <iostream>
#include <assert.h>

void print(int x)
{
	std::cout <<"\n\nInteger is assigned: " << x << ".";
	std::cout<<"assert(x == 42).";
}

void assertIt(int x)
{
	assert(x == 42);
}

int main()
{
	std::cout <<"\nAssert will throw an exception and exit program if false.";

	int a = 42;
	print(a);
	assertIt(a);

	int b = 2;
	print(b);
	assertIt(b);

	return 0;
}
