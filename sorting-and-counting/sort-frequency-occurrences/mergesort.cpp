#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
  string s1;
  char * c1;
  vector<char *> v1;

  ifstream aFile;

  aFile.open("foggytext.txt");

  while(!aFile.eof())
  {
    aFile>>s1;

  }
  aFile.close();

  cout << s1 <<"\n\n\n"; // string,


  return 0;
}
