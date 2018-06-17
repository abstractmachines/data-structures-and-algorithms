/*
Print an array in reverse using C++, on one line, with spaces in between.

-Sample input: edge case, one element
1
2
Sample output:
2
Passed

-Sample input:
4
1 4 3 2
Sample output:
2 3 4 1
Passed

-Sample input: edge case, no elements { empty set }
Failed (hangs)
To do: conditional/switch: std::getline, if \n\ exit failure 1, else fall thru
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseIt(int n);

int main()
{
	cout<<"\nEnter how many elements you want to reverse:\n";
	int n;
	cin >> n;

	vector<int> arr(reverseIt(n));

	return 0;
}

vector<int> reverseIt(int n)
{
	vector<int> arr(n);

	cout<<"You chose size of: " << n <<endl
		<<"Now enter the array itself like this: 1 (enter) 2 (enter)\n";

	int index = 0;

	for(;index < n;index++)
	{
		cin >> arr[index];
	}

	cout<<"\nReversed results:\n";

	index = n-1;

	for(; index>=0;--index)
	{
		cout<<arr[index];
		cout<<" ";
	}

	cout<< endl;

	return arr;
}
