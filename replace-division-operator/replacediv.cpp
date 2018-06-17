#include <iostream>

/*
* @param x is dividend, y is divisor
*/
int divide(int x, int y, int count)
{
  if( (x-y) == 0 )
  {
    return ++count;
  }
  return count = divide( x-y, y, ++count);

}

int main()
{
  int result = divide(12, 3, 0);
  std::cout<<"\nResult is : " << result << std::endl;

  return 0;
}
