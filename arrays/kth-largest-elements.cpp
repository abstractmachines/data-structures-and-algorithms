/*
Given an array of length n and some integer k, return the k largest values in array n.
 */

#include <algorithm>
#include <array>
#include <iostream>
#define SIZE 6

using namespace std;

int main(int argc, char ** argv)
{
  // char ** newArgv;

  std::cout<<"\nargc, " << argc <<endl <<endl;

  std::cout<<"\nargv: " <<endl;
  int idx = 0;
  for( ; idx < argc; ++idx ) {
    std::cout << argv[idx] <<endl;
    // newArgv[idx] = argv[idx];
    // std::cout << newArgv[idx] <<endl;
  }



  return 0;
}
