#include <iostream>

int xNOR(int a, int b)
{
  if(!(a ^ b))
    return 0;
  else {
    return a;
  }
}

int main()
{
  int a, b;

  std::cin >> a;
  std::cin >> b;

  int eq = xNOR(a, b);

  if(!eq) std::cout<<"\nThey're equal. XNOR.\n";

  else std::cout<<"\nNot Equal. XNOR.\n";

  return 0;
}
