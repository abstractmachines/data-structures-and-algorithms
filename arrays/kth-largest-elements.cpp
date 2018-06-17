/*
Given an array of length n and some integer k, return the k largest values in array n.

My solution: take argv in, convert it to a vector of integers via atoi,
sort it in descending order, and take the kth 1st elements out of the vector.

Expected:

$ g++ -std=c++11 kth-largest-elements.cpp

$ ./a.out 66 12 2 88 89089 22 3 11 23232

The vector is now:
89089 23232 88 66 22 12 11 3 2
So how many is k? Enter a number.

3
89089 23232 88 // See, you've found the kth largest elements.
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#define SIZE 6

using namespace std;

/* Sort Descending order happens when 3rd argument is std::greater<type>:
*/
std::vector<int> sortDescend(std::vector<int> arr)
{
	std::sort(arr.begin(),arr.end(),std::greater<int>());
	return arr;
};

/* print with simplified syntax using auto C++ type deduction
*/
void printAuto(std::vector<int> arr)
{
  std::cout << "\nThe vector is now: \n";
	for(auto it:arr)
	{
		std::cout << it << " ";
	}
}

void printIterator(std::vector<int> v, int k)
{
	std::vector<int>::iterator it;
  int count = 0;

	for(it = v.begin(); it != v.end(); ++it)
	{
    if (count == k) {
      return;
    }
    else {
      std::cout << *it << " ";
    }
    ++count;
	}
}

int main(int argc, char ** argv)
{
  std::vector<int> v;
  std::vector<int> vMut; // When possible, create new data instead of mutating.
  int k;

  for(int i = 1; i<argc; ++i)
	{
		int temp = std::atoi(argv[i]);
		v.push_back(temp);
	}
  vMut = sortDescend(v);
  printAuto(vMut);

  std::cout << "\nSo how many is k? Enter a number.\n\n";
  k = getchar() - '0'; // convert ascii code to char int (range -127 to 127)

  printIterator(vMut, k);

  return 0;
}
