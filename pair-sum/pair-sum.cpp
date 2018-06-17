/* Part 1:
for any ordered collection of numbers, find a pair that sums to a
given, desired sum. Return true if found.
*/

// g++ pair-sum.cpp -std=c++11
#include <iostream>
#include <vector>

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

int main()
{
	int sum = 8;
	int input;
	bool wasFound;
	std::vector<int> v1 = {1,2,7,4,4,9,11};
	std::vector<int> v2 = {1,2};

	std::cout <<"\nVector v1 test : Expected true for sum = " << sum <<std::endl;

	wasFound = runTest(v1,sum);

	printStatus(wasFound);

	std::cout <<"\nVector v2 test : Expected false for sum = " << sum <<std::endl;

	wasFound = runTest(v2,sum);

	printStatus(wasFound);

	return 0;
}
