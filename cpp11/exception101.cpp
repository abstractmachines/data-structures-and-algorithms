
/* Algorithms with C++ Standard Library by Amanda Falke

Compile:
$ g++ exception101.cpp -std=c++11 -o whee
Run:
$ ./whee

***** Basic Exception C++ Classes that subclass std::exception: *****

- std::runtime_error
Subclassed in turn by specific runtime exception handlers
including overflow, underflow, range_error...

- std::logic_error
Subclassed in turn by specific logical exception handlers
including length_error, invalid_argument, etc.

Type checking exception classes:
- std::bad_typeid
- std::bad_cast

... and many more.

***** What about validating argc, argv command line input? *****

We use getopt to validate and parse command line args argc, argv.

***** What about validating cin input? *****

We use getopt to validate and parse command line args argc, argv.

Rather than using exceptions for I/O validation, we use the inherent
qualities of the base class for streams.

Validating user input in C++ is done in one of several ways. It is not usually
done using exceptions. "I/O errors aren't exceptional, they are quite common."

*** istream >> operator does type checking ***
- Note that cin subclasses istream.
- The >> operator, overloaded for the istream class, reads characters that
match the specified type. It also leaves things in the buffer that it doesn't
read in!!
- std::istream::operator>>
- Use in conditional statement such as: if( !cin>>input )

*** cin.fail() ***
- Checks whether failbit (logic error on input) or badbit (bad input) are set.
- Returns true if either bits are set.
- Use in a conditional if applicable

*** cin.clear() ***
- Use cin.clear() to clear the failure bits once set, for future continued use.
- Call after you've determined a fail-state for input stream validation

*** cin.ignore(numCharsToIgnore,delimiter) ***
- Sample: ignore 10K chars until enter: std::cin.ignore(10000,'\n')
- Sample: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
- Call after cin.clear()

*** to check strings for valid input, use std::isalpha() function ***
- Create new string iterator std::string::iterator it
- #include <locale> and create a new locale object std::locale loc
- iterate over the string with a typical C++ std:: container for loop
- use the std::isalpha(*it,locale) function to determine if it's alphabetic.
- We do this because the istream >> operator's type checking
 doesn't work with std::string


See also: istringstream
OR
http://stackoverflow.com/questions/17928865/correct-way-to-use-cin-fail
Extract data directly from stream.

When you detect a numerical value,
use istringstream to convert the value (see stringstream1.cpp),
or std::stoi()  - similar to atoi().
*/

#include <iostream>
#include <locale> // std::isalpha
#include <string>

class someClass
{};

int singleFunction(void)
{
	std::cout<<"\n\nHere we just run a function where a std::runtime error "
	<< "is thrown.\n\n";

	try {
		std::cout<<"About to throw...\n";
		if(1)
		{
			throw std::runtime_error("Gak!");
		}
		std::cout<<"Back from throw?!\n";
	}
	catch (std::exception &e)
	{
		std::cout<<"Caught exception: "<<e.what()<<"\n";
	}
	return 0;
}

void eatHealthy(int numCookies, std::string flavor)
{
	try
	{
		if(numCookies > 3)
		{
			throw std::runtime_error("\n\nException thrown. You're going to get fat.");
		}
		std::cout<<"\n\nNo exception thrown. You can haz "
			<< numCookies << " " << flavor <<" cookies!\n";
	}

	catch(std::exception &e)
	{
		std::cout<<"Caught exception: " << e.what() << std::endl;
	}
}

/*
- Clear failbit / badbit cleared on cin before future use.
- Clear buffer
- TODO: this should be a polymorphic input checker.
*/
bool handleFlagsBuffer()
{
	std::cout<<"\nYou need to enter the proper data type.\n";
	std::cin.clear();
	std::cin.ignore(10000,'\n');

	return true;
}

void howManyCookies()
{
	int numCookies;
	std::string flavor;

	bool getBetterInput = true;

	while(getBetterInput == true)
	{
		std::cout<<"\n\nEnter many cookies you would like to eat!!\n";
		std::cin >> numCookies;

		if(!std::cin>>numCookies) // checks TYPE. because it's an istream >> operator!
		{
			getBetterInput = handleFlagsBuffer();
		}
		else
		{
			getBetterInput = false;
			std::cin.ignore(10000,'\n');
			std::cout<<"\n\nEnter FLAVOR of cookies you would like.\n";
			std::cin >> flavor;

			std::locale loc;
			std::string::iterator it;

			for(it = flavor.begin();
					it != flavor.end(); ++it)
			{
				if(!std::isalpha(*it,loc))
				{
					getBetterInput = handleFlagsBuffer();
				}
			}
		}
	}

	eatHealthy(numCookies,flavor);
}

int main()
{

	std::cout<<"\n\nExceptions in C++11 using the Standard Library.";

	int a = singleFunction();

	howManyCookies();

	return 0;
}
