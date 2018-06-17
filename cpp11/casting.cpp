/* Algorithms in C++ by Amanda Falke:

Casting

compile: $ g++ casting.cpp -Wall -std=c++11

TODO: void * polymorphic printing function

Expected Output :

********Casting********

----> C style cast: Double to Int.

From: Type d Value: 3.14
To  : Type i Value: 3


----> C++ static cast: Char to Int.

From: Type c Value: z
To  : Type i Value: 42

*/


#include <iostream>
#include <algorithm>
#include <functional>
#include <typeinfo>


int cCast(char c)
{
	int n = 42;
	c = ( char ) n; // or c = char ( n )

	return c;
}

int staticCast(double d)
{
	int x = static_cast<int> (d);
	return x;
}

int dynamicCast(double d)
{
	int x = static_cast<int> (d);
	return x;
}

void printPolyMorph(void * )
{
	// for all types.
}

int main ()
{
	double doubleToCast = 3.14;

	int nowAnInt = staticCast(doubleToCast);

	std::cout
		<<"\n\n********Casting********"
		<<"\n\n----> C style cast: Double to Int. \n\n"

		/* TODO: DRY
			place this section in a polymorphic print val + type function
			with void * params
		*/
		<<"From: Type " << typeid(doubleToCast).name() << " Value: " <<doubleToCast
		<<"\nTo  : Type " << typeid(nowAnInt).name() << " Value: " <<nowAnInt << std::endl; // 3

	char charToCast = 'z';

	int nowAnIntToo = cCast(charToCast);

	// TODO: DRY
	std::cout
		<<"\n\n----> C++ static cast: Char to Int. \n\n"

		<<"From: Type " << typeid(charToCast).name() << " Value: " <<charToCast
		<<"\nTo  : Type " << typeid(nowAnIntToo).name() << " Value: " <<nowAnIntToo << std::endl; // 3

	return 0;
}
