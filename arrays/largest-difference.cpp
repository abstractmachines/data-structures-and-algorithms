/*
Enter integer array after ./program as args; algo finds largest difference.

Input Validation:

TIME ALLOWING: In main() after input, we'd validate input of argv using getopt.

Not doing that now for purposes of meeting time constraints.
argc = num args. argv[] = actual args:
Use case:  Compile + run:
$ g++ largest-difference.cpp -std=c++11
$ ./a.out 3 9 7 6 1 2
argv[0] is ./a.out. argv[1] is 3. argv[2] is 9. etc, etc.

Use the argv[] char * array to parse for:
- is correct data type? istream operators >> check data type,
you can also use std::isAlpha() for std::strings, and you can
also use std::typeid(varname).name() to compare data types.
Finally, std::exception is subclassed by std::bad_datatype.
- is a reasonable value? array length? you decide.
It may be ok to throw a std::exception std::runtime_error here if improper
input is entered.


*/


#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <typeinfo>

bool sortVector(std::vector<int> &v)
{
	std::sort(v.begin(),v.end());

	return true;
}

void printVector(std::vector<int> v)
{
	std::vector<int>::iterator it;

	for(it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

int subtractLargestDiff(std::vector<int> & v)
{
	int size = (int) v.size();
	std::cout<<"\n\n vector size is : " << size << " elements!\n";

	// std::cout<<"subtract: " << (v[size] - v[0]) << std::endl;

	int smol, largest;

	std::vector<int>::iterator it;
	for(it = v.begin(); it != v.end(); ++it)
	{
		if(it == v.begin())
		{
			smol = *it;
			std::cout<<"smol: " << smol <<std::endl;
		}
		else if(it == v.end()-1)
		{
			largest = *it;
			std::cout<<"largest: " << largest <<std::endl;
		}
	}

	return largest - smol;
}

int main(int argc, char * argv[])
{
	std::vector<int> v;

	// assuming input is validated (see comments above!!)

	std::cout<<"\n\nYou entered " << argc-1 << " elements.\n";

	for(int i = 1;i<argc;++i)
	{
		int temp = std::atoi(argv[i]);
		v.push_back(temp);
	}

	std::cout<<"\n\nUnsorted vector: \n";

	printVector(v);

	bool isSorted = sortVector(v);

	if( isSorted )
	{
		std::cout<<"\n\nSorted vector: \n";
		printVector(v);
		int diff = subtractLargestDiff(v);
		std::cout <<"Difference: " << diff << std::endl;
	}

	return 0;
}
