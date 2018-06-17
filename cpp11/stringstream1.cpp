/* C++ Algorithms by Amanda Falke:

*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>


int main ()
{
	std::ostringstream os;

	os << "Base 10: " << 11 <<" Hex: " << std::hex << 11 <<std::endl;

	std::cout<< os.str();

	return 0;
}
