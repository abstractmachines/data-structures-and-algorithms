/*

Problem statement:
- Write a function that takes an array and size as a parameter.
- The array contains non-negative numbers.
- Every number in the array appears an even number of times, except for one
 number that appears an odd number of times.
- The function should return the number that appears an odd number of times.
*/

/********  Amanda's notes: ***********
I'm going to give sample input for a starting point.

For given input: 1 2 1 2 4 2 4
Expected output : 2

Modulus operation

From interview: writing/thinking on the spot:
Option 1: Counting Sort algorithm option:
    Probably more efficient than a hashtable for large data ranges.

Option 2: hash structure to count occurrences in buckets.
Less efficient for extremely large data sizes

Going with the hash structure for now...
*/

#include <iostream>
#include <array>
#include <unordered_set>

#define SIZE 7

int returnOddOccurrence(std::array<int,SIZE> & arr)
{
	int oddMod = 0;

	std::unordered_multiset<int> bag;
	/* originally I used an unordered_map here during the interview, w/ logic of
	"key: number itself. value = numOccurrences."
	However, that's non-ideal, as C++ Standard Library
	associative structures have a count() method returning numoccurrences.
	Hence:
	1. an associative key-value pair data structure is unnecessary, as built in
	performant functions will return count of Bag non-Set data structures;
	2. a Set would not work, because that's unique values only, so count()
	method deals with 1/unique logic. So, use a Bag (Multiset), and count().
	*/
	std::array<int, SIZE>::iterator it;
	std::unordered_multiset<int>::iterator hashIt;

	// same as interview; C++ containers (and Java Collections) are fairly uniform
	for( it = arr.begin(); it != arr.end(); ++it )
	{
		bag.insert(*it); // hash, an unordered O(1) insert. Same as interview.
	}

	/* Rather than conditionals here, such as if unordered associative C++
	container's find() function returns true, then increment the
	container->second numOccurrences, how about just use count() method? :)
	*/
	for( auto x:bag )
	{
		if( bag.count(x) % 2 != 0 )
		{
			oddMod = x;
		}
	}
	return oddMod;
}

int main()
{
	std::array<int,SIZE> bag;
	bag = {1,2,1,2,4,2,4};

	int result = returnOddOccurrence(bag);

	std::cout<<"\nReturn the single integer from a set that permutes an odd "
	<<"number of times.\n\nFor given input 1,2,1,2,4,2,4\n\nExpected output: 2\n\n";

	std::cout<<"\nActual output: " << result << std::endl;

	return 0;
}
