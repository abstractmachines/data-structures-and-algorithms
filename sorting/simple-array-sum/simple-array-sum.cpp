/* Algorithms with C++ by Amanda Falke

compile with C++11 : $ g++ simple-array-sum.cpp -std=c++11

*/

#include <vector>
#include <iostream>

int main() {
		std::vector<int> v;
		std::vector<int>::iterator it;
		int input;
		int count = 0;

		/* For determinism (not used here):
		int vectorSize;
		cout<<"\n\nEnter a size of the array (integer).\n\n";
		std::cin >> vectorSize;
		std::cin.clear();
		*/
		std::cout<<"\n\nEnter in array of any size.\n\n";

		std::cout<<"\n\nEnter individual numbers... then hit EOF to stop.\n\n";

		bool getBetterInput = true;

		while(getBetterInput == true)
		{
			while(std::cin >> input)
			{
				if(std::cin.fail())
				{
					std::cout<<"\n\ncin.fail() happened.\n\n";
					std::cin.clear();
					std::cin.ignore(1000,'\n');
				}
				else
				{
					v.push_back(input);
					getBetterInput = false;
				}
			}

			//Option 1: instead of using an iterator: This runs
			// for(it = v.begin(); it != v.end();++it)
			// {
			// 		count += *it;
			// }

			//Option 2: use auto: This runs. (Comment out Option 1.)
			for(auto x:v)
			{
					count += x;
			}

			// Option 3: use a std::accumulator to accumulate (3 args)



			std::cout<< count;

		}

		// if(!std::cin>>input)
		// {
		// 	std::cout<<"\n\nInvalid input.\n\n";
		// }
		// else
		// {
		// 	std::cout<<"\n\nOK, valid input.\n\n";
		// }


		return 0;
}
