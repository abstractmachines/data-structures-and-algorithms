/*
Determine that two strings are an anagram.

Solution 2: more efficient than solution 1 of multiple calls to sort()
counting the frequency of each element: Hashing !

Our algorithm:
counting the frequency of each element:

insert each element into a HashSet ( average O(1) insert() or emplace(),
and note that O(1) is really only O(n) in case of rehashing, which
can be reduced by designing with Capacity and Load Factors in mind! )

(use count() method for HashSet std::unordered_multiset container!)

Then, dump that into an array, and sort the array using binary search!

that's log n for the binary search!

So O(1) for the hash insert,
and O(k) for the count() proportional to k keys, but could be O(n) for size of container,

and log n for the binary search,

So maybe k log n at the VERY most!


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <locale>
//
// bool getBetterInput(std::string & s)
// {
// 	std::string::iterator it;
// 	std::locale loc;
//
// 	bool needBetterInput = true;
//
// 	while(needBetterInput)
// 	{
// 		std::cout<<"\nEnter string:\n";
// 		std::cin >> s;
//
// 		for(it = s.begin(); it != s.end(); ++it)
// 		{
// 			if(!std::isalpha(*it,loc))
// 			{
// 				std::cout<<"\nNeed better input.";
// 				needBetterInput = true;
// 			}
// 			else
// 			{
// 				needBetterInput = false;
// 			}
// 		}
// 	}
// 	return needBetterInput;
// }
//
// bool sortInput( std::string & s1, std::string & s2)
// {
// 	std::sort(s1.begin(),s1.end());
// 	std::sort(s2.begin(),s2.end());
// 	return ( s1 == s2 );
// 		// == () );
// }

int main()
{
	std::string s1;
	std::string s2;
	bool needBetterInput;
	bool isAnagram;
	//
	// needBetterInput = getBetterInput(s1);
	//
	// needBetterInput = getBetterInput(s2);
	//
	// std::cout<<"s1: " << s1 <<" s2: " << s2 << "\nLet's sort\n:";
	//
	// isAnagram = sortInput(s1,s2);
	//
	// if(isAnagram)
	// {
	// 	std::cout<<"\nYES.";
	// }
	// else
	// {
	// 	std::cout<<"\nNO.";
	// }

	return 0;
}
