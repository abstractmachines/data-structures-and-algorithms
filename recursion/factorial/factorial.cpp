// #include std::vector

#include <iostream>

int returnFactorial(int n)
{
	int final = 1;

		std::cout<<"\nn is : " << n <<"\nSo next is : ";
			// << n * returnFactorial(n-1) << std::endl;

		if( n-1 != 0)
		{
			return n * returnFactorial(n-1);
		}

		return final;
}


int main()
{
	int count = 1;

	std::cout << std::endl << returnFactorial(5) << std::endl;
	return 0;
}
