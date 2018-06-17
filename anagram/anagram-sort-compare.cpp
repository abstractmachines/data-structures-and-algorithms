/*
Determine that two strings are an anagram.

Solution 1 : sort each string and then compare using built-in std::string
operator overloading for comparison operators.

Good: easy to code

Bad: inefficient! Each of those sort() functions are O(n) or worse.

See part 2:
counting the frequency of each element: Hashing !
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <locale>

bool getBetterInput(std::string & s)
{
	std::string::iterator it;
	std::locale loc;

	bool needBetterInput = true;

	while(needBetterInput)
	{
		std::cout<<"\nEnter string:\n";
		std::cin >> s;

		for(it = s.begin(); it != s.end(); ++it)
		{
			if(!std::isalpha(*it,loc))
			{
				std::cout<<"\nNeed better input.";
				needBetterInput = true;
			}
			else
			{
				needBetterInput = false;
			}
		}
	}
	return needBetterInput;
}

bool sortInput( std::string & s1, std::string & s2)
{
	std::sort(s1.begin(),s1.end());
	std::sort(s2.begin(),s2.end());
	return ( s1 == s2 );
		// == () );
}

int main()
{
	std::string s1;
	std::string s2;
	bool needBetterInput;
	bool isAnagram;

	needBetterInput = getBetterInput(s1);

	needBetterInput = getBetterInput(s2);

	std::cout<<"s1: " << s1 <<" s2: " << s2 << "\nLet's sort\n:";

	isAnagram = sortInput(s1,s2);

	if(isAnagram)
	{
		std::cout<<"\nYES.";
	}
	else
	{
		std::cout<<"\nNO.";
	}

	return 0;
}
