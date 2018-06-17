/* Part 2:
Now that you've solved the problem very well with a linear time algorithm,
interviewer changes it up/levels it up!

"I can no longer guarantee that the collection of numbers is ordered."

Solution: Implement a HashSet (not a HashTable, because there are no key-value
pairs), and add the complements of each item.

sum - this item = complement

Then when you're looking at a new number, you're asking if that number is
already a KNOWN COMPLEMENT of the number you're looking at.

That is an incredibly interesting
solution and can be viewed here:
https://www.youtube.com/watch?v=XKu_SEDAykw
*/

/* Seems like there's something missing with the logic regarding
complement items, will investigate this later.
*/

// g++ pair-sum-unordered.cpp -std=c++11

#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>

#define ARR_SIZE 10

bool pairSumFound(const std::vector<int> & v, int sum)
{
	bool foundPairSum = false;

	int  low = v[0];
	int  high = v[v.size() - 1];
	std::cout<<"\nLow =  " << low <<"\nHigh = " << high <<std::endl;

	// while not same index, scan --> <--
	while(low < high)
	{
		int s = low + high;

		if(s == sum)
		{
			std::cout<<"\nFound pair at Low = " << low << ", High = " << high
			<<"\n" <<"s: " << s <<" == sum: " << sum << std::endl;
			return true;
		}

		else if(s > sum)
		{
			--high;
		}
		else if(s < sum)
		{
			++low;
		}
	}

	return foundPairSum;
}

bool runTest(const std::vector<int> & v, const int sum)
{
	bool wasFound = false;

	for( auto x:v)
	{
		std::cout<< x << std::endl; // x* ?
	}

	wasFound = pairSumFound(v, sum);

	return wasFound;
}

void printStatus(const bool & wasFound)
{
	if (wasFound)
	{
		std::cout<<"Return true\n-------------------\n";
	}
	else{
		std::cout<<"Return false\n-------------------\n";
	}
}

/** hash the complements
*
*
*/
bool isKnownComplement(const std::vector<int> data, const int sum)
{
	std::unordered_set<int> complements;
	std::unordered_set<int>::iterator it;

	for(auto i : data)
	{
		// std:: containers: if you didn't get through to end, you've found it.
		if(complements.find(i) != complements.end())
		{
			std::cout<<"\nFound: current = " << i <<" at " << std::endl;
			return true;
		}
		// otherwise, if not found, insert() complement = sum-current
		complements.emplace(sum-i);
		std::cout<<"\nEmplaced sum- current "
		<< sum << " - " << i << " = " << sum-i << std::endl;
	}

	std::cout<<"\nhi";

	for(it = complements.begin(); it != complements.end(); ++it)
	{
		std::cout<< *it <<std::endl;
	}
	// fall through to return wasn't found. wasInserted() is not our bool.
	return false;
}

int main()
{
	int sum = 8;
	int input;
	bool wasFound;
	std::vector<int> v1 = {1,2,7,4,4,9,11};
	std::vector<int> v2 = {1,2};
	std::vector<int> v3 = {1,2,3,5};
	std::vector<int> v4 = {1,5,7};


	std::cout <<"\nVector v1 test : Expected true for sum = " << sum <<std::endl;

	wasFound = runTest(v1,sum);

	printStatus(wasFound);

	std::cout <<"\nVector v2 test : Expected false for sum = " << sum <<std::endl;

	wasFound = runTest(v2,sum);

	printStatus(wasFound);

	std::cout <<"\nComplements: \ninput 1, 2, 3, 5\noutput 7, 6, 5, STOP!!\n"
	<<"5 already exists in number collection. so it was found." << std::endl;

	wasFound =  isKnownComplement(v3, sum);

	printStatus(wasFound);

	std::cout <<"\nComplements: \ninput 1, 5, 7, STOP!!\n"
	<<"7 is complement of 1." << std::endl;

	wasFound =  isKnownComplement(v4, sum);

	printStatus(wasFound);

	return 0;
}
